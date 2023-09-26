//
// Created by dario on 13/08/21.
//

#ifndef ESAME_LABORATORIO_MAPVIEW_H
#define ESAME_LABORATORIO_MAPVIEW_H

#include <SFML/Graphics.hpp>
#include "Observer.h"
#include "GameCharacter.h"
#include "Display.h"
#include "TerrainType.h"

class MapView : public Observer, public Display{
public:
    explicit MapView(GameCharacter* p, GameCharacter* e, sf::RenderWindow* w, TerrainType* Mountains, TerrainType* Mud);
    ~MapView() override;

    void update() override;

    void Draw(int posx, int posy) override;
private:
    GameCharacter* pg;
    GameCharacter* enemy;
    TerrainType* Mountains;
    TerrainType* Mud;
    sf::CircleShape pgShape;
    sf::RectangleShape enemyShape;
    sf::RenderWindow* window;
};


#endif //ESAME_LABORATORIO_MAPVIEW_H
