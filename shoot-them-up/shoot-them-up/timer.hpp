#pragma once

class Timer
{
public:
	Timer();
	~Timer();

	int GetDeltaTime();

private:
	DWORD startTime;
};