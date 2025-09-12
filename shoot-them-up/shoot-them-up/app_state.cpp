#include "framework.h"
#include "app_state.hpp"
#include "player.hpp"
#include "app.hpp"
#include "manager.hpp"
#include "event_handler.hpp"

void AppInGame::Enter(App& app) {
	Manager* appManager = app.GetManager();
	appManager->ClearEntities();
	app.GameStart();
}

void AppInGame::Update(App& app, float dt) {
	Manager* appManager = app.GetManager();
	Player* player = appManager->GetPlayer();
	app.GameUpdate(dt);

	if (!player->Exists() || appManager->GetNumberOfFoes() <= 0)
	{
		app.StateChange(&app.gameOver);
	}
}

void AppGameOver::Enter(App& app) {
	Manager* appManager = app.GetManager();
	appManager->ClearEntities();
	app.GameOverStart();
}

void AppGameOver::Update(App& app, float dt) {
	EventHandler* appInput = app.GetInput();
	app.GameOverUpdate(dt);
}