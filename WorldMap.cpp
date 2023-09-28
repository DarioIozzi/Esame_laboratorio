//
// Created by Dario on 27/09/2023.
//

#include "WorldMap.h"

void WorldMap::AddTP(TerrainType *tp) {
    TP.push_back(tp);
    sf::Vector2f p = tp->getPos();
    for(int i = p.y; i < p.y + tp->getHeight(); i++){
        for(int j = p.y; j < p.y + tp->getWidth(); j++){
            world_map[(j*600)+i] = tp->getCosto();
        }
    }
}