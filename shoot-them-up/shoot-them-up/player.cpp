#include "framework.h"
#include "player.hpp"
#include "player_state.hpp"
#include "projectile.hpp"
#include "event_handler.hpp"
#include "manager.hpp"

//Player::Player(EventHandler* inputManager, float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed = 20.f) : Character(x, y, heigth, width, color, manager, actorSpeed), movement(), hasBeenHit(), stateMachine(*this) {
//    playerInput = inputManager;
//    xAim = 0.f;
//    yAim = -1.f;
//    shootCooldown = .16f;
//    shootTimer = .16f;
//    bleepCooldown = 0.3f;
//    bleepTimer = 0.3f;
//    stateMachine.ChangeState(&movement);
//    correctionX = 0;
//    correctionY = 0;
//}

Player::Player() : stateMachine(*this) {

}

Player::~Player() {

}

void Player::Init(EventHandler* inputManager, float x, float y, float height, float width, sf::Color color, Manager* manager, float actorSpeed) {
    Character::Init(x, y, height, width, color, manager, actorSpeed);
    playerInput = inputManager;
    xAim = 0.f;
    yAim = -1.f;
    shootCooldown = .16f;
    shootTimer = .16f;
    bleepCooldown = 0.3f;
    bleepTimer = 0.3f;
    stateMachine.ChangeState(&movement);
    correctionX = 0;
    correctionY = 0;
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

void Player::OnCollision(Entity* collidedEntity) {
    if (collidedEntity->Type() == EntityType::OBSTACLE) {
        PushBack(collidedEntity);
    }
    if (collidedEntity->Type() == EntityType::ENEMY && !invicible) {
        PushBack(collidedEntity);
    }
    if ((collidedEntity->Type() == EntityType::ENEMY || collidedEntity->Type() == EntityType::PROJECTILE) && !invicible) {
        invicible = true;
        StateChange(&hasBeenHit);
        healthPoints -= 1;
    }
}

void Player::Shoot() {
    gameManager->CreateProjectile(xPos, yPos, xAim, yAim);
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

    float xMove = dirX * currentSpeed * dt + correctionX;
    float yMove = dirY * currentSpeed * dt + correctionY;

    Move(xMove, yMove);

    correctionX = 0;
    correctionY = 0;
}

void Player::Invicibility(float& dt) {
    bleepTimer += dt;
    if (bleepTimer >= bleepCooldown) {
        body.setFillColor(sf::Color::Transparent);
        if (bleepTimer >= bleepCooldown * 2)
        {
            body.setFillColor(sf::Color::Green);
            bleepTimer = 0.0f;
        }
    }
}

void Player::StateChange(State<Player>* newState) {
    stateMachine.ChangeState(newState);
}