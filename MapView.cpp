//
// Created by dario on 13/08/21.
//

#include "MapView.h"

void MapView::Draw(int posx, int posy) {
    pgShape.setOrigin(posx, posy);
    window->clear();
    window->draw(pgShape);
    window->draw(enemyShape);
    window->draw(mudShape);
    window->draw(mountainsShape);
    window->display();
}

void MapView::update() {
    int posx = pg->getPosX();
    int posy = pg->getPosY();
    Draw(posx, posy);
}

MapView::MapView(GameCharacter *p, GameCharacter* e, sf::RenderWindow* w, TerrainType* Mountains, TerrainType* Mud) : pg(p), enemy(e), mud(Mud), mountains(Mountains){
    pg->subscribe(this);
    pgShape.setRadius(40);
    pgShape.setOrigin(pg->getPosX(), pg->getPosY());
    pgShape.setFillColor(sf::Color::Red);
    enemyShape.setSize(sf::Vector2f(80.f, 55.f));
    enemyShape.setOrigin(enemy->getPosX(), enemy->getPosY());
    enemyShape.setFillColor(sf::Color::White);
    mudShape.setSize(sf::Vector2f(100.f, 100.f));
    mudShape.setOrigin(mud->getPosX(), mud->getPosY());
    mudShape.setFillColor(sf::Color::Cyan);
    mountainsShape.setSize(sf::Vector2f (100.f, 100.f));
    mountainsShape.setOrigin(mountains->getPosX(), mountains->getPosY());
    mountainsShape.setFillColor(sf::Color::White);
    window = w;
    window->clear();
    window->draw(enemyShape);
    window->draw(pgShape);
    window->draw(mudShape);
    window->draw(mountainsShape);
    window->display();
}

 MapView::~MapView() {
    pg->unsubscribe(this);
}