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

    void moveTextBox(double distance);
private:
    double mWindowPosX = 15;
    //only a handle. do not delete this!
    nanogui::Screen* mScreen;

    std::vector<std::unique_ptr<nanogui::Window>> mWindows;

    //test object. will be in a mapping later
    nanogui::TextBox* mTextBox;

    int parseWidget(nlohmann::json jsonItem, std::unique_ptr<nanogui::Window> &window);
};

#endif // MENU_H
