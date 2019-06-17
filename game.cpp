#include "game.h"
#include "physicshelper.h"

#include <GLFW/glfw3.h>
#include <chrono>
#include <iostream>
#include <memory>

Game::Game()
{
    //start up opengl
    init_glfw();

    //TODO:create input manager for glfw input events

    mScreen = new nanogui::Screen{{1280, 720}, "Editor", {}, true};
    mMenu = new Menu(*mScreen);

    mWorld = std::make_unique<b2World>(b2Vec2(0, 0));
    mWorld->SetDebugDraw(&mDebugDraw);
    auto body = PhysicsHelper::createBox(mWorld.get());

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

            double timeDelta = std::chrono::duration<double, std::milli>(timeNow - prevUpdateTimeInMills).count();
            timeDelta /= 1000.0; // in seconds

            //std::cout << std::to_string(timeDelta) << std::endl;

            nanogui::Screen *screen = mScreen;
            if (!screen->visible()) {
                continue;
            } else if (glfwWindowShouldClose(screen->glfwWindow())) {
                screen->setVisible(false);
                continue;
            }

            glClearColor( 0.0f, 0.0f, 0.0f, 0.0f ); //clear background screen to black

            //Clear information from last draw
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);



            glMatrixMode(GL_PROJECTION);
                glPushMatrix();
                glLoadIdentity();
                glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);

            glMatrixMode(GL_MODELVIEW);
                glPushMatrix();//Switch to the drawing perspective
                glLoadIdentity(); //Reset the drawing perspective


            //draw box2d debug info
            mWorld->DrawDebugData();
            glFlush();

            glPopMatrix();

            glMatrixMode(GL_PROJECTION);
                glPopMatrix();

            //nanogui draw
            screen->drawWidgets();

            //main update
            update(timeDelta);

            /* poll for mouse/keyboard or empty refresh events */
            glfwPollEvents();

            glfwSwapBuffers(mScreen->glfwWindow());

            prevUpdateTimeInMills = timeNow;
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
    mMenu->moveTextBox(timeDelta);
}
