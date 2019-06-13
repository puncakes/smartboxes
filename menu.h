#ifndef MENU_H
#define MENU_H

#include <nanogui/screen.h>


class Menu
{
public:
    Menu(nanogui::Screen& screen);
    ~Menu();

    //retrieves *this* pointer from GLFW's getWindowUserPointer
    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

private:
    //only a handle. do not delete this!
    nanogui::Screen* mScreen;

    nanogui::Window* mWindow;

    //test object. will be in a mapping later
    nanogui::TextBox* mTextBox;

};

#endif // MENU_H
