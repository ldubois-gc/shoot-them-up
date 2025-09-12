#pragma once

enum class EntityType { PLAYER, ENEMY, OBSTACLE, PROJECTILE, BOMBS };

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void SetX(float x) { xPos = x; }
	void SetY(float y) { yPos = y; }
	void SetColor(sf::Color newColor) { body.setFillColor(newColor); }
	float GetX() { return xPos; }
	float GetY() { return yPos; }
	float GetHeigth() { return height; }
	float GetWidth() { return width; }
	
	void Kill();
	bool Exists();

	virtual void OnCollision(Entity* collidedEntity) = 0;
	virtual EntityType Type() = 0;

	virtual void Init(float x, float y, float h, float w, sf::Color color);
	virtual void Update(float& dt) = 0;
	void Draw(sf::RenderWindow &window);

	bool collide;

protected:
	float xPos;
	float yPos;
	float height;
	float width;
	bool exists;
	sf::RectangleShape body;

	sf::Vector2f GetDirectionToPoint(float xPoint, float yPoint);
};