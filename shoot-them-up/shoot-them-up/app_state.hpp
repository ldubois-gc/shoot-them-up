#pragma once

#include "app.hpp"
#include "state.hpp"

class AppGameOver : State<App> {
	void Update(App& app, float dt) override;
};