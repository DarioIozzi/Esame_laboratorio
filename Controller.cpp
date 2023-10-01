//
// Created by dario on 13/08/21.
//

#include "Controller.h"

void Controller::Commands() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))    //SINISTRA
        pg->moveX(-10.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))    //DESTRA
        pg->moveX(10.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))    //SU
        pg->moveY(-10.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))    //GIU'
        pg->moveY(10.0f);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        pg->findpath();
}

Controller::Controller(sf::RenderWindow* w) {
    map = new WorldMap();
    map->CreateMap();
    mud = new Mud({300, 150});
    map->AddTP(mud);
    mountains = new Mountain({300, 400});
    map->AddTP(mountains);
    pg = new GameCharacter({0, 0}, map);
    enemy = new Enemy({600, 500});
    DrawMap = new MapView(pg, enemy, w, mountains, mud);
}
