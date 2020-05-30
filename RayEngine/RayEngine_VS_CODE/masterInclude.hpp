#ifndef MASTER_INCLUDE_HPP
#define MASTER_INCLUDE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <algorithm>
#include <thread>
#include <future>
#include <mutex>
#include <string>
#include <vector>
#include <stdint.h>
// #include "Windows.h"

using std::string;

#define WINDOW_RESOLUTION_X 500
#define WINDOW_RESOLUTION_Y 500
#define WINDOW_PIXEL_COUNT WINDOW_RESOLUTION_X * WINDOW_RESOLUTION_Y
#define COLOR_BUFFER_SIZE WINDOW_PIXEL_COUNT * 4
#define THREADCOUNT  std::thread::hardware_concurrency()



#endif //MASTER_INCLUDE_HPP