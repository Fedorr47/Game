export module StateManager;

import <unordered_map>;
import <memory>;
import <optional>;
import InterfaceState;
import InterfaceStateManager;

using StatesHolder = std::unordered_map<int, std::unique_ptr<IState>>;

export class StateManager final : public IStateManager
{
public:
    // Interface's methods
    void add_state(std::unique_ptr<IState> state) override;
    void remove_state(int in_state_type) override;
    void change_state(int in_state_type) override;
    bool has_state(int in_state_type) override;
    void handle_input() override;
    void update() override;
    void render() override;

    // Public methods
    int check_current_state() const { return current_state_; }
    
private:
    int current_state_{INVALID_STATE};
    StatesHolder states_;
};
