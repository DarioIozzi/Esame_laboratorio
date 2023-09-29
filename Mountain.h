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

    sf::Vector2f getSize() const override{
        return size;
    }

    sf::Vector2f getPos() const override{
        return pos;
    }

private:
    const int costo = 9;
    sf::Vector2f size {100.f, 100.f};
};

#endif //ESAME_LABORATORIO_MOUNTAIN_H
