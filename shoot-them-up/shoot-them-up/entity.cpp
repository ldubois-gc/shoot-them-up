#include "framework.h"
#include "entity.hpp"

Entity::Entity(float x, float y, float heigth, float width, sf::Color color) {
	xPos = x;
	yPos = y;
	exists = true;
	render.setSize(sf::Vector2f(heigth, width));
	render.setPosition(sf::Vector2f(xPos, yPos));
	render.setFillColor(color);
}

Entity::~Entity() {

}

void Entity::Draw(sf::RenderWindow &window) {
	window.draw(render);
}

void Entity::Update(float& dt) {

}

sf::Vector2f Entity::GetDirectionToPoint(float xPoint, float yPoint) {
	float xDistancePoint = xPoint - xPos;
	float yDistancePoint = yPoint - yPos;

	// 1. Norme
	float norm = sqrt(pow(xDistancePoint, 2) + pow(yDistancePoint, 2));

	// 2. Normalisation
	float distanceX = xDistancePoint / norm;
	float distanceY = yDistancePoint / norm;

	return sf::Vector2f(distanceX, distanceY);
}

void Entity::Kill() {
	exists = false;
}

bool Entity::Exists() {
	return exists;
}