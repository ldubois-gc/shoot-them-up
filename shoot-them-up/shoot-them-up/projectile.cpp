#include "framework.h"
#include "projectile.hpp"

Projectile::Projectile(float x, float y, float height, float width, float xDir, float yDir, sf::Color color, Manager* manager, float actorSpeed) : Actor(x, y, height, width, color, actorSpeed) {
	xForward = xDir;
	yForward = yDir;
	render.setSize(sf::Vector2f(8.f, 8.f));
}

Projectile::~Projectile() {

}

void Projectile::Update(float& dt) {
	Move((xForward*speed) * dt, (yForward * speed) * dt);
}