#include "framework.h"
#include "entity.hpp"

Entity::Entity(float x, float y, float heigth, float width, sf::Color color) {
	xPos = x;
	yPos = y;
	exists = true;
	render.setSize(sf::Vector2f(heigth, width));
	render.setPosition(sf::Vector2f(xPos, yPos));
	render.setFillColor(color);
	exists = true;
}

Entity::~Entity() {

}

void Entity::Draw(sf::RenderWindow &window) {
	window.draw(render);
}

void Entity::Update(float& dt) {

}

void Entity::Kill() {
	exists = false;
}

bool Entity::Exists() {
	return exists;
}

sf::Vector2f Entity::GetDirectionToPoint(float xPoint, float yPoint) {
	float xDistanceWithPoint = xPoint - xPos;
	float yDistanceWithPoint = yPoint - yPos;

	float norm = sqrt(pow(xDistanceWithPoint, 2) + pow(yDistanceWithPoint, 2));

	float xDirection = xDistanceWithPoint / norm;
	float yDirection = yDistanceWithPoint / norm;

	return sf::Vector2f(xDirection, yDirection);
}