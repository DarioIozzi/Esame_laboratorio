//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_MUD_H
#define ESAME_LABORATORIO_MUD_H

#include "TerrainType.h"

class Mud : public TerrainType {
public:
    Mud(sf::Vector2f o);
    ~Mud() override {}

    int getWidth() const override {
        return width;
    }

    int getHeight() const override {
        return Height;
    }

    sf::Vector2f getPos() const override {
        return pos;
    }

    int getCosto() const override;

private:
    const int costo = 7;
    int width = 100;
    int Height = 100;
};

#endif //ESAME_LABORATORIO_MUD_H
