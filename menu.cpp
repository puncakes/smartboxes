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

    glfwSetWindowUserPointer(screen.glfwWindow(), this);

    glfwSetCursorPosCallback(screen.glfwWindow(), Menu::cursor_position_callback);
}

Menu::~Menu()
{
    delete mTextBox;
    delete mWindow;
}

void Menu::cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{
    Menu* m = static_cast<Menu*>(glfwGetWindowUserPointer(window));

    m->mTextBox->setValue(std::to_string(static_cast<int>(xpos)) +
                          " " +
                          std::to_string(static_cast<int>(ypos)));

    //since i overwrote the callback, send the input back to the screen
    m->mScreen->cursorPosCallbackEvent(xpos, ypos);
}

void Menu::moveTextBox(double distance)
{
    double scalar = 10.0;
    mWindowPosX += distance * scalar;
    mWindow->setPosition({mWindowPosX, 15});
}
