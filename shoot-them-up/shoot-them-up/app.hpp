#pragma once

#include "timer.hpp"
#include "manager.hpp"
#include "event_handler.hpp"

class App
{
public:
	App();
	~App();

	int Init();
	int Runtime();

	void Start();
	void Update();
	void Render();

private:
	Timer timer;
	Manager gameManager;
	EventHandler input;
	sf::RenderWindow* window;
};