//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_TERRAINTYPE_H
#define ESAME_LABORATORIO_TERRAINTYPE_H

class TerrainType{
public:
    TerrainType() {}
    virtual ~TerrainType() {}
    virtual int getCosto() const = 0;

    virtual int getPosX() const = 0;
    virtual int getPosY() const = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
private:
    int width;
    int Height;
};

#endif //ESAME_LABORATORIO_TERRAINTYPE_H
