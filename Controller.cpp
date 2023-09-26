//
// Created by dario on 13/08/21.
//

#include "Controller.h"
#include <SFML/Graphics.hpp>

void Controller::Commands() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        pg->move(10, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        pg->move(-10, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        pg->move(0, 10);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        pg->move(0, -10);
}

Controller::Controller(sf::RenderWindow* w, int WinWidth, int WinHeight) {
    mud = new Mud(-300, -150);
    mountains = new Mountain(-300, -300);
    pg = new GameCharacter(0, 0, WinWidth, WinHeight);
    enemy = new GameCharacter(-100, -150);
    map = new WorldMap(WinWidth, WinHeight);
    DrawMap = new MapView(pg, enemy, w, mountains, mud);
}
