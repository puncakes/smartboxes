#include "menu.h"

#include <nanogui/window.h>
#include <nanogui/layout.h>
#include <nanogui/button.h>
#include <nanogui/textbox.h>

Menu::Menu(nanogui::Screen& screen)
{
    mScreen = &screen;

    mWindow = new nanogui::Window{&screen, "Window"};
    mWindow->setPosition({15, 15});
    mWindow->setLayout(new nanogui::GroupLayout());
    auto b =new nanogui::Button(mWindow, "My Button");

    mTextBox = new nanogui::TextBox(mWindow, "textbox");

    b->setCallback([] {
        exit(EXIT_SUCCESS);
    });
}

Menu::~Menu()
{
    delete mTextBox;
    delete mWindow;
}

void Menu::cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{
    mTextBox->setValue(std::to_string(xpos) + " " + std::to_string(ypos));

    //since i overwrote the callback, send the input back to the screen
    mScreen->cursorPosCallbackEvent(xpos, ypos);
}
