#include "pch.h"

#include "States/StateManager.h"
#include "States/MenuState.h"
#include "States/GameState.h"


TEST(StateManagerTest, AddState) {
    StateManager* manager = StateManager::get_instance();
    manager->add_state(std::make_unique<MenuState>(0));
    EXPECT_EQ(manager->has_state(0), true);
}


TEST(StateManagerTest, RemoveState) {
    StateManager* manager = StateManager::get_instance();
    manager->add_state(std::make_unique<MenuState>(0));
    manager->remove_state(0);
    EXPECT_EQ(manager->check_current_state(), -1);
}

TEST(StateManagerTest, ChangeState) {
    StateManager* manager = StateManager::get_instance();
    manager->add_state(std::make_unique<MenuState>(0));
    manager->add_state(std::make_unique<GameState>(1));
    manager->change_state(1);
    EXPECT_EQ(manager->check_current_state(), 1);
}

TEST(StateManagerTest, TestCanNotCopyManger) {
    StateManager* manager = StateManager::get_instance();
    StateManager* manager1 = StateManager::get_instance();
    EXPECT_EQ(manager, manager1);
}

