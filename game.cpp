#include "game.h"

#include <GLFW/glfw3.h>
#include <chrono>
#include <iostream>

Game::Game()
{
    //TODO:handle glfw events myself
    init_glfw();

    mScreen = new nanogui::Screen{{1280, 720}, "Editor", {}, true};
    mMenu = new Menu(*mScreen);
}
Game::~Game() {
    delete mMenu;
    delete mScreen;
}

void Game::run()
{
    //set the initial time
    prevUpdateTimeInMills = std::chrono::high_resolution_clock::now();

    mScreen->performLayout();

    mScreen->drawAll();
    mScreen->setVisible(true);

    //start the main game loop
    game_loop();

    glfwTerminate();
}

void Game::game_loop()
{
    if (mainloop_active)
        throw std::runtime_error("Main loop is already running!");

    mainloop_active = true;

    try {
        while (mainloop_active) {

            auto timeNow = std::chrono::high_resolution_clock::now();

            double deltaTime = std::chrono::duration<double, std::milli>(prevUpdateTimeInMills-timeNow).count();

            nanogui::Screen *screen = mScreen;
            if (!screen->visible()) {
                continue;
            } else if (glfwWindowShouldClose(screen->glfwWindow())) {
                screen->setVisible(false);
                continue;
            }

            //nanogui draw
            screen->drawAll();

            //main update
            update(deltaTime);

            /* Wait for mouse/keyboard or empty refresh events */
            glfwWaitEvents();
        }

        /* Process events once more */
        glfwPollEvents();
    } catch (const std::exception &e) {
        std::cerr << "Caught exception in main loop: " << e.what() << std::endl;
        mainloop_active = false;
    }
}


void Game::init_glfw()
{
    #if !defined(_WIN32)
        /* Avoid locale-related number parsing issues */
        setlocale(LC_NUMERIC, "C");
    #endif

    glfwSetErrorCallback(
        [](int error, const char *descr) {
            if (error == GLFW_NOT_INITIALIZED)
                return; /* Ignore */
            std::cerr << "GLFW error " << error << ": " << descr << std::endl;
        }
    );

    if (!glfwInit())
        throw std::runtime_error("Could not initialize GLFW!");

    glfwSetTime(0);
}

void Game::update(double timeDelta)
{

}
