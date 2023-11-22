//
// Created by Dario on 16/11/2023.
//

#include "WorldMap.h"

int world_map[(MW + 1) * (MH + 1)];

void CreateMap() {
    for (int j = 0; j <= MW; j++) {
        world_map[j * MH] = 0;
        for (int i = 1; i <= MH; i++) {
            world_map[j * MH + i] = normal;
        }
    }

    CreateTT(mudSize, mudPos, mud);

    CreateTT(mountainSize, mountainPos, mountains);
}

void CreateTT(sf::Vector2f size, sf::Vector2f pos, TerrainType tt){
    for (int i = pos.y + 1; i < pos.y + size.y; i++) {
        for (int j = pos.x + 1; j < pos.x + size.x; j++) {
            world_map[(j * MH) + i] = tt;
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
        return 9;
    }
    int x = p.x;
    int y = p.y;
    return world_map[(x * MH) + y];
}