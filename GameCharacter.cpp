//
// Created by dario on 12/08/21.
//

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"

void GameCharacter::move(int x, int y) {
    posX += x;
    posY += y;
    notify();
}

void GameCharacter::subscribe(Observer* o) {
    observers.push_back(o);
}

void GameCharacter::unsubscribe(Observer* o) {
    observers.remove(o);
}

void GameCharacter::notify() const {
    for(auto obs : observers){
        obs->update();
    }
}

GameCharacter::GameCharacter() {
    posX = 0;
    posY = 0;
    //sf::Texture texture;
    //texture.loadFromFile("image.png");
}