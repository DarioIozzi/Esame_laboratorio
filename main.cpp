#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Findpath.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
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
