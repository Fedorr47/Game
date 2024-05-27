#pragma once

class IState
{
public:
    IState(const IState& other) = delete;
    IState(IState&& other) = delete;
    IState& operator=(const IState& other) = delete;
    IState& operator=(IState&& other) = delete;

    IState() = default;
    virtual ~IState() = default;
    virtual void handle_input() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};
