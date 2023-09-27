//
// Created by dario on 12/08/21.
//
#include "GameCharacter.h"

void GameCharacter::move(int x, int y) {

    if(abs(posX + x) <= WorldMap::getMW()-80 && (posX + x) <= 0 && abs(posY +y) <= WorldMap::getMH()-80 && (posY + y) <= 0  ) {
        int c = map->getCosto(abs(posX), abs(posY));
        if(c == 9)
            return;      //TODO AGGIUNGERE DIMENSIONE PERSONAGGIO PER MOV OSTACOLATO
        posX += x/c;     //TODO MODIFICARE PER OTTERENERE COSTO PROSSIMA CASELLA
        posY += y/c;
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

GameCharacter::GameCharacter(int x, int y, int WW, int WH, WorldMap* map) : posX(x), posY(y), WinWidth(WW), WinHeight(WH), map(map) {
}

GameCharacter::GameCharacter(int x, int y) : posX(x), posY(y){
}