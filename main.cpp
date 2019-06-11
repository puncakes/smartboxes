#define GL_SILENCE_DEPRECATION

#include <iostream>

#include <nanogui/screen.h>
#include <nanogui/window.h>
#include <nanogui/layout.h>
#include <nanogui/button.h>

using namespace std;

int main() {

    nanogui::init();

    nanogui::Screen screen{{600, 420}, "Screen"};
    nanogui::Window window{&screen, "Window"};
    window.setPosition({15, 15});
    window.setLayout(new nanogui::GroupLayout());
    nanogui::Button *b =new nanogui::Button(&window, "My Button");

    b->setCallback([] {
        cout << "Button pressed!" << endl;
    });

    screen.performLayout();

    screen.drawAll();
    screen.setVisible(true);

    nanogui::mainloop();

    nanogui::shutdown();
    exit(EXIT_SUCCESS);
}
