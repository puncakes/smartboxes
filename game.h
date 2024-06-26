#ifndef GAME_H
#define GAME_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "menu.h"
#include "camera.h"

#include <nanogui/screen.h>
#include <Box2D/Box2D.h>
#include <chrono>

class Game
{
public:
    Game();
    ~Game();

    void run();
private:
    Menu* mMenu;
    nanogui::Screen* mScreen;
    GLFWwindow* mGLFWindow;
    GameCamera* mCamera;

    float mWidth = 1200;
    float mHeight = 720;

    bool mainloop_active = false;

    std::chrono::high_resolution_clock::time_point prevUpdateTimeInMills;

    void init_glfw();
    void game_loop();


    bool mouseButtonEvent(int button, int action, int modifiers);
    bool keypressEvent(int key, int scancode, int action, int mods);

    //perform update of game state
    //passing in time delta since last update
    void update(double timeDelta);

    std::unique_ptr<b2World> mWorld;



};

#endif // GAME_H
