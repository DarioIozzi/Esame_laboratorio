//
// Created by dario on 13/08/21.
//

#include "Controller.h"
#include <SFML/Graphics.hpp>

void Controller::Commands() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        pg->move(1, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        pg->move(-1, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        pg->move(0, 1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        pg->move(0, -1);
}

Controller::Controller(sf::RenderWindow* w) {
    pg = new GameCharacter(0, 0);
    enemy = new GameCharacter(10, 15);
    map = new MapView(pg, enemy, w);
}
