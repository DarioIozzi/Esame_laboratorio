//
// Created by Dario on 25/09/2024.
//

#include "gtest/gtest.h"
#include "../TerrainType.h"

TEST(TerrainType, Constructor){
    TerrainType t({-5, 900}, {900, -500}, 3);
    ASSERT_EQ(10, t.getSize().x);
    ASSERT_EQ(10, t.getSize().y);
    ASSERT_EQ(100, t.getPos().x);
    ASSERT_EQ(100, t.getPos().y);
    ASSERT_EQ(0, t.getTT());
}
