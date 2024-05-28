#pragma once

#include "BaseState.h"

class GameState : public BaseState
{
public:
    explicit GameState(int in_state_type) :
        BaseState(in_state_type)
    {}
    
    void on_create() override;
    void on_destroy() override;

    void activate() override;
    void deactivate() override;
    
    void update() override;
    void render() override;

    void handle_input() override;
};

