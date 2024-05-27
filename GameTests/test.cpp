#include "pch.h"
#include "States/MainState.h"

TEST(MainMenuStateTest, HandleInput) {
  MainMenuState menuState;
  menuState.handle_input();
}

TEST(MainMenuStateTest, Update) {
  MainMenuState menuState;
  menuState.update();
}

TEST(MainMenuStateTest, Render) {
  MainMenuState menuState;
  menuState.render();
}