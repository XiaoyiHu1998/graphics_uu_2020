#include "Timer.hpp"

Timer::Timer() {
	startTime = std::chrono::high_resolution_clock::now();
	endTime = std::chrono::high_resolution_clock::now();
	frameTime = 0;
}

void Timer::startTimer() {
	startTime = std::chrono::high_resolution_clock::now();
	lastFrameTime = frameTime;
}

void Timer::endTimer() {
	endTime = std::chrono::high_resolution_clock::now();
	frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
}

double Timer::getFrameRate() {
	return 1000 / frameTime;
}
double Timer::getFrameTime() {
	return frameTime;
}

double Timer::getLastFrameTime() {
	return frameTime;
}