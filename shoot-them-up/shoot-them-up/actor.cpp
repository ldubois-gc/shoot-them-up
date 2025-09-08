#include "framework.h"
#include "actor.hpp"

Actor::Actor() {

}

Actor::~Actor() {

}

void Actor::Move(float x, float y) {
	xPos += x;
	yPos += y;
	render.setPosition(sf::Vector2f(xPos, yPos));
}