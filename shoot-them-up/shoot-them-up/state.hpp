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
    void ChangeState(State<EntityType>* newState, EntityType& entity) {
        if (state) {
            state->Exit(entity);
        }
        state = *newState;
        if (state) {
            state->Enter(entity);
        }
    }

    void Update(EntityType& entity, float dt) {
        if (state) state->Update(entity, dt);
    }

private:
    State<EntityType>* state;
};