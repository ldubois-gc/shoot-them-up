#pragma once

class Entity;

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

	//template<typename T, typename... Args>
	//T* Spawn(Args... args);

	/*template <typename T, typename... Args>
	T* Spawn(Args... args) {
		T* obj = new T(args...);
		newEntities.push_back(obj);
		return obj;
	}*/

	void ProcessCollision(Entity* entity);
	bool CheckCollision(Entity* a, Entity* b);

private:
	std::vector<Entity*> newEntities;
	std::vector<Entity*> entities;
	void ResetAllCollisions();
};
