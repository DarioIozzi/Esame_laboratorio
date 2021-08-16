//
// Created by dario on 13/08/21.
//

#include "MapView.h"

void MapView::draw(int posx, int posy) {
    //implementare
}

void MapView::update() {
    int posx = pg->getPosX();
    int posy = pg->getPosY();
    draw(posx, posy);
}
