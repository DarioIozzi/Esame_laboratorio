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
    GameCharacter(sf::Vector2f o);
    GameCharacter(sf::Vector2f o, WorldMap* map);
    ~GameCharacter() override = default;

    sf::Vector2f getPos() const override {
        return pos;
    }

    void moveX(float x) override;
    void moveY(float y) override;

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;

    void notify() const override;

private:
    TerrainType* mud;
    TerrainType* mountains;
    std::list<Observer*> observers;
    WorldMap* map;
};

#endif //ESAME_LABORATORIO_GAMECHARACTER_H
