#include "framework.h"
#include "event_handler.hpp"

EventHandler::EventHandler() {

}

EventHandler::~EventHandler() {

}

bool EventHandler::IsKeyDown(int keyCode) {
	return (GetAsyncKeyState(keyCode) & 0x8000) != 0;
}