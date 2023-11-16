//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_WORLDMAP_H
#define ESAME_LABORATORIO_WORLDMAP_H

#include "SFML/Graphics.hpp"

    enum TerrainType{
        normal = 0,
        mud = 6,
        mountains = 9
    };

    const int MW = 800;
    const int MH = 600;

    //dimensione e posizione di mud
    const sf::Vector2f mudSize = {100, 100};
    const sf::Vector2f mudPos = {300, 150};

    //dimensione e posizione di mountains
    const sf::Vector2f mountainSize = {100, 100};
    const sf::Vector2f mountainPos = {300, 400};

    void CreateMap();

    int getMW();

    int getMH();

    int getMapCosto(sf::Vector2f p);

#endif //ESAME_LABORATORIO_WORLDMAP_H