#include "framework.h"
#include "entity.hpp"

Entity::Entity(float x, float y, sf::Color color) {
	xPos = x;
	yPos = y;
	exists = true;
	render.setSize(sf::Vector2f(10.0f, 10.0f));
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