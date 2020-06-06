#ifndef TIMER_HPP
#define TIMER_HPP

#include "masterInclude.hpp"

class Timer{
private:
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> endTime;
    double frameTime;
public:
    Timer();
    void startTimer();
    void endTimer();
    double getFrameRate();
    double getFrameTime();
};


#endif //TIMER_HPP