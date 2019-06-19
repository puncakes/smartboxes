#include "game.h"
#include "physicshelper.h"

#include "debugdraw.h"

#include <GLFW/glfw3.h>
#include <chrono>
#include <iostream>
#include <memory>

Game::Game()
{
    //start up opengl
    init_glfw();

    //TODO:create input manager for glfw input events
    mMenu = new Menu(*mScreen);

    mWorld = std::make_unique<b2World>(b2Vec2(0, 0));

    g_debugDraw.Create();

    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_jointBit;
    flags += b2Draw::e_aabbBit;
    flags += b2Draw::e_pairBit;
    flags += b2Draw::e_centerOfMassBit;
    g_debugDraw.SetFlags(flags);

    mWorld->SetDebugDraw(&g_debugDraw);

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

            if (!mScreen->visible()) {
                continue;
            } else if (glfwWindowShouldClose(mScreen->glfwWindow())) {
                mScreen->setVisible(false);
                continue;
            }

            glClearColor( 0.0f, 0.0f, 0.0f, 1.0f ); //clear background screen to black

            //Clear information from last draw
            glClear(GL_COLOR_BUFFER_BIT);

            mWorld->Step(timeDelta, 1, 1);
            //glFlush();
            //draw box2d debug info
            mWorld->DrawDebugData();
            g_debugDraw.Flush();

            //nanogui draw
            mScreen->drawWidgets();

            //main update
            update(timeDelta);

            glfwSwapBuffers(mGLFWindow);

            /* poll for mouse/keyboard or empty refresh events */
            glfwPollEvents();

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

    mScreen = new nanogui::Screen{{1280, 720}, "Editor", {}, true};

    mGLFWindow = mScreen->glfwWindow();

    g_camera.m_width = mScreen->width();
    g_camera.m_height = mScreen->height();

    //set camera to map pixels to world coordinates initially
    //g_camera.m_center.Set(mScreen->width() / 2, mScreen->height() / 2);
    g_camera.m_center.Set(0,0);

    g_camera.m_zoom = 1.0f / 20.0f;
}

void Game::update(double timeDelta)
{
    mMenu->moveTextBox(timeDelta);
}
