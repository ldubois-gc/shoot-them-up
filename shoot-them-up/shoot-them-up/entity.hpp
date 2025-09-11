#pragma once

// class Sprite;

enum class EntityType { PLAYER, ENEMY, OBSTACLE, PROJECTILE };

class Entity
{
public:
	Entity(float x, float y, float h, float w, sf::Color color);
	virtual ~Entity();

	void SetX(float x) { xPos = x; }
	void SetY(float y) { yPos = y; }
	void SetColor(sf::Color newColor) { body.setFillColor(newColor); }
	float GetX() { return xPos; }
	float GetY() { return yPos; }
	float GetHeigth() { return heigth; }
	float GetWidth() { return width; }
	
	void Kill();
	bool Exists();

	virtual void OnCollision(Entity* collidedEntity) = 0;
	virtual EntityType Type() = 0;
	void Draw(sf::RenderWindow &window);
	virtual void Update(float& dt) = 0;

	bool collide;

protected:
	float xPos;
	float yPos;
	float heigth;
	float width;
	bool exists;
	sf::RectangleShape body;

	sf::Vector2f GetDirectionToPoint(float xPoint, float yPoint);
};