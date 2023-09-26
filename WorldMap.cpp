//
// Created by Dario on 26/09/2023.
//
#include "WorldMap.h"

WorldMap::WorldMap(int WW, int WH) : WW(WW), WH(WH){
    for(int i = 0; i<800; i++){
        world_map[0,i] = 2;
        for(int j = 1; j<600; j++){
            world_map[j,i] = 2;
        }
    }
}
