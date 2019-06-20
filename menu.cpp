#include "menu.h"

#include <nanogui/window.h>
#include <nanogui/layout.h>
#include <nanogui/button.h>
#include <nanogui/textbox.h>

#include <GLFW/glfw3.h>

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

bool Menu::cursor_position_callback(double xpos, double ypos)
{
    mTextBox->setValue(std::to_string(static_cast<int>(xpos)) +
                          " " +
                          std::to_string(static_cast<int>(ypos)));
    return true;
}

void Menu::moveTextBox(double distance)
{
    double scalar = 10.0;
    mWindowPosX += distance * scalar;
    mWindow->setPosition({mWindowPosX, 15});
}
