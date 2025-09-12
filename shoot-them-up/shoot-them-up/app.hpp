#pragma once

#include "timer.hpp"
#include "manager.hpp"
#include "event_handler.hpp"
#include "app_state.hpp"
#include "state.hpp"

class App
{
public:
	AppInGame game;
	AppGameOver gameOver;

	App();
	~App();

	EventHandler* GetInput() { return &input; }
	Manager* GetManager() { return &gameManager; }

	int Init();
	int Runtime();

	void GameStart();
	void GameUpdate(float& dt);
	void GameOverStart();
	void GameOverUpdate(float& dt);

	void Render();

	void StateChange(State<App>* newState);

private:
	Timer timer;
	Manager gameManager;
	EventHandler input;
	sf::RenderWindow* window;
	StateMachine<App> appMachine;
};