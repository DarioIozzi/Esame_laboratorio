//
// Created by dario on 13/08/21.
//

#ifndef ESAME_LABORATORIO_CONTROLLER_H
#define ESAME_LABORATORIO_CONTROLLER_H


#include <iostream>
#include "GameCharacter.h"
#include "MapView.h"

enum class GameEvent{
    quit, left, up, right, down, noop
};

class Controller {
public:
    explicit Controller();
    ~Controller() {
        delete pg;
    }

    GameEvent getEvent() const;
    bool update(const GameEvent& event);

private:
    GameCharacter* pg;
    MapView* map;
};


#endif //ESAME_LABORATORIO_CONTROLLER_H
