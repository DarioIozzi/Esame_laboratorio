//
// Created by dario on 12/08/21.
//
#include "GameCharacter.h"
void GameCharacter::moveX(float x) {
    if(pos.x + x <= WorldMap::getMW()-80 && (pos.x + x) <= 0){
        int c = map->getCosto(pos);
        if(x < 0) {    //DESTRA
            for (int j = 0; j < 10 - c; j++) {
            if (map->getCosto({pos.x - j - 80, pos.y}) == 9) {
                pos.x -= j;
                notify();
                return;
            }
        }
        if(map->getCosto({pos.x - 80, pos.y}) != 0){
            pos.x += x + map->getCosto({pos.x- 80, pos.y});notify();
            return;
        }
        pos.x += x + c;             //TODO AGGIUSTARE
        notify();
    }
        else{       //SINISTRA
        for (int j = 0; j < 10 - c; j++) {
            if (map->getCosto({pos.x + j + 1, pos.y}) == 9) {
                pos.x += j;
                notify();
                return;
            }
        }
        if(map->getCosto({pos.x - 80, pos.y}) != 0){
            pos.x += x - map->getCosto({pos.x- 80, pos.y});
            notify();
            return;
        }
        pos.x += x - c;
        notify();
    }
}
}

void GameCharacter::moveY(float y) {
    if(pos.y +y <= WorldMap::getMH()-80 && (pos.y + y) <= 0){
        int c = map->getCosto(pos);
        if(pos.y < 0) {   //BASSO
            for (int i = 0; i < 10 - c; i++) {
                if (map->getCosto({pos.x, pos.y - i - 80})) {
                    pos.y -= i;
                    notify();
                    return;
                }
            }
            if(map->getCosto({pos.x, pos.y- 80}) != 0){
                pos.y += y + map->getCosto({pos.x, pos.y - 80});
                notify();
                return;
            }
            pos.y += y + c;
            notify();
        }
        else{    //ALTO
            for (int i = 0; i < 10 - c; i++) {
                if (map->getCosto({pos.x, pos.y + i + 1}) == 9) {
                    pos.y += i;
                    notify();
                    return;
                }
            }
            if(map->getCosto({pos.x, pos.y - 80}) !=0){
                pos.y += y - map->getCosto({pos.x, pos.y - 80});
                notify();
                return;
            }
            pos.y += y - c;
            notify();
        }
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

GameCharacter::GameCharacter(sf::Vector2f o) {
    pos = o;
}