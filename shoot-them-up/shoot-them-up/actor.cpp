#include "framework.h"
#include "actor.hpp"

Actor::Actor(float x, float y, sf::Color color, float actorSpeed) : Entity(x, y, color) {
	speed = actorSpeed;
}

Actor::~Actor() {

}

void Actor::Move(float x, float y) {
	xPos += x;
	yPos += y;
	render.setPosition(sf::Vector2f(xPos, yPos));
}

void Actor::Update(float& dt) {

}