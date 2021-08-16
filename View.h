//
// Created by dario on 13/08/21.
//

#ifndef ESAME_LABORATORIO_VIEW_H
#define ESAME_LABORATORIO_VIEW_H


#include "Observer.h"
#include "GameCharacter.h"
#include "Controller.h"

class View : public Observer{
public:
    View(GameCharacter* p, Controller* c) : pg(p), controller(c){}
    ~View() override{
        delete pg;
    }

    void update() override{
        int posx = pg->getPosX();
        int posy = pg->getPosY();
        display(posx, posy);
    }

    void display(int x, int y);
private:
    GameCharacter* pg;
    Controller* controller;
};


#endif //ESAME_LABORATORIO_VIEW_H
