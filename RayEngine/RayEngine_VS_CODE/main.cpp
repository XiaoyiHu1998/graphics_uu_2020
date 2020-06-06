#include "RayEngine_2D.hpp"

int main(){
    std::cout << "select renderMode:" << std::endl;
    std::cout << "singleThreaded: 1" << std::endl;
    std::cout << "multithreaded: 2" << std::endl;
    std::cout << "multithreaded with threadpool: 3" << std::endl;
    int renderMode;
    while(true){
        std::cin >> renderMode;
        if(renderMode == 1 || renderMode == 2 || renderMode == 3){
            break;
        }
    }

    std::cout << std::thread::hardware_concurrency() << std::endl;
    sf::RenderWindow window{ sf::VideoMode(WINDOW_RESOLUTION_X, WINDOW_RESOLUTION_Y), "RayEngine" };
    RayEngine_2D rayEngine(window);
    rayEngine.init(renderMode);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
                window.close();
                if(renderMode == 3){
                    rayEngine.exit();
                }
                exit(0);
            }
        }

        rayEngine.renderLoop();
    }
}