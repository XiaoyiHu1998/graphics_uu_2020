#include "RayEngine_2D.hpp"


int main(){
    std::cout << "running" << std::endl;
    RayEngine_2D rayEngine;
    rayEngine.init();

    sf::RenderWindow* window = rayEngine.getWindowPointer();

    while(window->isOpen()){
        sf::Event event;

        while(window->pollEvent(event)){

            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
                window->close();
            }
        }

        rayEngine.renderLoop();
    }
}