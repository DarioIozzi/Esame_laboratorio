//
// Created by dario on 13/08/21.
//

#ifndef ESAME_LABORATORIO_MAPVIEW_H
#define ESAME_LABORATORIO_MAPVIEW_H

#include <SFML/Graphics.hpp>
#include "Observer.h"
#include "Enemy.h"
#include "GameCharacter.h"
#include "Display.h"
#include "TerrainType.h"

class MapView : public Observer, public Display{
public:
    explicit MapView(GameCharacter* p, Enemy* e, sf::RenderWindow* w, TerrainType* Mountains, TerrainType* Mud);
    ~MapView() override;

    void update() override;

    void Draw(sf::Vector2f p) override;
private:
    GameCharacter* pg;
    Enemy* enemy;
    TerrainType* mountains;
    TerrainType* mud;
    sf::RectangleShape pgShape;
    sf::RectangleShape enemyShape;
    sf::RenderWindow* window;
    sf::RectangleShape mudShape;
    sf::RectangleShape mountainsShape;
};


#endif //ESAME_LABORATORIO_MAPVIEW_H
