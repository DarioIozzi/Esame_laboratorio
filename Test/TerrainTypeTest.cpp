//
// Created by Dario on 25/09/2024.
//

#include "gtest/gtest.h"
#include "../TerrainType.h"

TEST(TerrainType, Constructor){
    EXPECT_THROW(TerrainType t({-5, 900}, {900, -500}, 3), std::invalid_argument);
}
