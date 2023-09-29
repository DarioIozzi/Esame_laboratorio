//
// Created by Dario on 27/09/2023.
//

#include "WorldMap.h"

void WorldMap::AddTP(TerrainType *tp) {
    TP.push_back(tp);
    sf::Vector2f p = tp->getPos();
    for(int i = p.y + 1; i < p.y + tp->getSize().y; i++){
        for(int j = p.x + 1; j < p.x + tp->getSize().x; j++){
            world_map[(j*600)+i] = tp->getCosto();
        }
    }
}