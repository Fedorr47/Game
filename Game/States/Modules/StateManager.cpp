module StateManager;

StateManager* StateManager::pinstance_{ nullptr };
std::mutex StateManager::mutex_;

StateManager* StateManager::get_instance()
{
    if (pinstance_ == nullptr)
    {
        pinstance_ = new StateManager();
    }
    return pinstance_;
}

void StateManager::add_state(std::unique_ptr<IState> state)
{
    auto insert_pair = states_.try_emplace(state->get_state_type(), std::move(state));
}

void StateManager::remove_state(int in_state_type)
{
    //std::erase_if ( 
    //     states_,
    //     [in_state_type](const auto& state)
    //     {
    //         auto const& [state_key, state_val] = state;
    //         return (state_key == in_state_type);
    //     });
    //if (states_.empty())
    //{
    //    current_state_ = INVALID_STATE;
    //}
}

bool StateManager::has_state(int in_state_type)
{
    //return states_.contains(in_state_type);
    return false;
}


void StateManager::change_state(int in_state_type)
{
    //if (has_state(in_state_type))
    //{
    //    current_state_ = in_state_type;
    //}
}

void StateManager::handle_input()
{
    //if (has_state(current_state_))
    //{
    //    std::unique_ptr<IState>& state = states_[current_state_];
    //    state->handle_input();
    //}
}

void StateManager::update()
{
    //if (has_state(current_state_))
    //{
    //    std::unique_ptr<IState>& state = states_[current_state_];
    //    state->handle_input();
    //}
}

void StateManager::render()
{
    //if (has_state(current_state_))
    //{
    //    std::unique_ptr<IState>& state = states_[current_state_];
    //    state->handle_input();
    //}
}

