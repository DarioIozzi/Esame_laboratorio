//
// Created by Dario on 16/11/2023.
//

#include "WorldMap.h"

int world_map[(MW + 1) * (MH + 1)];

std::list<TerrainType*> TTs;

void CreateMap() {
    for (int j = 0; j <= MW; j++) {
        world_map[j * MH] = normal;
        for (int i = 1; i <= MH; i++) {
            world_map[j * MH + i] = normal;
        }
    }

    CreateTT();
}

void CreateTT(){
    for(auto t : TTs) {
        for (int i = t->getPos().y + 1; i < t->getPos().y + t->getSize().y; i++) {
            for (int j = t->getPos().x + 1; j < t->getPos().x + t->getSize().x; j++) {
                world_map[(j * MH) + i] = t->getTT();
            }
        }
    }
}

int getMW() {
    return MW;
}

int getMH() {
    return MH;
}

int getMapCosto(sf::Vector2f p) {
    if (p.x < 0 || p.x > MW || p.y < 0 || p.y > MH) {
        return mountains;
    }
    int x = p.x;
    int y = p.y;
    return world_map[(x * MH) + y];
}

void addTT(TerrainType* t){
    TTs.push_back(t);
}

void removeTT(){
    TTs.clear();
}

std::list<TerrainType*>* getListPointer(){
    return &TTs;
}
