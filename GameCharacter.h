//
// Created by dario on 12/08/21.
//

#ifndef ESAME_LABORATORIO_GAMECHARACTER_H
#define ESAME_LABORATORIO_GAMECHARACTER_H


#include "Observer.h"
#include "Subject.h"
#include "Findpath.cpp"
#include <memory>
#include <list>

class GameCharacter : public Subject{
public:
    GameCharacter(int x, int y);
    ~GameCharacter() override {}

    int getPosX() const {
        return posX;
    }

    int getPosY() const {
        return posY;
    }

    void move(int x, int y) override;

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;

    void notify() const override;

private:
    int posX, posY;
    std::list<Observer*> observers;
};

#endif //ESAME_LABORATORIO_GAMECHARACTER_H
