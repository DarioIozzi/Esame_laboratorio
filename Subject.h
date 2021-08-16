//
// Created by dario on 13/08/21.
//

#ifndef ESAME_LABORATORIO_SUBJECT_H
#define ESAME_LABORATORIO_SUBJECT_H


class Subject {
public:
    Subject() {}
    virtual ~Subject() {}

    virtual void move(int x, int y) = 0;
    virtual void notify() const = 0;
};


#endif //ESAME_LABORATORIO_SUBJECT_H
