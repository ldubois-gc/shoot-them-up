#include "framework.h"
#include "actor.hpp"

Actor::Actor() {
	healthPoints = 20.f;
	speed = 20.f;
}

Actor::~Actor() {

}

void Actor::Move(float x, float y) {
	xPos += speed * x;
	yPos += speed * y;
	render.setPosition(sf::Vector2f(xPos, yPos));
}

void Actor::Update(float& dt) {

}