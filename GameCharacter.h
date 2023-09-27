//
// Created by dario on 12/08/21.
//

#ifndef ESAME_LABORATORIO_GAMECHARACTER_H
#define ESAME_LABORATORIO_GAMECHARACTER_H


#include "Observer.h"
#include "Subject.h"
#include "TerrainType.h"
#include "cmath"
#include "WorldMap.h"
#include <memory>
#include <list>

class GameCharacter : public Subject{
public:
    GameCharacter(int x, int y);
    GameCharacter(int x, int y, int WW, int WH, WorldMap* map);
    ~GameCharacter() override = default;

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
    int WinWidth, WinHeight;
    TerrainType* mud;
    TerrainType* mountains;
    std::list<Observer*> observers;
    WorldMap* map;
};

#endif //ESAME_LABORATORIO_GAMECHARACTER_H
