//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_TERRAINTYPE_H
#define ESAME_LABORATORIO_TERRAINTYPE_H

class TerrainType{
public:
    TerrainType() {}
    virtual ~TerrainType() {}
    virtual int getCosto() = 0;
};

#endif //ESAME_LABORATORIO_TERRAINTYPE_H
