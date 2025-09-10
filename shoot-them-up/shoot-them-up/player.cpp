#include "framework.h"
#include "player.hpp"
#include "projectile.hpp"
#include "event_handler.hpp"

Player::Player(EventHandler* inputManager, float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed = 20.f) : : Character(x, y, heigth, width, color, actorSpeed) {
    playerInput = inputManager;
    xAim = 0.f;
    yAim = -1.f;
    shootCooldown = .16f;
    shootTimer = .16f;
}

Player::~Player() {

}

void Player::Update(float& dt) {
    sf::Vector2f mousePos = playerInput->GetMouseWorld();
    sf::Vector2f directionToMouse = GetDirectionToPoint(mousePos.x, mousePos.y);
    xAim = directionToMouse.x;
    yAim = directionToMouse.y;
    
    float currentSpeed = speed;
    shootTimer += dt;

    if (playerInput->IsKeyDown(VK_SPACE)) {
        currentSpeed *= 0.5;
    }
    if (playerInput->IsKeyDown(VK_UP) || playerInput->IsKeyDown(90)) // || playerInput->IsKeyDown(87) || playerInput->IsKeyDown(90)
    {
        Move(0.0f, -currentSpeed * dt);
    }
    if (playerInput->IsKeyDown(VK_DOWN) || playerInput->IsKeyDown(83))
    {
        Move(0.0f, currentSpeed * dt);
    }
    if (playerInput->IsKeyDown(VK_RIGHT) || playerInput->IsKeyDown(68))
    {
        Move(currentSpeed * dt, 0.0f);
    }
    if (playerInput->IsKeyDown(VK_LEFT) || playerInput->IsKeyDown(81))
    {
        Move(-currentSpeed * dt, 0.0f);
    }
    
    if (shootTimer >= shootCooldown) {
        Shoot();
        shootTimer = 0.f;
    }
}

void Player::Shoot() {
    //gameManager->Spawn<Projectile>(xPos, yPos, xDir, yDir, sf::Color::Blue, 40.f);
    Projectile* bullet = new Projectile(xPos, yPos, xAim, yAim, sf::Color::Blue, gameManager, 500.f);
    gameManager->AddEntity(bullet);
}