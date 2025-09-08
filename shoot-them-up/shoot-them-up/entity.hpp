#pragma once

class Sprite;

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void SetX(float x) { xPos = x; }
	void SetY(float y) { yPos = y; }
	float GetX() { return xPos; }
	float GetY() { return yPos; }

private:
	float xPos;
	float yPos;
	Sprite render;
};