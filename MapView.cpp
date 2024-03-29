//
// Created by dario on 13/08/21.
//

#include "MapView.h"

void MapView::Draw() {
    window->clear();
    window->draw(pgShape);
    window->draw(enemyShape);
    window->draw(mudShape);
    window->draw(mountainsShape);
    if(pg->FP)
        window->draw(pg->path);
    window->display();
}

void MapView::update() {
    pgShape.setPosition({pg->getPos().x, pg->getPos().y});
    Draw();
}

MapView::MapView(GameCharacter *p, Enemy* e, sf::RenderWindow* w) : pg(p), enemy(e){
    //personaggio
    pg->subscribe(this);
    pgShape.setSize(pg->getSize());
    pgShape.setOrigin(0.f, 0.f);
    pgShape.setPosition(pg->getPos());
    pgShape.setFillColor(sf::Color::Red);
    //nemico
    enemyShape.setSize(enemy->getSize());
    enemyShape.setOrigin(0.f, 0.f);
    enemyShape.setPosition(enemy->getPos());
    enemyShape.setFillColor(sf::Color::White);
    //mud
    mudShape.setSize(mudSize);
    mudShape.setOrigin(0.f, 0.f);
    mudShape.setPosition(mudPos);
    mudShape.setFillColor(sf::Color::Cyan);
    //mountains
    mountainsShape.setSize(mountainSize);
    mountainsShape.setOrigin(0.f, 0.f);
    mountainsShape.setPosition(mountainPos);
    mountainsShape.setFillColor(sf::Color::White);
    //finestra
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