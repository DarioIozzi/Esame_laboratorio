//
// Created by Dario on 27/09/2023.
//

#include "WorldMap.h"

void WorldMap::AddTP(TerrainType *tp) {
    TP.push_back(tp);
    int x = abs(tp->getPosX());
    int y = abs(tp->getPosY());
    for(int i = y; i < y + tp->getHeight(); i++){
        for(int j = x; j < x + tp->getWidth(); j++){
            world_map[(j*600)+i] = tp->getCosto();
        }
    }
}