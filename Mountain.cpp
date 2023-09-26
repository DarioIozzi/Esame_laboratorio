//
// Created by Dario on 26/09/2023.
//

#include "Mountain.h"

Mountain::Mountain(int x, int y) : posX(x), posY(y) {}

int Mountain::getCosto() const {
    return costo;
}