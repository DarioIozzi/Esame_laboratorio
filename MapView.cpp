//
// Created by dario on 13/08/21.
//

#include "MapView.h"

void MapView::Draw(sf::Vector2f p) {
    pgShape.setPosition({p.x, p.y});
    window->clear();
    window->draw(pgShape);
    window->draw(enemyShape);
    window->draw(mudShape);
    window->draw(mountainsShape);
    if(pg->FP)
        window->draw(*path);
    window->display();
}

void MapView::update() {
    sf::Vector2f p = pg->getPos();
    Draw(p);
}

MapView::MapView(GameCharacter *p, Enemy* e, sf::RenderWindow* w, TerrainType* Mountains, TerrainType* Mud) : pg(p), enemy(e), mud(Mud), mountains(Mountains){
    pg->subscribe(this);
    pgShape.setSize(pg->getSize());
    pgShape.setOrigin(0.f, 0.f);
    pgShape.setPosition(pg->getPos());
    pgShape.setFillColor(sf::Color::Red);
    enemyShape.setSize(enemy->getSize());
    enemyShape.setOrigin(0.f, 0.f);
    enemyShape.setPosition(enemy->getPos());
    enemyShape.setFillColor(sf::Color::White);
    mudShape.setSize(mud->getSize());
    mudShape.setOrigin(0.f, 0.f);
    mudShape.setPosition(mud->getPos());
    mudShape.setFillColor(sf::Color::Cyan);
    mountainsShape.setSize(mountains->getSize());
    mountainsShape.setOrigin(0.f, 0.f);
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