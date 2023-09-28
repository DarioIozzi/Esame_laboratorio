//
// Created by Dario on 26/09/2023.
//

#include "Mountain.h"

Mountain::Mountain(sf::Vector2f o) {
    pos = o;
}

int Mountain::getCosto() const {
    return costo;
}