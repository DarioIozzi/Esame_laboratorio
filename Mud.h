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

    sf::Vector2f getSize() const override {
        return size;
    }

    sf::Vector2f getPos() const override {
        return pos;
    }

    int getCosto() const override;

private:
    const int costo = 6;
    sf::Vector2f size {100.f, 100.f};
};

#endif //ESAME_LABORATORIO_MUD_H
