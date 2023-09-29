//
// Created by dario on 12/08/21.
//
#include "GameCharacter.h"
void GameCharacter::moveX(float x) {
    if(pos.x + x <= WorldMap::getMW() - 10 && (pos.x + x) >= 10){
        //TODO FUNZIONE PER GESTIRE MOVIMENTO OSTACOLATO
        pos.x += x - map->getCosto(pos);;
        notify();
    }
}

void GameCharacter::moveY(float y) {
    if (pos.y + y <= WorldMap::getMH() - 10 && (pos.y + y) >= 10) {
        //TODO FUNZIONE PER GESTIRE MOVIMENTO OSTACOLATO
        pos.y += y - map->getCosto(pos);;
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