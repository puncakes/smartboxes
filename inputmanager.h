#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <string>
#include <vector>
#include <functional>
#include <GLFW/glfw3.h>

#include "cursor_tools/ICursor.h"

typedef std::tuple<std::string, std::function<bool(double, double)>> MousePosCallback;
typedef std::tuple<std::string, std::function<bool(int, int, int)>> MouseButtonCallback;
typedef std::tuple<std::string, std::function<bool(int, int, int, int)>> KeyCallback;

//Class to handle routing of input events to registered callbacks
class InputManager
{
public:
    //sets this as main input manager
    static void registerWithGLFW(GLFWwindow& window);

    //force move semantics for callbacks
    static bool addMousePositionCallback(MousePosCallback&& callback);
    static bool addMouseButtonCallback(MouseButtonCallback&& callback);
    static bool addKeyCallback(KeyCallback&& callback);
    static void setCursor(ICursor* cursor);
    static ICursor* getCursor();

private:
    //various vectors for input callbacks
    static std::vector<MousePosCallback> mMousePosCallbacks;
    static std::vector<MouseButtonCallback> mMouseButtonCallbacks;
    static std::vector<KeyCallback> mKeyCallbacks;

    static void mainMousePositionCallback(GLFWwindow* window, double x, double y);
    static void mainMouseButtonCallback(GLFWwindow* window, int button, int action, int modifiers);
    static void mainKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static ICursor* mCursor;
};

#endif // INPUTMANAGER_H
