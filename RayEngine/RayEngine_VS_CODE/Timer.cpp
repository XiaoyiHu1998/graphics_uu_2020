#include "Timer.hpp"

Timer::Timer() {
	startTime = std::chrono::system_clock::now();
	endTime = std::chrono::system_clock::now();
	frameTime = 0;
}

void Timer::startTimer() {
	startTime = std::chrono::system_clock::now();
}

void Timer::endTimer() {
	endTime = std::chrono::system_clock::now();
	frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
}

double Timer::getFrameRate() {
	return 1000 / frameTime;
}
double Timer::getFrameTime() {
	return frameTime;
}