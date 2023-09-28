//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_MOUNTAIN_H
#define ESAME_LABORATORIO_MOUNTAIN_H

#include "TerrainType.h"

class Mountain : public TerrainType {
public:
    Mountain(sf::Vector2f o);
    ~Mountain() override{}

    int getCosto() const override;

    int getWidth() const override {
        return width;
    }

    int getHeight() const override {
        return Height;
    }

    sf::Vector2f getPos() const override{
        return pos;
    }

private:
    const int costo = 9;
    int width = 100;
    int Height = 100;
};

#endif //ESAME_LABORATORIO_MOUNTAIN_H
