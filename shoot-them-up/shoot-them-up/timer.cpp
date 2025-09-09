#include "framework.h"
#include "timer.hpp"

Timer::Timer() {;
	lastFrameTime = timeGetTime();
	totalTime = 0.0f;
	deltaTime = 0.0f;
}

Timer::~Timer() {

}

void Timer::UpdateClock() {
	DWORD currentTime = timeGetTime();
	DWORD elapsedTime = currentTime - lastFrameTime;
	lastFrameTime = currentTime;

	deltaTime = elapsedTime * 0.001f;
	totalTime += deltaTime;
}