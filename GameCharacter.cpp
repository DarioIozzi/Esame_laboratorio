//
// Created by dario on 12/08/21.
//
#include "GameCharacter.h"
void GameCharacter::moveX(float x) {
    if(pos.x + x <= WorldMap::getMW() - size.x && (pos.x + x) >= 0){            //interazione terreni
        int p1 = WorldMap::getCosto(pos);
        int p2 = WorldMap::getCosto({pos.x + size.x, pos.y});
        int p3 = WorldMap::getCosto({pos.x, pos.y + size.y});
        int p4 = WorldMap::getCosto({pos.x + size.x, pos.y + size.y});

        if (p1 != 0) {
            int c = x < 0 ? p1 : -p1;
            pos.x += x + c;
        }
        else if (p3 != 0) {
            int c = x < 0 ? p3 : -p3;
            pos.x += x + c;
        }
        else if(p2 != 0) {
            int c = x < 0 ? p2 : -p2;
            pos.x += x + c;
        }
        else if(p4 != 0) {
            int c = x < 0 ? p4 : -p4;
            pos.x += x + c;
        }
        else
            pos.x += x;
        CollisionX();

        if(FP)
            PathAdjustX();
    }
    else if(pos.x + x >= WorldMap::getMW() - size.x)           //Collisione bordo mappa
        pos.x = WorldMap::getMW() - size.x;
    else
        pos.x = 0;
    notify();
}

void GameCharacter::moveY(float y) {
    if (pos.y + y <= WorldMap::getMH() - size.y && (pos.y + y) >= 0) {      //Interazione terreni
        int p1 = WorldMap::getCosto(pos);
        int p2 = WorldMap::getCosto({pos.x + size.x, pos.y});
        int p3 = WorldMap::getCosto({pos.x, pos.y + size.y});
        int p4 = WorldMap::getCosto({pos.x + size.x, pos.y + size.y});
        if (p1 != 0) {
            int c = y < 0 ? p1 : -p1;
            pos.y += y + c;
        }
        else if (p2 != 0) {
            int c = y < 0 ? p2 : -p2;
            pos.y += y + c;
        }
        else if(p3 != 0) {
            int c = y < 0 ? p3 : -p3;
            pos.y += y + c;
        }
        else if(p4 != 0) {
            int c = y < 0 ? p4 : -p4;
            pos.y += y + c;
        }
        else
            pos.y += y;
        CollisionY();

        if(FP)
            PathAdjustY();
    }
    else if(pos.y + y >= WorldMap::getMH() - size.y)           //Collisione bordo mappa
        pos.y = WorldMap::getMH() - size.y;
    else
        pos.y = 0;
    notify();
}

void GameCharacter::subscribe(Observer* o) {
    observers.push_back(o);
}

void GameCharacter::unsubscribe(Observer* o) {
    observers.remove(o);
}

void GameCharacter::notify() const {
    for(auto obs : observers){
        obs->update();
    }
}

GameCharacter::GameCharacter(sf::Vector2f o) {
    pos = o;
}

void GameCharacter::CollisionX() {
    if (WorldMap::getCosto(pos) == 9) {
        for (int j = 1; j < 11; j++) {
            if (WorldMap::getCosto({pos.x + j, pos.y}) != 9) {
                pos.x += j;
                break;
            }
        }
        return;
    }
    if (WorldMap::getCosto({pos.x, pos.y + size.y}) == 9) {
        for (int j = 1; j < 11; j++) {
            if (WorldMap::getCosto({pos.x + j, pos.y + size.y}) != 9) {
                pos.x += j;
                break;
            }
        }
        return;
    }
    if (WorldMap::getCosto({pos.x + size.x, pos.y}) == 9) {
        for (int j = 1; j < 11; j++) {
            if (WorldMap::getCosto({pos.x + size.x - j, pos.y}) != 9) {
                pos.x -= j;
                break;
            }
        }
        return;
    }
    if (WorldMap::getCosto({pos.x + size.x, pos.y + size.y}) == 9) {
        for (int j = 1; j < 11; j++) {
            if (WorldMap::getCosto({pos.x + size.x - j, pos.y + size.y}) != 9) {
                pos.x -= j;
                break;
            }
        }
        return;
    }
}

void GameCharacter::CollisionY() {
    if (WorldMap::getCosto(pos) == 9) {
        for (int i = 1; i < 11; i++) {
            if (WorldMap::getCosto({pos.x, pos.y + i}) != 9) {
                pos.y += i;
                break;
            }
        }
        return;
    }
    if (WorldMap::getCosto({pos.x + size.x, pos.y}) == 9) {
        for (int i = 1; i < 11; i++) {
            if (WorldMap::getCosto({pos.x + size.x, pos.y + i}) != 9){
                pos.y += i;
                break;
            }
        }
        return;
    }
    if (WorldMap::getCosto({pos.x, pos.y + size.y}) == 9) {
        for (int i = 1; i < 11; i++) {
            if (WorldMap::getCosto({pos.x, pos.y + size.y - i}) != 9) {
                pos.y -= i;
                break;
            }
        }
        return;
    }
    if (WorldMap::getCosto({pos.x + size.x, pos.y + size.y}) == 9) {
        for (int i = 1; i < 11; i++) {
            if (WorldMap::getCosto({pos.x + size.x, pos.y + size.y - i}) != 9) {
                pos.y -= i;
                break;
            }
        }
        return;
    }
}

void GameCharacter::findpath(sf::Vector2f d) {

    if(FP) {   //se FP = true il path è già stato cercato e trovato, quindi disattiviamo la rappresentazione su display
        FP = !FP;
        notify();
        return;
    }
        destination = d;
        AStarSearch<NodeState> astarsearch;
        NodeState NStart(pos);
        NodeState NEnd(destination);
        astarsearch.SetStartAndGoalStates(NStart, NEnd);

        unsigned int SearchState;

        do {
            SearchState = astarsearch.SearchStep();

#if DEBUG_LISTS

            cout << "Steps:" << SearchSteps << "\n";

                int len = 0;

                cout << "Open:\n";
                MapSearchNode *p = astarsearch.GetOpenListStart();
                while( p )
                {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    ((MapSearchNode *)p)->PrintNodeInfo();
#endif
                    p = astarsearch.GetOpenListNext();

                }

                cout << "Open list has " << len << " nodes\n";

                len = 0;

                cout << "Closed:\n";
                p = astarsearch.GetClosedListStart();
                while( p )
                {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    p->PrintNodeInfo();
#endif
                    p = astarsearch.GetClosedListNext();
                }

                cout << "Closed list has " << len << " nodes\n";
#endif

        } while (SearchState == AStarSearch<NodeState>::SEARCH_STATE_SEARCHING);

        if (SearchState == AStarSearch<NodeState>::SEARCH_STATE_SUCCEEDED) {

            int vertices = 10;
            path.setPrimitiveType(sf::LineStrip);
            path.resize(vertices);
            int numLine = 0;

            NodeState *node = astarsearch.GetSolutionStart();
            path[numLine].position = node->getPos();

            bool x = false;     //true se c'è movimento sull'asse x
            NodeState* prevNode = node;
            node = astarsearch.GetSolutionNext();
            if(prevNode->getPos().y == node->getPos().y) //direzione iniziale
                x = true;
            numLine++;


            for (;;) {

                prevNode = node;
                node = astarsearch.GetSolutionNext();


                if(node == nullptr)
                    break;

                //Creazione vettore di vertici per rappresentare il percorso da fare
                if(!x) {
                    if(prevNode->getPos().y == node->getPos().y)   //se cambia la direzione modifico
                        x = true;
                    if(x) {                 //se la direzione è cambiata creo un nuovo vertice
                        if (numLine < vertices) {
                            path[numLine].position = prevNode->getPos();
                            numLine++;
                        } else {
                            path.append(sf::Vertex(prevNode->getPos()));
                            numLine++;
                        }
                    }
                }
                else{
                    if(prevNode->getPos().x == node->getPos().x)    //se cambia la direzione modifico
                        x = false;
                    if(!x) {                //se la direzione è cambiata creo un nuovo vertice
                        if (numLine < vertices) {
                            path[numLine].position = prevNode->getPos();
                            numLine++;
                        }
                        else {
                            path.append(sf::Vertex(prevNode->getPos()));
                            numLine++;
                        }
                    }
                }
            }

            //Qui si aggiunge un vertice con le coordinate della destinazione
            if(numLine < vertices) {
                path[numLine].position = destination;
                numLine++;
            }else
                path.append(sf::Vertex(destination));

            //se i vertici sono minori della dimensione di default ridimensiono il vettore
            if(numLine < vertices)
                path.resize(numLine);

            astarsearch.FreeSolutionNodes();

            //se false non disegno, se true disegno
            FP = !FP;
            notify();
        } else if (SearchState == AStarSearch<NodeState>::SEARCH_STATE_FAILED) {
            cout << "Impossibile raggiungere la destinazione" << endl;

        }
        astarsearch.EnsureMemoryFreed();
}

void GameCharacter::PathAdjustX() {
    if (path[1].position == pos) {
        for (int i = 0; i < path.getVertexCount() - 1; i++)
            path[i] = path[i + 1];
        path.resize(path.getVertexCount() - 1);
        return;
    } else if (path[0].position.y == path[1].position.y) {
        path[0].position.x = pos.x;
        return;
    } else {
        FP = false;                 //modifico FP altrimenti non ricalcola il percorso ma smette di disegnarlo
        findpath(destination);
    }

}

void GameCharacter::PathAdjustY() {
    if (path[1].position == pos) {
        for (int i = 0; i < path.getVertexCount() - 1; i++)
            path[i] = path[i + 1];
        path.resize(path.getVertexCount() - 1);
        return;
    } else if (path[0].position.x == path[1].position.x) {
        path[0].position.y = pos.y;
        return;
    } else {
        FP = false;                 //modifico FP altrimenti non ricalcola il percorso ma smette di disegnarlo
        findpath(destination);
    }
}