#include "framework.h"
#include "actor.hpp"

Actor::Actor(float x, float y, sf::Color color, float actorSpeed) : Entity(x, y, color) {
	healthPoints = 20.f;
	speed = actorSpeed;
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