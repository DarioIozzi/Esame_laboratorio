//
// Created by dario on 12/08/21.
//

#ifndef ESAME_LABORATORIO_GAMECHARACTER_H
#define ESAME_LABORATORIO_GAMECHARACTER_H


#include "Observer.h"
#include "Subject.h"
#include <memory>

class GameCharacter : public Subject{
public:
    explicit GameCharacter(int x = 0, int y = 0, Observer* obs = nullptr) : posX(x), posY(y)  {
        observer = obs;
    }
    ~GameCharacter() override {
        delete observer;
    };

    int getPosX() const {
        return posX;
    }

    int getPosY() const {
        return posY;
    }

    void move(int x, int y) override{
        posX += x;
        posY += y;
        notify();
    }

    void notify() const override{
        observer->update();
    }

private:
    int posX, posY;
    Observer* observer;
};

#endif //ESAME_LABORATORIO_GAMECHARACTER_H
