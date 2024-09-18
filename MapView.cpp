//
// Created by dario on 13/08/21.
//

#include "MapView.h"

void MapView::Draw() {
    window->clear();
    window->draw(pg->pgShape);
    window->draw(enemy->enemyShape);
    for(TerrainType* t : TT)
        window->draw(t->TerrainShape);
    if(pg->FP)
        window->draw(pg->path);
    window->display();
}

void MapView::update() {
    pg->pgShape.setPosition({pg->getPos().x, pg->getPos().y});
    Draw();
}

MapView::MapView(GameCharacter *p, Enemy* e, sf::RenderWindow* w) : pg(p), enemy(e){
    //personaggio
    pg->subscribe(this);
    //finestra
    window = w;
    window->clear();
    window->draw(enemy->enemyShape);
    window->draw(pg->pgShape);
    for(TerrainType* t : TT)
        window->draw(t->TerrainShape);
    window->display();
}

 MapView::~MapView() {
    pg->unsubscribe(this);
}