#pragma once

import InterfaceState;

class BaseState : public IState
{
public:

    explicit BaseState(int in_state_type) :
        state_type_{in_state_type}
    {}
    
    void on_create() override;
    void on_destroy() override;

    void activate() override;
    void deactivate() override;
    
    void update() override;
    void render() override;

    void handle_input() override;
    
    int get_state_type() const { return state_type_; }
    
protected:
    int state_type_{-1};
};
