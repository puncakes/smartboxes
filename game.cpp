#include "game.h"
#include "physicshelper.h"
#include "inputmanager.h"

#include "debugdraw.h"
#include "Commands/CreateBoxCommand.h"
#include "commandmanager.h"

#include <chrono>
#include <iostream>
#include <memory>

Game::Game()
{
    //start up opengl
    init_glfw();

    //sets the input manager as the default handler of glfw input events
    InputManager::registerWithGLFW(*mScreen->glfwWindow());

    mMenu = new Menu(*mScreen);
	mMenu->parseConfig("configs/menu.json");

    //create callbacks for input events
    auto mousePosTuple = std::make_tuple("pos",
        [=](double x, double y) {
            return mMenu->cursor_position_callback(x,y);
    });

    auto menuMousePosTuple = std::make_tuple("menu",
        [=](double x, double y) {
            return mScreen->cursorPosCallbackEvent(x,y);
    });

    auto menuMouseButtonTuple = std::make_tuple("menu",
        [=](int button, int action, int modifiers) {
            return mScreen->mouseButtonCallbackEvent(button, action, modifiers);
    });

    auto gameMouseButtonTuple = std::make_tuple("game",
        [=](int button, int action, int modifiers) {
            return this->mouseButtonEvent(button, action, modifiers);
    });

    auto gameKeyPressTuple = std::make_tuple("game",
        [=](int key, int scancode, int action, int mods) {
            return this->keypressEvent(key, scancode, action, mods);
    });

    //events are processed in queue priority
    //general idea is a callback returns true if it consumed the input

    //mouse position callback queue
    InputManager::addMousePositionCallback(std::move(menuMousePosTuple));
    InputManager::addMousePositionCallback(std::move(mousePosTuple));

    //mouse button callback queue
    InputManager::addMouseButtonCallback(std::move(menuMouseButtonTuple));
    InputManager::addMouseButtonCallback(std::move(gameMouseButtonTuple));

    //keypress callback queue
    InputManager::addKeyCallback(std::move(gameKeyPressTuple));

    mWorld = std::make_unique<b2World>(b2Vec2(0, -9.8f));

    PhysicsHelper::createGround(mWorld.get());

    g_debugDraw.Create();

    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_jointBit;
    //flags += b2Draw::e_aabbBit;
    flags += b2Draw::e_pairBit;
    flags += b2Draw::e_centerOfMassBit;
    g_debugDraw.SetFlags(flags);

    mWorld->SetDebugDraw(&g_debugDraw);

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

            //fixed time delta for simulations
            //run as if 60fps is normal speed
            //timeDelta = 0.016;

            if (!mScreen->visible()) {
                continue;
            } else if (glfwWindowShouldClose(mScreen->glfwWindow())) {
                mScreen->setVisible(false);
                continue;
            }

            glClearColor( 0.0f, 0.0f, 0.0f, 1.0f ); //clear background screen to black

            //Clear information from last draw
            glClear(GL_COLOR_BUFFER_BIT);

            mWorld->Step(timeDelta, 10, 10);

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

bool Game::mouseButtonEvent(int button, int action, int modifiers)
{
    double xd, yd;
    glfwGetCursorPos(mScreen->glfwWindow(), &xd, &yd);
    b2Vec2 ps((float32)xd, (float32)yd);

    // Use the mouse to move things around.
    if (button == GLFW_MOUSE_BUTTON_1)
    {
        //<##>
        //ps.Set(0, 0);
        b2Vec2 pw = g_camera.ConvertScreenToWorld(ps);
        if (action == GLFW_PRESS)
        {
            if (modifiers == GLFW_MOD_SHIFT)
            {
                //test->ShiftMouseDown(pw);
            }
            else
            {
                //test->MouseDown(pw);
            }
        }

        if (action == GLFW_RELEASE)
        {
            //create box on release
			CreateBoxCommand* command = new CreateBoxCommand(*mWorld.get(), pw);
            CommandManager::Execute(command);
        }
    }

    return true;
}

bool Game::keypressEvent(int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_Z && action == GLFW_RELEASE && mods == GLFW_MOD_CONTROL) {
        CommandManager::UndoLastCommand();
    }
    return true;
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

    mScreen = new nanogui::Screen{{1280, 720}, "Editor", {}, false};

    mGLFWindow = mScreen->glfwWindow();

    //get the shading language version
    const char *version = (const char *) glGetString(GL_SHADING_LANGUAGE_VERSION);

    //print the version
    std::cout << "GLSL version: " << version << std::endl;

	int width, height;
	glfwGetWindowSize(mGLFWindow, &width, &height);

    g_camera.m_width = width;
    g_camera.m_height = height;

    //set camera to map pixels to world coordinates initially
    //g_camera.m_center.Set(mScreen->width() / 2, mScreen->height() / 2);
    g_camera.m_center.Set(0,0);

}

void Game::update(double timeDelta)
{
    mMenu->update(timeDelta);
}
