#ifndef MENU_H
#define MENU_H

#include <nanogui/screen.h>


class Menu
{
public:
    Menu(nanogui::Screen& screen);
    ~Menu();

    bool cursor_position_callback(double xpos, double ypos);

    void moveTextBox(double distance);
private:
    double mWindowPosX = 15;
    //only a handle. do not delete this!
    nanogui::Screen* mScreen;

    nanogui::Window* mWindow;

    //test object. will be in a mapping later
    nanogui::TextBox* mTextBox;

};

#endif // MENU_H
