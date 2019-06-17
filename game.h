#ifndef GAME_H
#define GAME_H

#include "menu.h"
#include "debugdraw.h"

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
    Menu *mMenu;
    nanogui::Screen *mScreen;
    DebugDraw mDebugDraw;


    bool mainloop_active = false;

    std::chrono::high_resolution_clock::time_point prevUpdateTimeInMills;

    void init_glfw();
    void game_loop();

    //perform update of game state
    //passing in time delta since last update
    void update(double timeDelta);

    std::unique_ptr<b2World> mWorld;


};

#endif // GAME_H
