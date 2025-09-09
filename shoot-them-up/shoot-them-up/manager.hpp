#pragma once

class Entity;

class Manager
{
public:
	Manager();
	~Manager();

	std::vector<Entity*>& GetEntities() { return entities; };

	void AddEntity(Entity& newEntity);

private:
	std::vector<Entity*> entities;
};
