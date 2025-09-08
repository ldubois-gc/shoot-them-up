#include "framework.h"
#include "event_handler.hpp"

int EventHandler::PressedKey() {
	for (int keyCode = 0; keyCode < 256; keyCode++) {
		if (GetAsyncKeyState(keyCode)) {
			return keyCode;
		}
	}
}