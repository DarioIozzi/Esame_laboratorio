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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))   //FINDPATH
        pg->findpath(enemy->getPos());
}

Controller::Controller(sf::RenderWindow* w) : window(w) {
    WorldMap::CreateMap();
    mud = new Mud({300, 150});
    WorldMap::AddTT(mud);
    mountains = new Mountain({300, 400});
    WorldMap::AddTT(mountains);
    pg = new GameCharacter({0, 0});
    enemy = new Enemy({200, 500});
    DrawMap = new MapView(pg, enemy, w, mountains, mud);
}
