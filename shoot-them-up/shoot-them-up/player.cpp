#include "framework.h"
#include "player.hpp"
#include "player_state.hpp"
#include "projectile.hpp"
#include "event_handler.hpp"

Player::Player(EventHandler* inputManager, float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed = 20.f) : : Character(x, y, heigth, width, color, actorSpeed), movement(), hasBeenHit(), stateMachine(*this) {
    playerInput = inputManager;
    xAim = 0.f;
    yAim = -1.f;
    shootCooldown = .16f;
    shootTimer = .16f;
    bleepCooldown = 0.3f;
    bleepTimer = 0.3f;
    stateMachine.ChangeState(&movement);
}

Player::~Player() {

}

void Player::Update(float& dt) {
    sf::Vector2f mousePos = playerInput->GetMouseWorld();
    sf::Vector2f directionToMouse = GetDirectionToPoint(mousePos.x, mousePos.y);
    xAim = directionToMouse.x;
    yAim = directionToMouse.y;

    shootTimer += dt;
    if ((shootTimer >= shootCooldown) && !invicible) {
        Shoot();
        shootTimer = 0.f;
    }

    stateMachine.Update(dt);
    
}

void Player::Shoot() {
    Projectile* bullet = new Projectile(xPos, yPos, xAim, yAim, sf::Color::Blue, gameManager, 500.f);
    gameManager->AddEntity(bullet);
}

void Player::Movement(float& dt) {
    float currentSpeed = speed;
    float dirX = 0.f;
    float dirY = 0.f;

    if (playerInput->IsKeyDown(VK_UP) || playerInput->IsKeyDown(90))
    {
        dirY -= 1.f;
    }
    if (playerInput->IsKeyDown(VK_DOWN) || playerInput->IsKeyDown(83))
    {
        dirY += 1.f;
    }
    if (playerInput->IsKeyDown(VK_RIGHT) || playerInput->IsKeyDown(68))
    {
        dirX += 1.f;
    }
    if (playerInput->IsKeyDown(VK_LEFT) || playerInput->IsKeyDown(81))
    {
        dirX -= 1.f;
    }
    Move(dirX * currentSpeed * dt, dirY * currentSpeed * dt);
}

void Player::Invicibility(float& dt) {
    bleepTimer += dt;
    if (bleepTimer >= bleepCooldown) {
        render.setFillColor(sf::Color::Transparent);
        if (bleepTimer >= bleepCooldown * 2)
        {
            render.setFillColor(sf::Color::Green);
            bleepTimer = 0.0f;
        }
    }
}

void Player::StateChange(State<Player>* newState) {
    stateMachine.ChangeState(newState);
}