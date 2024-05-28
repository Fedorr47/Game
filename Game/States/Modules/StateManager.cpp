module StateManager;
import <optional>;

void StateManager::add_state(std::unique_ptr<IState> state)
{
    auto insert_pair = states_.try_emplace(state->get_state_type() ,std::move(state));
}

void StateManager::remove_state(int32_t in_state_type)
{
    std::erase_if ( 
         states_,
         [in_state_type](const auto& state)
         {
             auto const& [state_key, state_val] = state;
             return (state_key == in_state_type);
         });
    if (states_.empty())
    {
        current_state_ = INVALID_STATE;
    }
}

void StateManager::change_state(int32_t in_state_type)
{
    if (states_.contains(in_state_type))
    {
        current_state_ = in_state_type;
    }
}

std::optional<IState*> StateManager::get_current_state()
{
    if (states_.contains(current_state_))
    {
        return std::optional<IState*>{states_.at(current_state_).get()};
    }
    return {};
}

bool StateManager::has_state(int32_t in_state_type)
{
    return states_.contains(in_state_type);
}

void StateManager::handle_input()
{
    if (IState* state = get_current_state().value())
    {
        state->handle_input();
    }
}

void StateManager::update()
{
    if (IState* state = get_current_state().value())
    {
        state->handle_input();
    }
}

void StateManager::render()
{
    if (IState* state = get_current_state().value())
    {
        state->handle_input();
    }
}

