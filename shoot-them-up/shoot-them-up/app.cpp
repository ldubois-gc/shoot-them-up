#include "framework.h"
#include "app.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"

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
	Player player = Player(&input, 500.f, 500.f, sf::Color::Green);
	Enemy enemy = Enemy(50.f, 50.f, sf::Color::Red);
	gameManager.AddEntity(player);
	gameManager.AddEntity(enemy);

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
}

void App::Render() {
	window->clear();

	for (Entity* entity : gameManager.GetEntities()) {
		entity->Draw(*window);
	}
	window->display();
}