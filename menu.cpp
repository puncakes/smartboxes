#include "menu.h"

#include <nanogui/window.h>
#include <nanogui/layout.h>
#include <nanogui/button.h>
#include <nanogui/textbox.h>

#include <fstream>

#include <GLFW/glfw3.h>

using json = nlohmann::json;

Menu::Menu(nanogui::Screen& screen)
{
    mScreen = &screen;

    std::unique_ptr<nanogui::Window> window = std::make_unique<nanogui::Window>(nanogui::Window(&screen, "Window"));
    window->setPosition({15, 15});
    window->setLayout(new nanogui::GroupLayout());
    auto b = new nanogui::Button(window.get(), "My Button");

    mTextBox = new nanogui::TextBox(window.get(), "textbox");

    b->setCallback([] {
        exit(EXIT_SUCCESS);
    });

    mWindows.push_back(window);
}

Menu::~Menu()
{
    delete mTextBox;
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
    //mWindow->setPosition({mWindowPosX, 15});
}

//base entry for a recursive parsing of a json file containing parameters for a custom menu ui
int Menu::parseConfig(const char *path) {
    std::ifstream ifs(path);
    if(ifs) {
        json j;
        j.parse(ifs);

        for ( auto& window : j.items()) {
            if(window.key() == "window") {
                //create a new ui window
                std::unique_ptr<nanogui::Window> w = std::make_unique<nanogui::Window>(nanogui::Window(mScreen));

                //set a default layout
                w->setLayout(new nanogui::GroupLayout());

                //loop over all the window's defined parameters
                for (auto& winParams : window.value().items()) {
                    auto& keyName = winParams.key();
                    auto& keyValue = winParams.value();

                    if(keyName == "name") {
                        w->setTitle(keyValue);
                    } else if (keyName == "pos") {
                        w->setPosition({keyValue["x"], keyValue["y"]});
                    } else if (keyName == "layout") {
                        //maybe actually parse later
                    } else if (keyName == "widgets") {
                        //who knows how deep we'll go? muahahahaha
                        parseWidget(winParams, w);
                    }
                }
            }
        }
    }
    return 0;
}

int Menu::parseWidget(nlohmann::json jsonItem, std::unique_ptr<nanogui::Window> &window) {
    return 0;
}
