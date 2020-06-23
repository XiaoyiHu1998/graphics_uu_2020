#ifndef TIMER_HPP
#define TIMER_HPP

#include "masterInclude.hpp"

class Timer{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
    double frameTime;
    double lastFrameTime;
public:
    Timer();
    void startTimer();
    void endTimer();
    double getFrameRate();
    double getFrameTime();
    double getLastFrameTime();
};


#endif //TIMER_HPP