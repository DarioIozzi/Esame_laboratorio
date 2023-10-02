//
// Created by dario on 12/08/21.
//
#include "GameCharacter.h"
void GameCharacter::moveX(float x) {
    if(pos.x + x <= WorldMap::getMW() - size.x && (pos.x + x) >= 0){
        int p1 = map->getCosto(pos);
        int p2 = map->getCosto({pos.x + size.x, pos.y});
        int p3 = map->getCosto({pos.x, pos.y + size.y});
        int p4 = map->getCosto({pos.x + size.x, pos.y + size.y});

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
        notify();
    }
}

void GameCharacter::moveY(float y) {
    if (pos.y + y <= WorldMap::getMH() - size.y && (pos.y + y) >= 0) {
        int p1 = map->getCosto(pos);
        int p2 = map->getCosto({pos.x + size.x, pos.y});
        int p3 = map->getCosto({pos.x, pos.y + size.y});
        int p4 = map->getCosto({pos.x + size.x, pos.y + size.y});
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
        notify();
    }
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

GameCharacter::GameCharacter(sf::Vector2f o, WorldMap* map) : map(map){
    pos = o;
}

void GameCharacter::CollisionX() {
    if (map->getCosto(pos) == 9) {
        for (int j = 1; j < 11; j++) {
            if (map->getCosto({pos.x + j, pos.y}) != 9) {
                pos.x += j;
                return;
            }
        }
    }
    if (map->getCosto({pos.x, pos.y + size.y}) == 9) {
        for (int j = 1; j < 11; j++) {
            if (map->getCosto({pos.x + j, pos.y + size.y}) != 9) {
                pos.x += j;
                return;
            }
        }
    }

    if (map->getCosto({pos.x + size.x, pos.y}) == 9) {
        for (int j = 1; j < 11; j++) {
            if (map->getCosto({pos.x + size.x - j, pos.y}) != 9) {
                pos.x -= j;
                return;
            }
        }
    }
    if (map->getCosto({pos.x + size.x, pos.y + size.y}) == 9) {
        for (int j = 1; j < 11; j++) {
            if (map->getCosto({pos.x + size.x - j, pos.y + size.y}) != 9) {
                pos.x -= j;
                return;
            }
        }
    }
}

void GameCharacter::CollisionY() {
    if (map->getCosto(pos) == 9) {
        for (int i = 1; i < 11; i++) {
            if (map->getCosto({pos.x, pos.y + i}) != 9) {
                pos.y += i;
                return;
            }
        }
    }
    if (map->getCosto({pos.x + size.x, pos.y}) == 9) {
        for (int i = 1; i < 11; i++) {
            if (map->getCosto({pos.x + size.x, pos.y + i}) != 9) {
                pos.y += i;
                return;
            }
        }
    }
    if (map->getCosto({pos.x, pos.y + size.y}) == 9) {
        for (int i = 1; i < 11; i++) {
            if (map->getCosto({pos.x, pos.y + size.y - i}) != 9) {
                pos.y -= i;
                return;
            }
        }
    }
    if (map->getCosto({pos.x + size.x, pos.y + size.y}) == 9) {
        for (int i = 1; i < 11; i++) {
            if (map->getCosto({pos.x + size.x, pos.y + size.y - i}) != 9) {
                pos.y -= i;
                return;
            }
        }
    }
}

void GameCharacter::findpath(sf::Vector2f destination) {
    AStarSearch<NodeState> astarsearch;
    NodeState NStart(pos);
    NodeState NEnd(static_cast<sf::Vector2f>(destination));
    astarsearch.SetStartAndGoalStates( NStart, NEnd );

    unsigned int SearchCount = 0;
    unsigned int SearchState;

    do{
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

    }
    while( SearchState == AStarSearch<NodeState>::SEARCH_STATE_SEARCHING );

    if( SearchState == AStarSearch<NodeState>::SEARCH_STATE_SUCCEEDED ){

        //TODO DISEGNA IL PERCORSO

        astarsearch.FreeSolutionNodes();
    }
    else if( SearchState == AStarSearch<NodeState>::SEARCH_STATE_FAILED ){
        cout << "Impossibile raggiungere la destinazione" <<endl;

    }
    astarsearch.EnsureMemoryFreed();
}