//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_MUD_H
#define ESAME_LABORATORIO_MUD_H

#include "TerrainType.h"

class Mud : public TerrainType {
public:
    Mud(int x, int y);
    ~Mud() override {}

    int getPosX() const override {
        return posX;
    }

    int getPosY() const override {
        return posY;
    }

    int getWidth() const override {
        return width;
    }

    int getHeight() const override {
        return Height;
    }

    int getCosto() const override;

private:
    const int costo = 5;
    int posX;
    int posY;
    int width = 100;
    int Height = 100;
};

#endif //ESAME_LABORATORIO_MUD_H
