#pragma once

class Entity;

class Manager
{
public:
	Manager();
	~Manager();

private:
	std::vector<Entity*> entities;
};
