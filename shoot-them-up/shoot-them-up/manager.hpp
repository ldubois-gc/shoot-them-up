#pragma once

class Entity;
class EventHandler;
class Player;

class Manager
{
public:
	Manager();
	~Manager();

	std::vector<Entity*>& GetEntities() { return entities; };
	std::vector<Entity*>& GetNewEntities() { return newEntities; };
	void UpdateManager();

	void AddEntity(Entity* newEntity);
	void RemoveFlaggedEntities();

	void CreatePlayer(EventHandler* input, float xPos, float yPos);
	void CreateEnemy(float xPos, float yPos, float speed);
	void CreateProjectile(float xPos, float yPos, float xDir, float yDir);
	void CreateObstacle(float xPos, float yPos, float height, float width);

	void ProcessCollision(Entity* entity);
	bool CheckCollision(Entity* a, Entity* b);

private:
	Player* player;
	std::vector<Entity*> newEntities;
	std::vector<Entity*> entities;
	void ResetAllCollisions();
};
