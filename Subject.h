//
// Created by Dario on 16/11/2023.
//

#ifndef ESAME_LABORATORIO_SUBJECT_H
#define ESAME_LABORATORIO_SUBJECT_H

#include "SFML/Graphics.hpp"
#include "Observer.h"

class Subject {
public:
    Subject() {}
    virtual ~Subject() {}

    virtual void notify() const = 0;
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
};

#endif //ESAME_LABORATORIO_SUBJECT_H
