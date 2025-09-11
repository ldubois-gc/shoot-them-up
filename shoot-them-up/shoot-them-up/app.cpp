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
	gameManager.CreatePlayer(&input, 500.f, 500.f);
	gameManager.CreateEnemy(50.f, 50.f, 100.f);
	gameManager.CreateEnemy(150.f, 50.f, 100.f);
	gameManager.CreateEnemy(100.f, 50.f, 100.f);
	gameManager.CreateObstacle(20.f, 200.f, 200.f, 20.f);

	/*for (int i = 0; i < 20; i++)
	{
		float randomXPos = ((float)rand()) / (float)800;
		float randomYPos = ((float)rand()) / (float)800;
		gameManager.CreateEnemy(randomXPos, randomYPos, 100.f);
	}

	for (int i = 0; i < 100; i++)
	{
		float randomXPos = ((float)rand()) / (float)800;
		float randomYPos = ((float)rand()) / (float)800;
		gameManager.CreateObstacle(randomXPos, randomYPos, 20.f, 20.f);
	}*/
}