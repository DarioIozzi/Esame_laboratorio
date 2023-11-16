//
// Created by dario on 12/08/21.
//

#ifndef ESAME_LABORATORIO_GAMECHARACTER_H
#define ESAME_LABORATORIO_GAMECHARACTER_H


#include "SFML/Graphics.hpp"
#include <list>
#include "StlAStar.h"
#include "Enemy.h"
#include "Subject.h"
#include <memory>

class GameCharacter : public Subject{
public:
    GameCharacter(sf::Vector2f o);
    ~GameCharacter()  = default;

    sf::Vector2f getPos() const  {
        return pos;
    }

    void moveX(float x);
    void moveY(float y);

    void subscribe(Observer* o);
    void unsubscribe(Observer* o);

    sf::Vector2f getSize() const{
        return size;
    }

    void findpath(sf::Vector2f destination);

    void CollisionX();
    void CollisionY();

    void notify() const;

    void PathAdjust();

    bool FP = false;

    sf::VertexArray path;

private:
    std::list<Observer*> observers;
    sf::Vector2f size {20.f,20.f};
    sf::Vector2f pos;
    sf::Vector2f destination;
};

#endif //ESAME_LABORATORIO_GAMECHARACTER_H
