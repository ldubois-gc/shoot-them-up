#pragma once

//#include "app.hpp"
#include "state.hpp"

class App;

class AppInGame : public State<App> {
	void Enter(App& app) override;
	void Update(App& app, float dt) override;
};

class AppGameOver : public State<App> {
	void Enter(App& app) override;
	void Update(App& app, float dt) override;
};