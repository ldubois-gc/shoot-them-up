#include "framework.h"
#include "event_handler.hpp"

EventHandler::EventHandler() {

}

EventHandler::~EventHandler() {

}

void EventHandler::InitWindow(sf::RenderWindow* gameWindow) {
	window = gameWindow;
}

bool EventHandler::IsKeyDown(int keyCode) {
	// return (GetAsyncKeyState(keyCode) & 0x8000) != 0;
	return keys[keyCode];
}

void EventHandler::UpdateEvents() {
	for (int i = 0; i < 255; i++) {
		if ((GetAsyncKeyState(i) & 0x8000) != 0) {
			keys[i] = true;
		}
		else {
			keys[i] = false;
		}
	}
	sf::Vector2i mousePixel = sf::Mouse::getPosition(*window); // window relative
	mouseWorld = window->mapPixelToCoords(mousePixel); // convert to world
}