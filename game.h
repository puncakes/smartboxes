#ifndef GAME_H
#define GAME_H

#include "menu.h"

#include <nanogui/screen.h>
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

    bool mainloop_active = false;

    std::chrono::high_resolution_clock::time_point prevUpdateTimeInMills;

    void init_glfw();
    void game_loop();

    //perform update of game state
    //passing in time delta since last update
    void update(double timeDelta);


};

#endif // GAME_H
