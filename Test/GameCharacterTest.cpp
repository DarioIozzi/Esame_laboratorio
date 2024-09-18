#include "gtest/gtest.h"
#include "../GameCharacter.h"
#include "../Controller.h"

TEST(GameCharacter, FindpathTest){
    sf::RenderWindow window(sf::VideoMode(800, 600), "FindpathTest");
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