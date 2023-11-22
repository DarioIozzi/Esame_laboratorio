#include "gtest/gtest.h"
#include "../GameCharacter.h"
#include "../Controller.h"
#include <SFML/Graphics.hpp>

TEST(GameCharacter, FindpathTest){
    sf::RenderWindow window(sf::VideoMode(800, 600), "pathTest");
    Controller game(&window);
    CreateTT({800, 70}, {0, 280}, mud);
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