//
// Created by dario on 13/08/21.
//

#include "Controller.h"
#include <SFML/Graphics.hpp>

void Controller::Commands() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))     //SINISTRA
        pg->move(10, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))     //DESTRA
        pg->move(-10, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))     //ALTO
        pg->move(0, 10);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))     //BASSO
        pg->move(0, -10);
}

Controller::Controller(sf::RenderWindow* w, int WinWidth, int WinHeight) {
    map = new WorldMap();
    map->CreateMap();
    mud = new Mud(-300, -150);
    map->AddTP(mud);
    mountains = new Mountain(-300, -300);
    map->AddTP(mountains);
    pg = new GameCharacter(0, 0, WinWidth, WinHeight, map);
    enemy = new GameCharacter(-100, -150);
    DrawMap = new MapView(pg, enemy, w, mountains, mud);
}
