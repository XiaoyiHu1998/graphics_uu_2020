#include "Renderer_2D.hpp"

Renderer_2D::Renderer_2D(sf::RenderWindow& window) :
    window{ window },
    rayCaster{threadCount},
    objectStorage{ ObjectStorage_2D() },
    colorBuffer{std::make_shared<float[]>(COLOR_BUFFER_SIZE)}
    {
        objectStorage.init();
        threadCount = std::thread::hardware_concurrency() - 2;
    }

void Renderer_2D::init(){
    renderFrameBuffer = sf::Image();
    renderFrameBuffer.create(WINDOW_RESOLUTION_X, WINDOW_RESOLUTION_Y);
    texture = sf::Texture();
    sprite = sf::Sprite();
}

void Renderer_2D::renderFrame(){

    std::vector<std::thread> renderThreads;
    renderThreads.reserve(threadCount);

    for (int i = 0; i < threadCount; i++) {
        renderThreads.push_back(
            std::thread(
                &RayCaster_2D::castRays, 
                &rayCaster, 
                std::ref(objectStorage.getLightVector()), 
                std::ref(objectStorage.getobjects()), 
                colorBuffer,
                i
            )
        );
    }
    for (int i = 0; i < threadCount; i++) {
        renderThreads[i].join();
    }
    
    for(Light_2D &light : objectStorage.getLightVector()){
        light.updatePosition();
        light.updateColor();
    }
    for(std::shared_ptr<Circle_2D> &circle : objectStorage.getobjects()){
        circle->updatePosition();
    }

    for(unsigned int y = 0; y < WINDOW_RESOLUTION_Y; y++) {
        for (unsigned int x = 0; x < WINDOW_RESOLUTION_X; x++){
            int currentCoord = x + y * WINDOW_RESOLUTION_X;
            sf::Color testColor = sf::Color(currentCoord % 255, currentCoord % 128, currentCoord & 64);
            renderFrameBuffer.setPixel(x, y, getRenderBufferColor(x, y));
        }
    }
}

void Renderer_2D::drawFrame(){
    window.clear(sf::Color::Black);
    texture.loadFromImage(renderFrameBuffer);
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(0,0));
    window.draw(sprite);
    window.display();
}

sf::Color Renderer_2D::getRenderBufferColor(int x, int y){
    int index = (x + y * WINDOW_RESOLUTION_X) * 4;

    sf::Uint8 r = static_cast<sf::Uint8>(getBoundedfloat(colorBuffer[index + 0]) * 255.0f);
    sf::Uint8 g = static_cast<sf::Uint8>(getBoundedfloat(colorBuffer[index + 1]) * 255.0f);
    sf::Uint8 b = static_cast<sf::Uint8>(getBoundedfloat(colorBuffer[index + 2]) * 255.0f);
    sf::Uint8 a = static_cast<sf::Uint8>(getBoundedfloat(colorBuffer[index + 3]) * 255.0f);

    return sf::Color(r,g,b,a);
}

float Renderer_2D::getBoundedfloat(float number){
    if(number > 1){
        return 1;
    }
    else if(number > 0){
        return number;
    }
    else{
        return 0;
    }
}