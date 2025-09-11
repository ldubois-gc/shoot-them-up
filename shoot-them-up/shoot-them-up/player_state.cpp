#include "framework.h"
#include "player_state.hpp"
#include "player.hpp"
#include "event_handler.hpp"

void PlayerMoving::Update(Player& player, float dt) {
    EventHandler* playerEvent = player.GetPlayerInput();
    player.Movement(dt);

    if (playerEvent->IsKeyDown(69)) // || playerInput->IsKeyDown(87) || playerInput->IsKeyDown(90)
    {
        player.SetInvicibility(true);
        player.StateChange(&player.hasBeenHit);
    }
}

void PlayerHit::Update(Player& player, float dt) {
    EventHandler* playerEvent = player.GetPlayerInput();
    player.Invicibility(dt);


    if (playerEvent->IsKeyDown(69)) // || playerInput->IsKeyDown(87) || playerInput->IsKeyDown(90)
    {
        player.SetInvicibility(false);
        player.SetColor(sf::Color::Green);
        player.StateChange(&player.movement);
    }
}