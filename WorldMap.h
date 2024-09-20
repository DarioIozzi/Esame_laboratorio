//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_WORLDMAP_H
#define ESAME_LABORATORIO_WORLDMAP_H

#include "SFML/Graphics.hpp"
#include <list>
#include "TerrainType.h"

    enum terrtype{
        normal = 0,
        mud = 6,
        mountains = 9
    };

    const int MW = 800;
    const int MH = 600;

    void CreateMap();

    void CreateTT();

    int getMW();

    int getMH();

    int getMapCosto(sf::Vector2f p);

    void addTT(TerrainType* t);

    std::list<TerrainType*>* getListPointer();

#endif //ESAME_LABORATORIO_WORLDMAP_H