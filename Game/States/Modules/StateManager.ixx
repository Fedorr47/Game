export module StateManager;

import <unordered_map>;
import <memory>;
import <optional>;
import InterfaceState;
import InterfaceStateManager;

using StatesHolder = std::unordered_map<int32_t, std::unique_ptr<IState>>;

export constexpr int32_t INVALID_STATE = -1;

export class StateManager final : public IStateManager
{
public:
    void add_state(std::unique_ptr<IState> state) override;
    void remove_state(int32_t in_state_type) override;
    void change_state(int32_t in_state_type) override;
    std::optional<IState*> get_current_state() override;
    bool has_state(int32_t in_state_type) override;
    void handle_input() override;
    void update() override;
    void render() override;
    
private:
    int32_t current_state_{INVALID_STATE};
    StatesHolder states_;
};
