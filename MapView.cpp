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
    window->display();
}

void MapView::update() {
    sf::Vector2f p = pg->getPos();
    Draw(p);
}

MapView::MapView(GameCharacter *p, Enemy* e, sf::RenderWindow* w, TerrainType* Mountains, TerrainType* Mud) : pg(p), enemy(e), mud(Mud), mountains(Mountains){
    pg->subscribe(this);
    pgShape.setSize(pg->getSize());
    pgShape.setOrigin(pg->getSize().x/2, pg->getSize().y/2);
    pgShape.setPosition(pg->getPos());
    pgShape.setFillColor(sf::Color::Red);
    enemyShape.setSize(enemy->getSize());
    enemyShape.setOrigin(enemy->getSize().x/2, enemy->getSize().y/2);
    enemyShape.setPosition(enemy->getPos());
    enemyShape.setFillColor(sf::Color::White);
    mudShape.setSize(mud->getSize());
    mudShape.setOrigin(mud->getSize().x/2, mud->getSize().y/2);
    mudShape.setPosition(mud->getPos());
    mudShape.setFillColor(sf::Color::Cyan);
    mountainsShape.setSize(mountains->getSize());
    mountainsShape.setOrigin(mountains->getSize().x/2, mountains->getSize().y/2);
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