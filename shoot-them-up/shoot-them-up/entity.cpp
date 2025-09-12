#include "framework.h"
#include "entity.hpp"

Entity::Entity() {
	
}

Entity::~Entity() {

}

void Entity::Init(float x, float y, float h, float w, sf::Color color) {
	xPos = x;
	yPos = y;
	height = h;
	width = w;
	exists = true;
	body.setSize(sf::Vector2f(width, height));
	body.setPosition(sf::Vector2f(xPos, yPos));
	body.setFillColor(color);

	collide = false;
	exists = true;
}

void Entity::Draw(sf::RenderWindow &window) {
	window.draw(body);
}

void Entity::Update(float& dt) {

}

void Entity::OnCollision(Entity* collidedEntity) {

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