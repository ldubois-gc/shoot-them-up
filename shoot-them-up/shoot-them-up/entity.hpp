#pragma once

// class Sprite;

class Entity
{
public:
	Entity(float x, float y, float heigth, float width, sf::Color color);
	virtual ~Entity();

	void SetX(float x) { xPos = x; }
	void SetY(float y) { yPos = y; }
	void SetColor(sf::Color newColor) { render.setFillColor(newColor); }
	float GetX() { return xPos; }
	float GetY() { return yPos; }
	
	void Kill();
	bool Exists();

	void Draw(sf::RenderWindow &window);
	virtual void Update(float& dt) = 0;

protected:
	float xPos;
	float yPos;
	bool exists;
	sf::RectangleShape render;

	sf::Vector2f GetDirectionToPoint(float xPoint, float yPoint);
};