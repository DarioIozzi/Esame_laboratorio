//
// Created by dario on 12/08/21.
//

#include "GameCharacter.h"

void GameCharacter::move(int x, int y) {
    posX += x;
    posY += y;
    notify();
}
