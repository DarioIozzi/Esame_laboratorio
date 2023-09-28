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

    void CreateMap(){
        for(int j = 0; j<800; j++){
            world_map[j*600] = 0;
            for(int i = 1; i<600; i++){
                world_map[j*600+i] = 0;
            }
        }
    }

    void AddTP(TerrainType* tp);

    static int getMW() {
        return MW;
    }

    static int getMH() {
        return MH;
    }

    int getCosto(int x, int y) {
        return world_map[(x*600)+y];
    }

private:
    static const int MW = 800;
    static const int MH = 600;
    int world_map[MW * MH];
    std::list<TerrainType*> TP;

};

#endif //ESAME_LABORATORIO_WORLDMAP_H
