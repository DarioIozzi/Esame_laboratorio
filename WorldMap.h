//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_WORLDMAP_H
#define ESAME_LABORATORIO_WORLDMAP_H

#include "TerrainType.h"
#include <cmath>
#include <list>

class WorldMap{
public:

    WorldMap() {}
    ~WorldMap() {}

    static void CreateMap();

    static void AddTP(TerrainType* tp);

    static int getMW() {
        return MW;
    }

    static int getMH() {
        return MH;
    }

    static int getCosto(sf::Vector2f p) {
        if(p.x < 0 || p.x > MW || p.y < 0 || p.y > MH){
            return 9;
        }
        int x = p.x;
        int y = p.y;
        return world_map[(x*MH)+y];
    }

private:
    static const int MW = 800;
    static const int MH = 600;
    static int world_map[(MW + 1) * (MH + 1)];
    static std::list<TerrainType*> TP;

};

#endif //ESAME_LABORATORIO_WORLDMAP_H
