#include "framework.h"
#include "actor.hpp"

Actor::Actor() {

}

Actor::~Actor() {

}

void Actor::Init(float x, float y, float height, float width, sf::Color color, float actorSpeed) {
	Entity::Init(x, y, height, width, color);
	speed = actorSpeed;
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
	float selfBottom = yPos + height;

	float overlapX1 = entityRight - xPos;   // push right
	float overlapX2 = selfRight - otherEntity->GetX();   // push left
	float overlapY1 = entityBottom - yPos;   // push down
	float overlapY2 = selfBottom - otherEntity->GetY();   // push up
	
	float correctionX = (overlapX1 < overlapX2) ? overlapX1 : -overlapX2;
	float correctionY = (overlapY1 < overlapY2) ? overlapY1 : -overlapY2;

	if (std::abs(correctionX) < std::abs(correctionY)) {
		xPos += correctionX;
	} else {
		yPos += correctionY;
	}
	body.setPosition(sf::Vector2f(xPos, yPos));
}

void Actor::Update(float& dt) {

}

void Actor::OnCollision(Entity* collidedEntity) {

}