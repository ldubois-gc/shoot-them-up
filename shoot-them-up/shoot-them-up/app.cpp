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

	//allEntities = gameManager.GetEntities();
	return 0;
}

int App::Runtime() {
	Player player(&input, 500.f, 500.f, 10.f, 10.f, sf::Color::Green);
	Enemy enemy1(50.f, 50.f, 10.f, 10.f, sf::Color::Red, &player);
	Enemy enemy2(200.f, 50.f, 10.f, 10.f, sf::Color::Red, &player);
	Obstacle obstacle(100.f, 200.f, 20.f, 20.f, sf::Color::White);
	gameManager.AddEntity(player);
	gameManager.AddEntity(enemy1);
	gameManager.AddEntity(enemy2);
	gameManager.AddEntity(obstacle);

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
	}
	return 0;
}

void App::Update() {
	timer.UpdateClock();
	input.UpdateEvents();
	float deltaTime = timer.GetDeltaTime();

	for (Entity* entity : gameManager.GetEntities()) {
		entity->Update(deltaTime);
	}
	gameManager.UpdateManager();
}

void App::Render() {
	window->clear();

	for (Entity* entity : gameManager.GetEntities()) {
		entity->Draw(*window);
	}
	window->display();
}