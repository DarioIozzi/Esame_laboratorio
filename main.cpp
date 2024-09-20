#include <SFML/Graphics.hpp>
#include "Controller.h"

const int WinWidth = 800;
const int WinHeight = 600;

int main() {

    sf::RenderWindow window(sf::VideoMode(WinWidth, WinHeight), "Esame laboratorio");
    TerrainType Mountain({100, 100}, {300, 400}, mountains);
    TerrainType Mud({100, 100}, {300, 400}, mud);
    addTT(&Mountain);
    addTT(&Mud);
    Controller game(&window);
    while(window.isOpen()){
        sf::Event event{};
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                game.Commands();
        }
    }
}
