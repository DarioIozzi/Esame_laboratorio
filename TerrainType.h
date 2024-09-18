//
// Created by Dario on 18/09/2024.
//

#ifndef ESAME_LABORATORIO_TERRAINTYPE_H
#define ESAME_LABORATORIO_TERRAINTYPE_H

#include "SFML/Graphics.hpp"


class TerrainType {

public:
    TerrainType(sf::Vector2f s, sf::Vector2f p, int t){
        Size = s;
        Pos = p;
        tt = t;
        TerrainShape.setSize(s);
        TerrainShape.setOrigin(0.f, 0.f);
        TerrainShape.setPosition(p);
        if(t == 6)
            TerrainShape.setFillColor(sf::Color::Cyan);
        else
            TerrainShape.setFillColor(sf::Color::White);
    }

    sf::Vector2f getSize() const{
        return Size;
    }

    sf::Vector2f getPos() const{
        return Pos;
    }

    int getTT() const{
        return tt;
    }

    sf::RectangleShape TerrainShape;

private:
    sf::Vector2f Size;
    sf::Vector2f Pos;
    int tt;
};


#endif //ESAME_LABORATORIO_TERRAINTYPE_H
