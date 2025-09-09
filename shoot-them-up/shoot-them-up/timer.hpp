#pragma once

class Timer
{
public:
	Timer();
	~Timer();

	float GetDeltaTime() { return deltaTime; }
	float GetTotalTime() { return totalTime; }
	void UpdateClock();

private:
	float totalTime;
	float deltaTime;
	DWORD lastFrameTime;
};