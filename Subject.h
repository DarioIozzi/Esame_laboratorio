//
// Created by dario on 13/08/21.
//

#ifndef ESAME_LABORATORIO_SUBJECT_H
#define ESAME_LABORATORIO_SUBJECT_H

#include "SFML/Graphics.hpp"
#include <list>

class Subject {
public:
    Subject() {}
    virtual ~Subject() {}

    virtual sf::Vector2f getPos() const = 0;
    virtual void moveX(float x) = 0;
    virtual void moveY(float y) = 0;
    virtual void notify() const = 0;
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;

protected:
    sf::Vector2f pos;
};


#endif //ESAME_LABORATORIO_SUBJECT_H
