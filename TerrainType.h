//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_TERRAINTYPE_H
#define ESAME_LABORATORIO_TERRAINTYPE_H

#include "SFML/Graphics.hpp"

class TerrainType{
public:
    TerrainType(sf::Vector2f o) {}
    virtual ~TerrainType() {}
    virtual int getCosto() const = 0;
    virtual sf::Vector2f getSize() const = 0;
    virtual sf::Vector2f getPos() const = 0;

protected:
    sf::Vector2f pos;
};

#endif //ESAME_LABORATORIO_TERRAINTYPE_H
