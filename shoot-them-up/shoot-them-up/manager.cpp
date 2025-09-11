#include "framework.h"
#include "manager.hpp"
#include "entity.hpp"

float gameClock;

Manager::Manager() {}

Manager::~Manager() {}

void Manager::ProcessCollision() {
    ResetAllColisions();

    for (Entity* entity : entities) {
        
    }

    /*this.position.x < other.position.x + other.width &&
    this.position.x + this.width > other.position.x&&
    this.position.y < other.position.y + other.height &&
    this.position.y + this.height > other.position.y*/
}

void Manager::ResetAllColisions() {
    for (Entity* entity : entities) {
        if (Actor* actor = dynamic_cast<Actor*>(entity)) {
            actor->colideUp = false;
            actor->colideRigth = false;
            actor->colideDown = false;
            actor->colideLeft = false;
        }
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