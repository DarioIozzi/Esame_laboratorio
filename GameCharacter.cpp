//
// Created by dario on 12/08/21.
//
#include "GameCharacter.h"
void GameCharacter::moveX(float x) {
    if(pos.x + x <= WorldMap::getMW() - size.x && (pos.x + x) >= 0){
        float p1 = map->getCosto(pos);
        float p2 = map->getCosto({pos.x + size.x, pos.y});
        float p3 = map->getCosto({pos.x, pos.y + size.y});
        float p4 = map->getCosto({pos.x + size.x, pos.y + size.y});

        if (p1 != 0) {
            float c = x < 0 ? p1 : -p1;
            pos.x += x + c;
        }
        else if (p3 != 0) {
            float c = x < 0 ? p3 : -p3;
            pos.x += x + c;
        }
        else if(p2 != 0) {
            float c = x < 0 ? p2 : -p2;
            pos.x += x + c;
        }
        else if(p4 != 0) {
            float c = x < 0 ? p4 : -p4;
            pos.x += x + c;
        }
        else
            pos.x += x;
        CollisionX(x);
        notify();
    }
}

void GameCharacter::moveY(float y) {
    if (pos.y + y <= WorldMap::getMH() - size.y && (pos.y + y) >= 0) {
        float p1 = map->getCosto(pos);
        float p2 = map->getCosto({pos.x + size.x, pos.y});
        float p3 = map->getCosto({pos.x, pos.y + size.y});
        float p4 = map->getCosto({pos.x + size.x, pos.y + size.y});
        if (p1 != 0) {
            float c = y < 0 ? p1 : -p1;
            pos.y += y + c;
        }
        else if (p2 != 0) {
            float c = y < 0 ? p2 : -p2;
            pos.y += y + c;
        }
        else if(p3 != 0) {
            float c = y < 0 ? p3 : -p3;
            pos.y += y + c;
        }
        else if(p4 != 0) {
            float c = y < 0 ? p4 : -p4;
            pos.y += y + c;
        }
        else
            pos.y += y;
        CollisionY(y);
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

void GameCharacter::CollisionX(float x) {

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

void GameCharacter::CollisionY(float y) {
    float p1 = map->getCosto(pos);
    float p2 = map->getCosto({pos.x + size.x, pos.y});
    float p3 = map->getCosto({pos.x, pos.y + size.y});
    float p4 = map->getCosto({pos.x + size.x, pos.y + size.y});

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