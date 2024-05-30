export module InterfaceStateManager;

import InterfaceState;
import <memory>;

export class IStateManager
{
public:
    IStateManager(const IStateManager& other) = delete;
    IStateManager(IStateManager&& other) = delete;
    IStateManager& operator=(const IStateManager& other) = delete;
    IStateManager& operator=(IStateManager&& other) = delete;

    IStateManager() = default;
    virtual ~IStateManager() = default;

    virtual void add_state(std::unique_ptr<IState> state) = 0;
    virtual void remove_state(int in_state_type) = 0;
    virtual void change_state(int in_state_type) = 0;
    virtual bool has_state(int in_state_type) = 0;
    virtual void handle_input() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};