#include "pch.h"

import StateManager;
#include "States/MenuState.h"
#include "States/GameState.h"


TEST(StateManagerTest, AddState) {
    StateManager manager;
    manager.add_state(std::make_unique<MenuState>(0));
    EXPECT_EQ(manager.has_state(0), true);
}


TEST(StateManagerTest, RemoveState) {
    StateManager manager;
    manager.add_state(std::make_unique<MenuState>(0));
    manager.remove_state(0);
    EXPECT_EQ(manager.check_current_state(), -1);
}

TEST(StateManagerTest, ChangeState) {
    StateManager manager;
    manager.add_state(std::make_unique<MenuState>(0));
    manager.add_state(std::make_unique<GameState>(1));
    manager.change_state(1);
    EXPECT_EQ(manager.check_current_state(), 1);
}

TEST(StateManagerTest, TestCopyManger) {
    StateManager manager;
    manager.add_state(std::make_unique<MenuState>(0));
    manager.add_state(std::make_unique<GameState>(1));
    manager.change_state(1);
    EXPECT_EQ(manager.check_current_state(), 1);
}

