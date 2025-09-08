#pragma once

class Timer
{
public:
	Timer();
	~Timer();

	float GetDeltaTime();

private:
	DWORD startTime;
};