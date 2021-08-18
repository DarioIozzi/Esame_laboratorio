//
// Created by dario on 13/08/21.
//

#include "Controller.h"


GameEvent Controller::getEvent() {
    char c;
    while(std::cin.get(c)){
        std::cin.ignore(100, '\n');
        switch (c){
            case 'Q':
                return GameEvent::quit;
            case 'w':
                return GameEvent::up;
            case 'a':
                return GameEvent::left;
            case 's':
                return GameEvent::down;
            case 'd':
                return GameEvent::right;
            default:
                return GameEvent::noop;
        }
    }
    return GameEvent::noop;
}

bool Controller::update(const GameEvent &event) {
    {
        switch(event){
            case GameEvent::up: {
                pg->move(0, 1);
                break;
            }
            case GameEvent::right: {
                pg->move(1, 0);
                break;
            }
            case GameEvent::down: {
                pg->move(0, -1);
                break;
            }
            case GameEvent::left: {
                pg->move(-1, 0);
                break;
            }
            case GameEvent::quit: {
                return true;
            }
            case GameEvent::noop: {
                break;
            }
        }
        return false;
    }
}

Controller::Controller() {
    pg = new GameCharacter;
    map = new MapView(pg);
}
