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

    for (int i = mudPos.y + 1; i < mudPos.y + mudSize.y; i++) {
        for (int j = mudPos.x + 1; j < mudPos.x + mudSize.x; j++) {
            world_map[(j * MH) + i] = TerrainType::mud;
        }
    }

    for (int i = mountainPos.y + 1; i < mountainPos.y + mountainSize.y; i++) {
        for (int j = mountainPos.x + 1; j < mountainPos.x + mountainSize.x; j++) {
            world_map[(j * MH) + i] = TerrainType::mountains;
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