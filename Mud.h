//
// Created by Dario on 26/09/2023.
//

#ifndef ESAME_LABORATORIO_MUD_H
#define ESAME_LABORATORIO_MUD_H

#include "TerrainType.h"

class Mud : public TerrainType {
public:
    Mud(int x, int y);
    ~Mud() override {}

    int getCosto() override;

private:
    int costo;
    int posx;
    int posy;
};

#endif //ESAME_LABORATORIO_MUD_H
