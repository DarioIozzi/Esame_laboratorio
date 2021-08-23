//
// Created by dario on 13/08/21.
//

#include "MapView.h"
#include <iostream>

void MapView::draw(int posx, int posy) {
    std::cout << "Coordinate x: " << posx << " y: " << posy << std::endl;
}

void MapView::update() {
    int posx = pg->getPosX();
    int posy = pg->getPosY();
    draw(posx, posy);
}

MapView::MapView(GameCharacter *p) : pg(p){
    pg->subscribe(this);
}
 MapView::~MapView() {
    pg->unsubscribe(this);
}