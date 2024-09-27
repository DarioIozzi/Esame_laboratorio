//
// Created by Dario on 25/09/2024.
//
#include "gtest/gtest.h"
#include "../Controller.h"

class GameCharacterSuite : public::testing::Test{

protected:
    virtual void SetUp() {
    }

    GameCharacter pg;
};

TEST_F(GameCharacterSuite, ObserverTest){
    Enemy e({0, 0});
    sf::RenderWindow window(sf::VideoMode(800, 600), "ObsTest");
    MapView m(&pg, &e, &window);
    pg.subscribe(&m);
    ASSERT_EQ(2, pg.numObservers());
    pg.unsubscribe(&m);
    ASSERT_EQ(0, pg.numObservers());
}

TEST_F(GameCharacterSuite, FindImpossiblePathTest){
    sf::RenderWindow window(sf::VideoMode(800, 600), "FindpathTest");
    TerrainType Mountain1({391, 70}, {0, 50}, mountains);
    TerrainType Mountain2({390, 70}, {410, 50}, mountains);
    addTT(&Mountain1);
    addTT(&Mountain2);
    Controller game(&window);
    while(window.isOpen()){
    sf::Event event{};
    pg.findpath({600, 500});
    window.close();
    }
    ASSERT_EQ(false, pg.FP);
}

