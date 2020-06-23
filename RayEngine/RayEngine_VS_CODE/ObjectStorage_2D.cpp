#include "ObjectStorage_2D.hpp"

ObjectStorage_2D::ObjectStorage_2D(){}

std::vector<Light_2D>& ObjectStorage_2D::getLightVector(){
    return lightVector;
}

std::vector<std::shared_ptr<Circle_2D>>& ObjectStorage_2D::getobjects(){
    return objects;
}

void ObjectStorage_2D::init(){
    int midx = WINDOW_RESOLUTION_X / 2;
    int midy = WINDOW_RESOLUTION_Y / 2;
    float full360 = 2 * 3.14;

    lightVector = {
            Light_2D(sf::Vector2f(0, midy / 4), sf::Vector3f(0.2, 0.4, 0.7), 5),
            Light_2D(sf::Vector2f(midx, midy), sf::Vector3f(0.7, 0.4, 0.3), 5, false),
            Light_2D(sf::Vector2f(-1 * WINDOW_RESOLUTION_X / 3, WINDOW_RESOLUTION_Y - midy / 4), sf::Vector3f(0.1, 0.2, 0.1), 5),

            //Light_2D(sf::Vector2f(0, midy / 3), sf::Vector3f(0.2, 0.4, 0.7), 5),
            //Light_2D(sf::Vector2f(midx, midy), sf::Vector3f(0.7, 0.4, 0.3), 5, false),
            //Light_2D(sf::Vector2f(-1 * WINDOW_RESOLUTION_X / 3, WINDOW_RESOLUTION_Y - midy / 3), sf::Vector3f(0.1, 0.2, 0.1), 5),
            //Light_2D(sf::Vector2f(0, 50), sf::Vector3f(0.2, 0.5, 0.4), 5)
    };

    objects = std::vector<std::shared_ptr<Circle_2D>>{
           /* std::make_shared<Circle_2D>(sf::Vector2f(350,250), 20, 50),
            std::make_shared<Circle_2D>(sf::Vector2f(120,340), 20, 64),
            std::make_shared<Circle_2D>(sf::Vector2f(500,50), 30, 21),
            std::make_shared<Circle_2D>(sf::Vector2f(150,100), 50, 15),*/

            std::make_shared<Circle_2D>(sf::Vector2f(midx, midy), WINDOW_RESOLUTION_Y / 20, WINDOW_RESOLUTION_Y / 4, 1 * full360 / 3),
            std::make_shared<Circle_2D>(sf::Vector2f(midx, midy), WINDOW_RESOLUTION_Y / 20, WINDOW_RESOLUTION_Y / 4, 2 * full360 / 3),
            std::make_shared<Circle_2D>(sf::Vector2f(midx, midy), WINDOW_RESOLUTION_Y / 20, WINDOW_RESOLUTION_Y / 4, 3 * full360 / 3),

            //std::make_shared<Circle_2D>(sf::Vector2f(midx, midy), WINDOW_RESOLUTION_Y / 20, WINDOW_RESOLUTION_Y / 8, 1.5 * full360 / 3),
            //std::make_shared<Circle_2D>(sf::Vector2f(midx, midy), WINDOW_RESOLUTION_Y / 20, WINDOW_RESOLUTION_Y / 8, 2.5 * full360 / 3),
            //std::make_shared<Circle_2D>(sf::Vector2f(midx, midy), WINDOW_RESOLUTION_Y / 20, WINDOW_RESOLUTION_Y / 8, 3.5 * full360 / 3)
    };
}