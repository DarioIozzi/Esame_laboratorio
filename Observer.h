//
// Created by dario on 12/08/21.
//

#ifndef ESAME_LABORATORIO_OBSERVER_H
#define ESAME_LABORATORIO_OBSERVER_H


class Observer {
public:
    Observer(){}
    virtual ~Observer() {}

    virtual void update() = 0;
};


#endif //ESAME_LABORATORIO_OBSERVER_H
