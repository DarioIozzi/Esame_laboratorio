#include "gtest/gtest.h"
#include "../GameCharacter.h"
#include "../Controller.h"

TEST(GameCharacter, FindpathTest){
    sf::RenderWindow window(sf::VideoMode(800, 600), "FindpathTest");
    Controller game(&window);
    CreateTT({391, 70}, {0, 280}, mountains);
    CreateTT({390, 70}, {410, 280}, mountains);
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