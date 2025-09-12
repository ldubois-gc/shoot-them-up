#include "framework.h"
#include "app.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "obstacle.hpp"
#include "app_state.hpp"

App::App() : appMachine(*this) {
	
}

App::~App() {

}

int App::Init() {
	window = new sf::RenderWindow(sf::VideoMode({ 800, 800 }), "Shoot'em Up !");
	window->setFramerateLimit(60);

	input.InitWindow(window);
	appMachine.ChangeState(&game);
	return 0;
}

int App::Runtime() {
	//GameStart();
	while (window->isOpen()) {
		while (const std::optional event = window->pollEvent())
		{
			if (event->is<sf::Event::Closed>()) {
				window->close();
				return 0;
			}
		}

		Sleep(1);
		float deltaTime = timer.GetDeltaTime();
		appMachine.Update(deltaTime);
		Render();
		gameManager.UpdateManager();
	}
	return 0;
}

void App::GameUpdate(float& dt) {
	timer.UpdateClock();
	input.UpdateEvents();

	for (Entity* entity : gameManager.GetEntities()) {
		entity->Update(dt);
		gameManager.ProcessCollision(entity);
	}
}

void App::GameStart() {
	gameManager.CreatePlayer(&input, 400.f, 400.f);
	gameManager.CreateObstacle(-100.f, 0.f, 100.f, 800.f);
	gameManager.CreateObstacle(0.f, -100.f, 800.f, 100.f);
	gameManager.CreateObstacle(800.f, 0.f, 100.f, 800.f);
	gameManager.CreateObstacle(0.f, 800.f, 800.f, 100.f);

	for (int i = 0; i < 20; i++)
	{
		float randomXPos = (float)rand() / (float)RAND_MAX * 800;
		float randomYPos = (float)rand() / (float)RAND_MAX * 800;
		gameManager.CreateEnemy(randomXPos, randomYPos, 80.f);
	}

	for (int i = 0; i < 100; i++)
	{
		float randomXPos = (float)rand() / (float)RAND_MAX * 800.0f;
		float randomYPos = (float)rand() / (float)RAND_MAX * 800;
		gameManager.CreateObstacle(randomXPos, randomYPos, 20.f, 20.f);
	}
}

void App::GameOverStart() {

}

void App::GameOverUpdate(float& dt) {
	input.UpdateEvents();
	if (input.IsKeyDown(VK_SPACE)) {
		appMachine.ChangeState(&game);
	}
}

void App::Render() {
	window->clear();

	for (Entity* entity : gameManager.GetEntities()) {
		entity->Draw(*window);
	}
	window->display();
}

void App::StateChange(State<App>* newState) {
	appMachine.ChangeState(newState);
}