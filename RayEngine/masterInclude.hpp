#ifndef MASTER_INCLUDE_HPP
#define MASTER_INCLUDE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <thread>
#include <string>
#include <vector>

using std::string;

// unsigned int threadCount = std::thread::hardware_concurrency();
// #define THREAD_COUNT threadCount
#define WINDOW_RESOLUTION_X 640
#define WINDOW_RESOLUTION_Y 400
#define WINDOW_PIXEL_COUNT WINDOW_RESOLUTION_X * WINDOW_RESOLUTION_Y
#define COLOR_BUFFER_SIZE WINDOW_PIXEL_COUNT * 4


#endif //MASTER_INCLUDE_HPP