//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_WORLDMAP_H
#define ESAME_LABORATORIO_WORLDMAP_H

#endif //ESAME_LABORATORIO_WORLDMAP_H

class WorldMap{
public:

    WorldMap() {}
    ~WorldMap() {}

    void CreateMap(){
        for(int i = 0; i<800; i++){
            world_map[i*600] = 1;
            for(int j = 1; j<600; j++){
                world_map[i*600+j] = 1;
            }
        }
    }

    int getCosto(int x, int y) {
        return world_map[(y*600)+x];
    }

private:
    static const int MW = 800;
    static const int MH = 600;
    int world_map[MW * MH];
};