//
// Created by Dario on 27/09/2023.
//

#include "WorldMap.h"

void WorldMap::AddTP(TerrainType *tp) {
    TP.push_back(tp);
    sf::Vector2f p = tp->getPos();
    for(int i = p.y - tp->getSize().y/2; i < p.y + tp->getSize().y/2; i++){
        for(int j = p.y - tp->getSize().x/2; j < p.y + tp->getSize().x/2; j++){
            world_map[(j*600)+i] = tp->getCosto();
        }
    }
}