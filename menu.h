#ifndef MENU_H
#define MENU_H

#include <nanogui/screen.h>
#include <nlohmann/json.hpp>

class Menu
{
public:
    Menu(nanogui::Screen& screen);
    ~Menu();

    int parseConfig(const char* path);
    bool cursor_position_callback(double xpos, double ypos);

	void moveTextBox(double distance, nanogui::Window& window);

	void update(double timeDelta);
private:
    double mWindowPosX = 15;
    //only a handle. do not delete this!
    nanogui::Screen* mScreen;

    std::vector<nanogui::Window*> mWindows;

    //test object. will be in a mapping later
    nanogui::TextBox* mTextBox;

    int parseWidget(nlohmann::json jsonItem, nanogui::Window& window);
	int addButton(nlohmann::json jsonItem, nanogui::Window& window);
	
};

#endif // MENU_H
