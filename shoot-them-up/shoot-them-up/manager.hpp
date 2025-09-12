#pragma once

class Entity;
class EventHandler;
class Player;
class Obstacle;
class Character;

class Manager
{
public:
	Manager();
	~Manager();

	Player* GetPlayer() { return player; }
	std::vector<Entity*>& GetEntities() { return entities; }
	std::vector<Entity*>& GetNewEntities() { return newEntities; }
	std::vector<Obstacle*>& GetObstacles() { return obstacles; }
	void UpdateManager();

	void AddEntity(Entity* newEntity);
	void RemoveFlaggedEntities();
	void ClearEntities();

	void CreatePlayer(EventHandler* input, float xPos, float yPos);
	void CreateEnemy(float xPos, float yPos, float speed);
	void CreateProjectile(float xPos, float yPos, float xDir, float yDir, float bulletSpeed, Character* shooter);
	void CreateObstacle(float xPos, float yPos, float height, float width);

	void ProcessCollision(Entity* entity);
	bool CheckCollision(Entity* a, Entity* b);

private:
	Player* player;
	std::vector<Entity*> newEntities;
	std::vector<Entity*> entities;
	std::vector<Obstacle*> obstacles;
	void ResetAllCollisions();
};
