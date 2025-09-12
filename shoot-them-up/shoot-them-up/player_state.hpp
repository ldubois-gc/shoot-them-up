#pragma once

#include "state.hpp"

class Player;

class PlayerMoving : public State<Player> {
public:
	//void Enter(Player& player);
	void Update(Player& player, float dt) override;
	//void Exit(Player& player);
};

class PlayerHit: public State<Player> {
public:
	//void Enter(Player& player);
	void Update(Player& player, float dt) override;
	//void Exit(Player& player);
private:
	float timer;
};

class PlayerDashing : public State<Player> {
public:
	//void Enter(Player& player);
	void Update(Player& player, float dt) override;
	//void Exit(Player& player);
private:
	float timer;
};

class PlayerDying: public State<Player> {
public:
	//void Enter(Player& player) override;
	void Update(Player& player, float dt) override;
	//void Exit(Player& player) override;
};