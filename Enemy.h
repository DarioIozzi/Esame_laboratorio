//
// Created by Dario on 29/09/2023.
//

#ifndef ESAME_LABORATORIO_ENEMY_H
#define ESAME_LABORATORIO_ENEMY_H

class Enemy {
public:

    explicit Enemy(sf::Vector2f o){
        pos = o;
        enemyShape.setSize(size);
        enemyShape.setOrigin(0.f, 0.f);
        enemyShape.setPosition(pos);
        enemyShape.setFillColor(sf::Color::White);
    }
    ~Enemy() = default;

    sf::Vector2f getPos() const {
        return pos;
    }

    sf::Vector2f getSize() const{
        return size;
    }

    sf::RectangleShape enemyShape;

private:
    sf::Vector2f size {30.f,30.f};
    sf::Vector2f pos;
};

#endif //ESAME_LABORATORIO_ENEMY_H
