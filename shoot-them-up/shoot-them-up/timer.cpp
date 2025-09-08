#include "framework.h"
#include "timer.hpp"

Timer::Timer() {

}

Timer::~Timer() {

}

float Timer::GetDeltaTime() {
	return static_cast<float>((timeGetTime() - startTime) * 0.0001);
}