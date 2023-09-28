//
// Created by Dario on 26/09/2023.
//

#include "Mud.h"

Mud::Mud(sf::Vector2f o) {
    pos = o;
}

int Mud::getCosto() const {
    return costo;
}