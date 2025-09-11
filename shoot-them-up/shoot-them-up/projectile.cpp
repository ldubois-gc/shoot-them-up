#include "framework.h"
#include "projectile.hpp"

Projectile::Projectile(float x, float y, float height, float width, float xDir, float yDir, sf::Color color, Manager* manager, Character* newShooter, float actorSpeed) : Actor(x, y, height, width, color, actorSpeed) {
	xForward = xDir;
	yForward = yDir;
	shooter = newShooter;
	body.setSize(sf::Vector2f(8.f, 8.f));
}

Projectile::~Projectile() {

}

void Projectile::Update(float& dt) {
	Move((xForward*speed) * dt, (yForward * speed) * dt);
}

void Projectile::OnCollision(Entity* collidedEntity) {
	if (shooter != collidedEntity) {
		exists = false;
	}
}