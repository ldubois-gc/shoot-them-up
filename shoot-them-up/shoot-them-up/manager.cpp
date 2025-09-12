#include "framework.h"
#include "manager.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "projectile.hpp"
#include "bomb.hpp"
#include "obstacle.hpp"

float gameClock;

Manager::Manager() {}

Manager::~Manager() {}

void Manager::ProcessCollision(Entity* entity) {
    ResetAllCollisions();

	for (Entity* otherEntity : entities) {
		if (entity != otherEntity && CheckCollision(entity, otherEntity)) {
			entity->OnCollision(otherEntity);
			otherEntity->OnCollision(entity);
		}
	}
}

bool Manager::CheckCollision(Entity* a, Entity* b) {
	return  a->GetX() < b->GetX() + b->GetWidth() &&
			a->GetX() + a->GetWidth() > b->GetX() &&
			a->GetY() < b->GetY() + b->GetHeigth() &&
			a->GetY() + a->GetHeigth() > b->GetY();
}


void Manager::ResetAllCollisions() {
    for (Entity* entity : entities) {
        entity->collide = false;
    }
}

void Manager::UpdateManager() {
	RemoveFlaggedEntities();
	for (Entity* entity : newEntities) {
		entities.push_back(entity);
	}
	newEntities.clear();
}

void Manager::AddEntity(Entity* newEntity) {
	newEntities.push_back(newEntity);
}

void Manager::RemoveFlaggedEntities() {
	entities.erase(
		std::remove_if(
			entities.begin(), 
			entities.end(), 
			[](Entity* e) { 
				if (!e->Exists()) {
					delete e; 
					return true;      
				}
				return false;
			}), 
		entities.end()
	);
}

void Manager::ClearEntities() {
	for (Entity* entity : entities) {
		entity->Kill();
	}
}

void Manager::CreatePlayer(EventHandler* input, float xPos, float yPos) {
	player = new Player();
	player->Init(input, xPos, yPos, 20.f, 20.f, sf::Color::Green, this, 200.f);
	AddEntity(player);
}

void Manager::CreateEnemy(float xPos, float yPos, float speed) {
	Enemy* enemy = new Enemy();
	enemy->Init(xPos, yPos, 15.f, 15.f, sf::Color::Yellow, this, player, speed);
	AddEntity(enemy);
	nFoes++;
}

void Manager::CreateProjectile(float xPos, float yPos, float xDir, float yDir, float bulletSpeed, Character* shooter) {
	Projectile* bullet = new Projectile();
	bullet->Init(xPos, yPos, 8.f, 3.f, xDir, yDir, sf::Color(214, 50, 0), this, shooter, bulletSpeed);
	AddEntity(bullet);
}

void Manager::CreateBomb(float xPos, float yPos, float xDir, float yDir, float bulletSpeed, Character* shooter) {
	Bomb* bomb = new Bomb();
	bomb->Init(xPos, yPos, 15.f, 15.f, xDir, yDir, sf::Color(255, 82, 0), this, shooter, bulletSpeed);
	AddEntity(bomb);
}

void Manager::CreateObstacle(float xPos, float yPos, float height, float width) {
	Obstacle* obstacle = new Obstacle();
	obstacle->Init(xPos, yPos, width, height, sf::Color::White);
	AddEntity(obstacle);
	obstacles.push_back(obstacle);
}