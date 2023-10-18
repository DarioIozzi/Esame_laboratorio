//
// Created by Dario on 27/09/2023.
//

#include "WorldMap.h"

void WorldMap::AddTT(TerrainType *tt) {
    TT.push_back(tt);
    int c = tt->getCosto();
    sf::Vector2f s = tt->getSize();
    sf::Vector2f p = tt->getPos();

    for(int i = p.y + 1; i < p.y + s.y; i++){
        for(int j = p.x + 1; j < p.x + s.x; j++){
            world_map[(j*MH)+i] = c;
        }
    }
}
void WorldMap::CreateMap(){
    for(int j = 0; j <= MW; j++){
        world_map[j*MH] = 0;
        for(int i = 1; i <= MH; i++){
            world_map[j*MH+i] = 0;
        }
    }
}

int WorldMap::world_map[(MW + 1) * (MH + 1)];

std::list<TerrainType*> WorldMap::TT;