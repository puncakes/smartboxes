#include "game.h"

#include <memory>

Game::Game()
{
    nanogui::init();
    mScreen = new nanogui::Screen{{1280, 720}, "Editor", {}, true};
    mMenu = new Menu(*mScreen);
}
Game::~Game() {
    delete mMenu;
    delete mScreen;
}

void Game::run()
{
    mScreen->performLayout();

    mScreen->drawAll();
    mScreen->setVisible(true);

    nanogui::mainloop();

    nanogui::shutdown();
}
