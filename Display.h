//
// Created by dario on 16/08/21.
//

#ifndef ESAME_LABORATORIO_DISPLAY_H
#define ESAME_LABORATORIO_DISPLAY_H


class Display {
public:
    Display() {}
    ~Display() {}

    virtual void Draw(int posx, int posy) = 0;
};


#endif //ESAME_LABORATORIO_DISPLAY_H
