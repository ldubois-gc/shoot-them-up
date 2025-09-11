#include "framework.h"
#include "projectile.hpp"
#include "character.hpp"

//Projectile::Projectile(float x, float y, float height, float width, float xDir, float yDir, sf::Color color, Manager* manager, Character* newShooter, float actorSpeed) : Actor(x, y, height, width, color, actorSpeed) {
//	xForward = xDir;
//	yForward = yDir;
//	shooter = newShooter;
//	body.setSize(sf::Vector2f(8.f, 8.f));
//}

Projectile::Projectile() {

}

Projectile::~Projectile() {

}

void Projectile::Init(float x, float y, float height, float width, float xDir, float yDir, sf::Color color, Manager* manager, Character* newShooter, float actorSpeed) {
	Actor::Init(x, y, height, width, color, actorSpeed);
	xForward = xDir;
	yForward = yDir;
	shooter = newShooter;
	body.setSize(sf::Vector2f(height, width));
	
	float angleRad = std::atan2(yForward, xForward);
	float angleDeg = angleRad * 180.f / 3.14159f;
	body.setRotation(sf::degrees(angleDeg));
}

void Projectile::Update(float& dt) {
	Move((xForward*speed) * dt, (yForward * speed) * dt);
}

void Projectile::OnCollision(Entity* collidedEntity) {
	if (shooter != collidedEntity) {
		exists = false;
	}
}