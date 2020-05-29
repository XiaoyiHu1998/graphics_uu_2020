#include "Renderer_2D.hpp"
#include "masterInclude.hpp"
#include <execution>
#include "Windows.h"

Renderer_2D::Renderer_2D(sf::RenderWindow& window) :
    window{ window },
    threadCount{THREADCOUNT},
    rayCaster{THREADCOUNT},
    objectStorage{ ObjectStorage_2D() },
    renderThreads{std::vector<std::thread>()},
    render{std::vector<bool>()},
    colorBuffer{ std::vector<float>() }
    {
        colorBuffer.reserve(COLOR_BUFFER_SIZE);
        colorBuffer.assign(colorBuffer.capacity(), 0.0f);
        objectStorage.init();
    }

void Renderer_2D::init(){
    renderFrameBuffer = sf::Image();
    renderFrameBuffer.create(WINDOW_RESOLUTION_X, WINDOW_RESOLUTION_Y);
    texture = sf::Texture();
    sprite = sf::Sprite();

    renderThreads.reserve(threadCount);
    render.reserve(threadCount);
    renderThreads.clear();
    render.assign(threadCount, false);

    for (int i = 0; i < threadCount; i++) {
        renderThreads.push_back(
            std::thread(
                &RayCaster_2D::castRaysMT,
                &rayCaster,
                std::ref(objectStorage.getLightVector()),
                std::ref(objectStorage.getobjects()),
                std::ref(colorBuffer),
                i,
                std::ref(render),
                std::ref(renderMutex),
                std::ref(bufferMutex)
            )
        );
    }
}

void Renderer_2D::renderFrame(){
    renderMutex.lock();
    for (int i = 0; i < render.size(); i++) {
        render[i] = true;
    }
    renderMutex.unlock();

    while (true) {
        renderMutex.lock();
        bool frameRendered = true;
        for (int i = 0; i < render.size(); i++) {
            if (render[i]) {
                frameRendered = false;
            }
        }
        renderMutex.unlock();
        if (frameRendered) {
            break;
        }
    }

    

    /*std::vector<std::thread> renderThreads;
    renderThreads.reserve(threadCount);

    for (int i = 0; i < threadCount; i++) {
        renderThreads.push_back(
            std::thread(
                &RayCaster_2D::castRays,
                &rayCaster,
                std::ref(objectStorage.getLightVector()),
                std::ref(objectStorage.getobjects()),
                std::ref(colorBuffer),
                i
            )
        );
    }
    for (std::thread& thread : renderThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    renderThreads.erase(renderThreads.begin(), renderThreads.end());*/

    /*for (int i = 0; i < threadCount; i++) {
        rayCaster.castRays(
            objectStorage.getLightVector(),
            objectStorage.getobjects(),
            colorBuffer,
            i,
            bufferMutex
        );
    }*/

    for(Light_2D &light : objectStorage.getLightVector()){
        light.updatePosition();
        light.updateColor();
    }
    for(std::shared_ptr<Circle_2D> &circle : objectStorage.getobjects()){
        circle->updatePosition();
    }

    std::lock_guard<std::mutex> colorBufferGuard(bufferMutex);
    for(unsigned int y = 0; y < WINDOW_RESOLUTION_Y; y++) {
        for (unsigned int x = 0; x < WINDOW_RESOLUTION_X; x++){
            int currentCoord = x + y * WINDOW_RESOLUTION_X;
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

sf::Color Renderer_2D::getRenderBufferColor(uint_fast64_t x, uint_fast64_t y){
    uint_fast64_t index = (x + y * WINDOW_RESOLUTION_X) * 4;

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