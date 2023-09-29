//
// Created by Dario on 29/09/2023.
//

#ifndef ESAME_LABORATORIO_ENEMY_H
#define ESAME_LABORATORIO_ENEMY_H

class Enemy {
public:

    explicit Enemy(sf::Vector2f o) : pos(o) {}
    ~Enemy() = default;

    sf::Vector2f getPos() const {
        return pos;
    }

    sf::Vector2f getSize() const{
        return size;
    }

private:
    sf::Vector2f size {30.f,30.f};
    sf::Vector2f pos;
};

#endif //ESAME_LABORATORIO_ENEMY_H
