#include "framework.h"
#include "projectile.hpp"

Projectile::Projectile() {

}

Projectile::~Projectile() {

}

void Projectile::Update(float& dt) {
	Move(xForward * dt, yForward * dt);
}