#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "WorldMap.h"

const int WinWidth = 800;
const int WinHeight = 600;

int main() {

    sf::RenderWindow window(sf::VideoMode(WinWidth, WinHeight), "Esame laboratorio");
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
