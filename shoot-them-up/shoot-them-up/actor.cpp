#include "framework.h"
#include "actor.hpp"


Actor::Actor(float x, float y, float heigth, float width, sf::Color color, float actorSpeed) : Entity(x, y, heigth, width, color) {
	speed = actorSpeed;
}

Actor::~Actor() {

}

void Actor::Move(float x, float y) {
	xPos += x;
	yPos += y;
	body.setPosition(sf::Vector2f(xPos, yPos));
}

void Actor::PushBack(Entity* otherEntity) {
	float entityRight = otherEntity->GetX() + otherEntity->GetWidth();
	float selfRight = xPos + width;
	float entityBottom = otherEntity->GetY() + otherEntity->GetHeigth();
	float selfBottom = yPos + heigth;

	float overlapX1 = entityRight - xPos;   // push right
	float overlapX2 = selfRight - otherEntity->GetX();   // push left
	float overlapY1 = entityBottom - yPos;   // push down
	float overlapY2 = selfBottom - otherEntity->GetY();   // push up

	float minX = abs(overlapX1) < abs(overlapX2) ? overlapX1 : overlapX2;
	float minY = abs(overlapY1) < abs(overlapY2) ? overlapY1 : overlapY2;
	
	correctionX = (overlapX1 < overlapX2) ? overlapX1 : -overlapX2;
	correctionY = (overlapY1 < overlapY2) ? overlapY1 : -overlapY2;
}

void Actor::Update(float& dt) {

}

void Actor::OnCollision(Entity* collidedEntity) {

}