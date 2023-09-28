//
// Created by dario on 13/08/21.
//

#include "MapView.h"

void MapView::Draw(sf::Vector2f p) {
    pgShape.setOrigin(p.x, p.y);
    window->clear();
    window->draw(pgShape);
    window->draw(enemyShape);
    window->draw(mudShape);
    window->draw(mountainsShape);
    window->display();
}

void MapView::update() {
    sf::Vector2f p = pg->getPos();
    Draw(p);
}

MapView::MapView(GameCharacter *p, GameCharacter* e, sf::RenderWindow* w, TerrainType* Mountains, TerrainType* Mud) : pg(p), enemy(e), mud(Mud), mountains(Mountains){
    pg->subscribe(this);
    pgShape.setRadius(40);                          //TODO SET ORIGIN CON CENTRO DI SIMMETRIA
    pgShape.setOrigin(0.f,0.f);
    pgShape.setPosition(pg->getPos());
    pgShape.setFillColor(sf::Color::Red);
    enemyShape.setSize(sf::Vector2f(80.f, 55.f));
    enemyShape.setOrigin(0.f,0.f);
    enemyShape.setPosition(enemy->getPos());
    enemyShape.setFillColor(sf::Color::White);
    mudShape.setSize(sf::Vector2f(100.f, 100.f));
    mudShape.setOrigin(0.f,0.f);
    mudShape.setPosition(mud->getPos());
    mudShape.setFillColor(sf::Color::Cyan);
    mountainsShape.setSize(sf::Vector2f (100.f, 100.f));
    mountainsShape.setOrigin(0.f,0.f);
    mountainsShape.setPosition(mountains->getPos());
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