//
// Created by dario on 12/08/21.
//

#ifndef ESAME_LABORATORIO_GAMECHARACTER_H
#define ESAME_LABORATORIO_GAMECHARACTER_H


#include <SFML/Graphics.hpp>
#include "StlAStar.h"
#include "Enemy.h"
#include "Subject.h"

class GameCharacter : public Subject{
public:
    explicit GameCharacter(sf::Vector2f o, sf::Vector2f s = {20,20});
    ~GameCharacter() {}

    sf::Vector2f getPos() const{
        return pos;
    }

    void moveX(float x);
    void moveY(float y);

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;

    void notify() const override;

    sf::Vector2f getSize() const{
        return size;
    }

    void findpath(sf::Vector2f destination);

    void CollisionX();
    void CollisionY();

    void PathAdjust();

    bool FP = false;

    sf::VertexArray path;

    sf::RectangleShape pgShape;

private:
    std::list<Observer*> observers;
    sf::Vector2f size;
    sf::Vector2f pos;
    sf::Vector2f destination;
};

#endif //ESAME_LABORATORIO_GAMECHARACTER_H
