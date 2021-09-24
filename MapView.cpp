//
// Created by dario on 13/08/21.
//

#include "MapView.h"

void MapView::draw(int posx, int posy) {
    pgShape.setOrigin(posx, posy);
    window->clear();
    window->draw(pgShape);
    window->draw(enemyShape);
    window->display();
}

void MapView::update() {
    int posx = pg->getPosX();
    int posy = pg->getPosY();
    draw(posx, posy);
}

MapView::MapView(GameCharacter *p, GameCharacter* e, sf::RenderWindow* w) : pg(p), enemy(e){
    pg->subscribe(this);
    pgShape.setRadius(40);
    pgShape.setOrigin(pg->getPosX(), pg->getPosY());
    pgShape.setFillColor(sf::Color::Red);
    enemyShape.setSize(sf::Vector2f(80.f, 55.f));
    enemyShape.setOrigin(enemy->getPosX(), enemy->getPosY());
    enemyShape.setFillColor(sf::Color::White);
    window = w;
    window->clear();
    window->draw(enemyShape);
    window->draw(pgShape);
    window->display();
}

 MapView::~MapView() {
    pg->unsubscribe(this);
}