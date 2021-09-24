//
// Created by dario on 12/08/21.
//

#include "GameCharacter.h"

void GameCharacter::move(int x, int y) {
    if(abs(posX + x) < MAP_WIDTH && abs(posY +y) < MAP_HEIGHT) {
        posX += x;
        posY += y;
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

GameCharacter::GameCharacter(int x, int y) : posX(x), posY(y) {
}