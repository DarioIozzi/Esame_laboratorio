//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_MOUNTAIN_H
#define ESAME_LABORATORIO_MOUNTAIN_H

#include "TerrainType.h"

class Mountain : public TerrainType {
public:
    Mountain(int x, int y);
    ~Mountain() override{}

    int getCosto() const override;

    int getPosX() const override{
        return posX;
    }

    int getPosY() const override{
        return posY;
    }

private:
    const int costo = 9;
    int posX;
    int posY;
};

#endif //ESAME_LABORATORIO_MOUNTAIN_H
