#pragma once

class EventHandler
{
public:
	EventHandler();
	~EventHandler();

	void InitWindow(sf::RenderWindow* gameWindow);

	sf::Vector2f GetMouseWorld() { return mouseWorld; };
	sf::RenderWindow* GetWindow() { return window; };

	bool IsKeyDown(int keyCode);
	void UpdateEvents();

private:
	bool keys[255];
	sf::Vector2f mouseWorld;
	sf::RenderWindow* window;
};