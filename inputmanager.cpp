#include "inputmanager.h"

std::vector<MousePosCallback> InputManager::mMousePosCallbacks;
std::vector<MouseButtonCallback> InputManager::mMouseButtonCallbacks;
std::vector<KeyCallback> InputManager::mKeyCallbacks;
ICursor* InputManager::mCursor;

void InputManager::registerWithGLFW(GLFWwindow& window)
{
    glfwSetCursorPosCallback(&window, mainMousePositionCallback);
    glfwSetMouseButtonCallback(&window, mainMouseButtonCallback);
    glfwSetKeyCallback(&window, mainKeyCallback);
}

bool InputManager::addMousePositionCallback(MousePosCallback &&callback)
{
    mMousePosCallbacks.push_back(callback);
    return true;
}

bool InputManager::addMouseButtonCallback(MouseButtonCallback &&callback)
{
    mMouseButtonCallbacks.push_back(callback);
    return true;
}

bool InputManager::addKeyCallback(KeyCallback &&callback)
{
    mKeyCallbacks.push_back(callback);
    return true;
}

//section loops through registered callbacks and passes on input events
void InputManager::mainMousePositionCallback(GLFWwindow *window, double x, double y)
{
    for(auto cb : mMousePosCallbacks) {
        auto cbDest = std::get<0>(cb);
        auto cbFunc = std::get<1>(cb);

        if(cbFunc(x, y)) {
            break;
        }
    }
}

void InputManager::mainMouseButtonCallback(GLFWwindow *window, int button, int action, int modifiers)
{
    for(auto cb : mMouseButtonCallbacks) {
        auto cbDest = std::get<0>(cb);
        auto cbFunc = std::get<1>(cb);

        if(cbFunc(button, action, modifiers)) {
            break;
        }
    }
}

void InputManager::mainKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    for(auto cb : mKeyCallbacks) {
        auto cbDest = std::get<0>(cb);
        auto cbFunc = std::get<1>(cb);

        if(cbFunc(key, scancode, action, mods)) {
            break;
        }
    }
}

void InputManager::setCursor(ICursor *cursor) {
    //free previous cursor
    delete mCursor;
    mCursor = cursor;
}

ICursor *InputManager::getCursor() {
    return mCursor;
}
