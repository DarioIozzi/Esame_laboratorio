//
// Created by Dario on 25/09/2024.
//

#include "gtest/gtest.h"
#include "../TerrainType.h"

TEST(TerrainType, Constructor){
    try {
        TerrainType t({-5, 900}, {900, -500}, 3);
    }catch(std::invalid_argument const &e){
        std::cerr << e.what() << std::endl;
    }
}
