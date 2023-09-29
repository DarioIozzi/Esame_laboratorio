//
// Created by dario on 13/08/21.
//

#ifndef ESAME_LABORATORIO_CONTROLLER_H
#define ESAME_LABORATORIO_CONTROLLER_H


#include <iostream>
#include "MapView.h"
#include "Mud.h"
#include "Mountain.h"

class Controller {
public:
    explicit Controller(sf::RenderWindow* window);
    ~Controller() {}

    void Commands();

private:
    GameCharacter* pg;
    Enemy* enemy;
    MapView* DrawMap;
    Mud* mud;
    Mountain* mountains;
    WorldMap* map;
};


#endif //ESAME_LABORATORIO_CONTROLLER_H
