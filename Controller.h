//
// Created by dario on 13/08/21.
//

#ifndef ESAME_LABORATORIO_CONTROLLER_H
#define ESAME_LABORATORIO_CONTROLLER_H


#include <iostream>
#include "GameCharacter.h"
#include "MapView.h"

class Controller {
public:
    explicit Controller(sf::RenderWindow* window);
    ~Controller() {    }

    void Commands();

private:
    GameCharacter* pg;
    GameCharacter* enemy;
    MapView* map;
};


#endif //ESAME_LABORATORIO_CONTROLLER_H
