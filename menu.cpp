#include "menu.h"

#include <nanogui/window.h>
#include <nanogui/layout.h>
#include <nanogui/button.h>
#include <nanogui/textbox.h>

#include <fstream>
#include <iostream>

#include <GLFW/glfw3.h>

#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

using json = nlohmann::json;

Menu::Menu(nanogui::Screen& screen)
{
    mScreen = &screen;
}

Menu::~Menu()
{
    delete mTextBox;
	for (auto window : mWindows) {
		delete window;
	}
}

bool Menu::cursor_position_callback(double xpos, double ypos)
{
    //mTextBox->setValue(std::to_string(static_cast<int>(xpos)) +
    //                      " " +
    //                      std::to_string(static_cast<int>(ypos)));

    return true;
}

void Menu::moveTextBox(double distance,nanogui::Window& window)
{
    double scalar = 10.0;
    mWindowPosX += window.position().x() + distance * scalar;
    window.setPosition({ mWindowPosX, window.position().y() });
}

void Menu::update(double timeDelta)
{
	for (auto&& window : mWindows) {
		//TODO::check to see if the window actually wants to update
		//moveTextBox(timeDelta, window);
	}
}

//base entry for a recursive parsing of a json file containing parameters for a custom menu ui
int Menu::parseConfig(const char *path) {
    std::ifstream ifs(path);
    if(ifs) {
		json j = json::parse(ifs);
		                           
		for (auto window : j["windows"]) {
			LOG(DEBUG) << "inside window object array";

			//create a new ui window
			nanogui::Window* w = new nanogui::Window(mScreen, "Test Title");

			//set a default layout
			w->setLayout(new nanogui::GroupLayout());
		
			if (window.contains("name")) {
				w->setTitle(window["name"].get<std::string>());
				LOG(DEBUG) << "name of window: " << window["name"].get<std::string>();
			}
			if (window.contains("pos")) {
				w->setPosition({ window["pos"]["x"].get<int>(), window["pos"]["y"].get<int>()});
				LOG(DEBUG) << "window xpos: " << window["pos"]["x"].get<int>();
				LOG(DEBUG) << "window ypos: " << window["pos"]["y"].get<int>();
			}
			if (window.contains("layout")) {
				//maybe actually parse later
			}
			if (window.contains("widgets")) {
				//who knows how deep we'll go? muahahahaha
				for (auto widget : window["widgets"]) {
					parseWidget(widget, *w);
				}
				
			}

			mWindows.push_back(w);
		}
    }
    return 0;
}

int Menu::parseWidget(nlohmann::json jsonItem, nanogui::Window& window) {
	if (jsonItem.contains("button")) {
		addButton(jsonItem["button"], window);
	}
    return 0;
}

int Menu::addButton(nlohmann::json jsonItem, nanogui::Window& window)
{
	auto b = new nanogui::Button(&window);

	if (jsonItem.contains("text")) {
		b->setCaption(jsonItem["text"].get<std::string>());
	}
	if (jsonItem.contains("action")) {
		//TODO::something besides exiting the application :P
		b->setCallback([] {
			exit(EXIT_SUCCESS);
		});
	}
	return 0;
}
