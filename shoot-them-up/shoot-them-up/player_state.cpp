#include "framework.h"
#include "player_state.hpp"
#include "player.hpp"
#include "event_handler.hpp"

void PlayerMoving::Update(Player& player, float dt) {
    EventHandler* playerEvent = player.GetPlayerInput();
    player.Movement(dt);
}

void PlayerHit::Update(Player& player, float dt) {
    EventHandler* playerEvent = player.GetPlayerInput();

    timer += dt;
    player.Invicibility(dt);
    player.Movement(dt);

    if (timer >= (dt * 200)) {
        player.SetInvicibility(false);
        player.SetColor(sf::Color::Green);
        timer = 0.0f;
        player.StateChange(&player.movement);
    }
}