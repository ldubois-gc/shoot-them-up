#include "framework.h"
#include "player.hpp"
#include "player_state.hpp"
#include "projectile.hpp"
#include "event_handler.hpp"
#include "manager.hpp"

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
    bleepCooldown = 0.2f;
    bleepTimer = 0.2f;
    stateMachine.ChangeState(&movement);
    healthPoints = 5;
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
    if (healthPoints <= 0) {
        StateChange(&dying);
    }

    stateMachine.Update(dt);   
}

void Player::OnCollision(Entity* collidedEntity) {
    if (collidedEntity->Type() == EntityType::OBSTACLE) {
        PushBack(collidedEntity);
    }
    if (((collidedEntity->Type() == EntityType::ENEMY || (collidedEntity->Type() == EntityType::PROJECTILE) && static_cast<Projectile*>(collidedEntity)->GetShooter() != this) && !invicible)) {
        PushBack(collidedEntity);
        invicible = true;
        healthPoints -= 1;
        StateChange(&hasBeenHit);
    }
}

void Player::Shoot() {
    gameManager->CreateProjectile(xPos, yPos, xAim, yAim, 600.0f, static_cast<Character*>(this));
}

void Player::Movement(float& dt) {
    float currentSpeed = speed;
    if (invicible)
    {
        currentSpeed *= 1.2f;
    }
    dirX = 0.f;
    dirY = 0.f;

    if (playerInput->IsKeyDown(VK_UP) || playerInput->IsKeyDown('Z'))
    {
        dirY -= 1.f;
    }
    if (playerInput->IsKeyDown(VK_DOWN) || playerInput->IsKeyDown('S'))
    {
        dirY += 1.f;
    }
    if (playerInput->IsKeyDown(VK_RIGHT) || playerInput->IsKeyDown('D'))
    {
        dirX += 1.f;
    }
    if (playerInput->IsKeyDown(VK_LEFT) || playerInput->IsKeyDown('Q'))
    {
        dirX -= 1.f;
    }

    if (playerInput->IsKeyDown('E') && !invicible)
    {
        stateMachine.ChangeState(&dashing);
    }

    float length = std::sqrt(dirX * dirX + dirY * dirY);
    if (length != 0.f) {
        dirX /= length;
        dirY /= length;
    }

    float xMove = dirX * currentSpeed * dt;
    float yMove = dirY * currentSpeed * dt;

    Move(xMove, yMove);
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

void Player::Dash(float& dt) {

}

void Player::StateChange(State<Player>* newState) {
    stateMachine.ChangeState(newState);
}