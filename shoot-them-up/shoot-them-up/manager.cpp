#include "framework.h"
#include "manager.hpp"

float gameClock;

Manager::Manager() {}

Manager::~Manager() {}

void Manager::AddEntity(Entity& newEntity) {
	entities.push_back(&newEntity);
}