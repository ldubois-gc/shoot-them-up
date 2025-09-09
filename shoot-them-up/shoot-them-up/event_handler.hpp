#pragma once

class EventHandler
{
public:
	EventHandler();
	~EventHandler();

	bool IsKeyDown(int keyCode);
	void UpdateEvents();

private:
	bool keys[255];
};