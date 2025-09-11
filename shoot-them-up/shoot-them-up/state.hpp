#pragma once

template <typename EntityType>
class State {
public:
    virtual ~State() = default;
    virtual void Enter(EntityType& entity) {}
    virtual void Update(EntityType& entity, float dt) = 0;
    virtual void Exit(EntityType& entity) {}
};

template <typename EntityType>
class StateMachine {
public:
    StateMachine(EntityType& newOwner) : owner(newOwner) {}

    void ChangeState(State<EntityType>* newState) {
        if (state) {
            state->Exit(owner);
        }
        state = newState;
        if (state) {
            state->Enter(owner);
        }
    }

    void Update(float dt) {
        if (state) state->Update(owner, dt);
    }

private:
    EntityType& owner;
    State<EntityType>* state;
};