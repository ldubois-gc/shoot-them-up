#include "framework.h"
#include "app.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "obstacle.hpp"

App::App() {
	
}

App::~App() {

}

int App::Init() {
	window = new sf::RenderWindow(sf::VideoMode({ 800, 800 }), "Shoot'em Up !");
	window->setFramerateLimit(60);

	input.InitWindow(window);
	return 0;
}

int App::Runtime() {
	Start();
	while (window->isOpen()) {
		while (const std::optional event = window->pollEvent())
		{
			if (event->is<sf::Event::Closed>()) {
				window->close();
				return 0;
			}
		}

		Sleep(1);
		Update();
		Render();
		gameManager.UpdateManager();
	}
	return 0;
}

void App::Update() {
	timer.UpdateClock();
	input.UpdateEvents();
	float deltaTime = timer.GetDeltaTime();

	for (Entity* entity : gameManager.GetEntities()) {
		entity->Update(deltaTime);
		gameManager.ProcessCollision(entity);
	}
}

void App::Render() {
	window->clear();

	for (Entity* entity : gameManager.GetEntities()) {
		entity->Draw(*window);
	}
	window->display();
}

void App::Start() {
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