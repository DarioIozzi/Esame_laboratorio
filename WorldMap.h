//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_WORLDMAP_H
#define ESAME_LABORATORIO_WORLDMAP_H

#endif //ESAME_LABORATORIO_WORLDMAP_H

class WorldMap{
public:
    WorldMap(int WW, int WH);

    int getCosto() const {
        return costo;
    }

private:
    int costo;
    int WW, WH;
    int world_map[ WW * WH ]; //TODO WORLD MAP. TUTTO IN MAIN?
};