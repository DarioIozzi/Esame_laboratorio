#include "gtest/gtest.h"
#include "../Controller.h"

TEST(GameCharacter, Constructor){
    GameCharacter pg({-5,10});
    ASSERT_EQ(0, pg.getPos().x);
    ASSERT_EQ(0, pg.getPos().y);
}

TEST(GameCharacter, Movement){
    GameCharacter pg;
    pg.moveX(10);
    pg.moveY(5);
    ASSERT_EQ(10, pg.getPos().x);
    ASSERT_EQ(5, pg.getPos().y);
}