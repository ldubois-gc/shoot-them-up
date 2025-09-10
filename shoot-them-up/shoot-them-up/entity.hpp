#pragma once

// class Sprite;

class Entity
{
public:
	Entity(float x, float y, sf::Color color);
	virtual ~Entity();

	void SetX(float x) { xPos = x; }
	void SetY(float y) { yPos = y; }
	float GetX() { return xPos; }
	float GetY() { return yPos; }

	void Draw(sf::RenderWindow &window);
	virtual void Update(float& dt) = 0;

protected:
	float xPos;
	float yPos;
	bool exists;
	sf::RectangleShape render;
};