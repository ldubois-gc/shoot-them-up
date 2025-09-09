#include "framework.h"
#include "player.hpp"
#include "event_handler.hpp"

Player::Player(EventHandler* inputManager) {
    playerInput = inputManager;
}

Player::~Player() {

}

void Player::Update(float& dt) {
    if (playerInput->IsKeyDown(VK_UP))
    {
        Move(0.0f, -speed * dt);
    }
    if (playerInput->IsKeyDown(VK_DOWN))
    {
        Move(0.0f, speed * dt);
    }
    if (playerInput->IsKeyDown(VK_RIGHT))
    {
        Move(speed * dt, 0.0f);
    }
    if (playerInput->IsKeyDown(VK_LEFT))
    {
        Move(-speed * dt, 0.0f);
    }
}
//void Player::ProcessInput() {
//    if (playerInput->IsKeyDown(VK_UP))
//    {
//        Move(0.0f, -speed * clock.GetDeltaTime());
//    }
//    if (playerInput->IsKeyDown(VK_DOWN))
//    {
//        Move(0.0f, speed * clock.GetDeltaTime());
//    }
//    if (playerInput->IsKeyDown(VK_RIGHT))
//    {
//        Move(speed * clock.GetDeltaTime(), 0.0f);
//    }
//    if (playerInput->IsKeyDown(VK_LEFT))
//    {
//        Move(-speed * clock.GetDeltaTime(), 0.0f);
//    }
//}