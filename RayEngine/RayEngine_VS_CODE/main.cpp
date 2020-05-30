#include "RayEngine_2D.hpp"


int main(){
    std::cout << "running" << std::endl;
    sf::RenderWindow window{ sf::VideoMode(WINDOW_RESOLUTION_X, WINDOW_RESOLUTION_Y), "RayEngine" };
    RayEngine_2D rayEngine(window);
    rayEngine.init();

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
                window.close();
                exit(0);
            }
        }

        rayEngine.renderLoop();
    }
}