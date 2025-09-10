#include "framework.h"
#include "player.hpp"
#include "event_handler.hpp"

Player::Player(EventHandler* inputManager, float x, float y, float heigth, float width, sf::Color color, float actorSpeed) : Character(x, y, heigth, width, color, actorSpeed) {
    playerInput = inputManager;
}

Player::~Player() {

}

void Player::Update(float& dt) {
    if (playerInput->IsKeyDown(VK_UP)) // || playerInput->IsKeyDown(87) || playerInput->IsKeyDown(90)
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

void Player::Shoot(float& xDir, float& yDir) {

}