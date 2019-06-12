#ifndef GAME_H
#define GAME_H

#include <nanogui/screen.h>

#include "menu.h"

class Game
{
public:
    Game();
    ~Game();

    void run();
private:
    Menu *mMenu;
    nanogui::Screen *mScreen;

};

#endif // GAME_H
