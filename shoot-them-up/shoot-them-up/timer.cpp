#include "framework.h"
#include "timer.hpp"

int Timer::GetDeltaTime() {
	return timeGetTime() - startTime;
}