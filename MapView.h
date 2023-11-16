//
// Created by dario on 13/08/21.
//

#ifndef ESAME_LABORATORIO_MAPVIEW_H
#define ESAME_LABORATORIO_MAPVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "Observer.h"
#include "Enemy.h"
#include "GameCharacter.h"
#include "Display.h"

class MapView : public Observer, public Display{
public:
    MapView(GameCharacter* p, Enemy* e, sf::RenderWindow* w);
    ~MapView() override;

    void update() override;

    void Draw() override;
private:
    GameCharacter* pg;
    Enemy* enemy;
    sf::RectangleShape pgShape;
    sf::RectangleShape enemyShape;
    sf::RenderWindow* window;
    sf::RectangleShape mudShape;
    sf::RectangleShape mountainsShape;
    sf::VertexArray* path;
};


#endif //ESAME_LABORATORIO_MAPVIEW_H
