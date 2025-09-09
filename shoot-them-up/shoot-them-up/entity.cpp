#include "framework.h"
#include "entity.hpp"

Entity::Entity() {
	xPos = 500.0f;
	yPos = 500.0f;
	render.setSize(sf::Vector2f(10.0f, 10.0f));
	render.setPosition(sf::Vector2f(xPos, yPos));
	render.setFillColor(sf::Color::Green);
}

Entity::~Entity() {

}

void Entity::Draw(sf::RenderWindow &window) {
	window.draw(render);
}

void Entity::Update(float& dt) {

}