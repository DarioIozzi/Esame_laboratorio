//
// Created by dario on 12/08/21.
//
#include "GameCharacter.h"

void GameCharacter::move(int x, int y) {

    if(abs(posX + x) <= WinWidth-80 && (posX + x) <= 0 && abs(posY +y) <= WinHeight-80 && (posY + y) <= 0  ) {
        int c = map->getCosto(abs(posX), abs(posY));
        if(c == 9)
            return;
        posX += x/c;
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