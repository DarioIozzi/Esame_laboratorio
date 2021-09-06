//
// Created by dario on 13/08/21.
//

#include "MapView.h"

void MapView::draw(int posx, int posy) {
    shape.setOrigin(posx, posy);
    window->clear();
    window->draw(shape);
    window->display();
}

void MapView::update() {
    int posx = pg->getPosX();
    int posy = pg->getPosY();
    draw(posx, posy);
}

MapView::MapView(GameCharacter *p, sf::RenderWindow* w) : pg(p){
    pg->subscribe(this);
    shape.setRadius(100);
    shape.setFillColor(sf::Color::Red);
    window = w;
    window->clear();
    window->draw(shape);
    window->display();
}

 MapView::~MapView() {
    pg->unsubscribe(this);
}