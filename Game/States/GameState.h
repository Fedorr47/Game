#pragma once

#include "IState.h"

class GameState : public IState
{
public:
    virtual void handle_input() override;
    virtual void update() override;
    virtual void render() override;
};