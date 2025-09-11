#include "framework.h"
#include "manager.hpp"
#include "entity.hpp"

float gameClock;

Manager::Manager() {}

Manager::~Manager() {}

void Manager::ProcessCollision(Entity* entity) {
    ResetAllCollisions();

	for (Entity* otherEntity : entities) {
		if (entity != otherEntity && CheckCollision(entity, otherEntity)) {
			entity->OnCollision(otherEntity);
			otherEntity->OnCollision(entity);
		}
	}
    /*for (Entity* entity : entities) {
        for (Entity* otherEntity : entities) {
            if (entity != otherEntity && CheckCollision(entity, otherEntity)) {
				entity->OnCollision();
				otherEntity->OnCollision();
            }
        }
    }*/
}

bool Manager::CheckCollision(Entity* a, Entity* b) {
	return  a->GetX() < b->GetX() + b->GetWidth() &&
			a->GetX() + a->GetWidth() > b->GetX() &&
			a->GetY() < b->GetY() + b->GetHeigth() &&
			a->GetY() + a->GetHeigth() > b->GetY();
}

void Manager::ResetAllCollisions() {
    for (Entity* entity : entities) {
        entity->collide = false;
    }
}

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