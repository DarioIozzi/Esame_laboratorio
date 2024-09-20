#include "gtest/gtest.h"
#include "../Controller.h"

TEST(GameCharacter, FindpathTest){
    sf::RenderWindow window(sf::VideoMode(800, 600), "FindpathTest");
    TerrainType Mountain1({391, 70}, {0, 280}, mountains);
    TerrainType Mountain2({390, 70}, {410, 280}, mountains);
    addTT(&Mountain1);
    addTT(&Mountain2);
    Controller game(&window);
    while(window.isOpen()){
        sf::Event event{};
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                game.Commands();
        }
    }
}

TEST(GameCharacter, Constructor){
    GameCharacter pg({-5,10});
    cout<<"Coordinate pg: "<< pg.getPos().x << " " << pg.getPos().y;
}