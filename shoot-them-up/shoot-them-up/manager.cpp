#include "framework.h"
#include "manager.hpp"
#include "entity.hpp"

float gameClock;

Manager::Manager() {}

Manager::~Manager() {}

void Manager::UpdateManager() {
	RemoveFlaggedEntities();
	for (Entity* entity : newEntities) {
		entities.push_back(entity);
	}
	newEntities.clear();
}

void Manager::AddEntity(Entity* newEntity) {
	newEntities.push_back(newEntity);
}

void Manager::RemoveFlaggedEntities() {
	entities.erase(
		std::remove_if(
			entities.begin(), 
			entities.end(), 
			[](Entity* e) { return !e->Exists(); }), 
		entities.end()
	);
}