#pragma once

// class Sprite;

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void SetX(float x) { xPos = x; }
	void SetY(float y) { yPos = y; }
	float GetX() { return xPos; }
	float GetY() { return yPos; }

	void Draw(sf::RenderWindow &window);

protected:
	float xPos;
	float yPos;
	sf::RectangleShape render;
};