#include "framework.h"
#include "bomb.hpp"
#include "character.hpp"

Bomb::Bomb() {

}

Bomb::~Bomb() {

}

void Bomb::Init(float x, float y, float height, float width, float xDir, float yDir, sf::Color color, Manager* manager, Character* newShooter, float actorSpeed = 20.f) {
	Projectile::Init(x, y, height, width, xDir, yDir, color, manager, newShooter, actorSpeed);
	xRange = 20.f;
	yRange = 20.f;
}

void Bomb::Explode() {

}

void Bomb::OnCollision(Entity* collidedEntity) {
	if (shooter != collidedEntity && collidedEntity->Type() != EntityType::PROJECTILE) {
		exists = false;
	}
}