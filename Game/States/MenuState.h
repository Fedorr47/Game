#pragma once

#include "BaseState.h"

class MenuState : public BaseState 
{
public:
    void on_create() override;
    void on_destroy() override;

    void activate() override;
    void deactivate() override;
    
    void update() override;
    void render() override;
};