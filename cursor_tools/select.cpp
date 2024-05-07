//
// Created by Adam on 5/7/2024.
//

#include "select.h"
#include "../debugdraw.h"

bool SelectCursor::handleMouseInput(b2World &world, double x, double y, int button, int action, int modifiers) {
    //if left mouse button is clicked and nothing has been previously selected or if ctrl is pressed
    if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS && (modifiers == GLFW_MOD_CONTROL || selectedObjects.empty())) {
        b2Vec2 ps((float32)x, (float32)y);
        b2Vec2 pw = g_camera.ConvertScreenToWorld(ps);

        //iterate through all objects in the world
        for (b2Body* b = world.GetBodyList(); b; b = b->GetNext()) {
            //if the object is within the mouse click
            if (b->GetFixtureList()->TestPoint(pw)) {
                //if the object is already selected, deselect it
                if (std::find(selectedObjects.begin(), selectedObjects.end(), b) != selectedObjects.end()) {
                    selectedObjects.erase(std::remove(selectedObjects.begin(), selectedObjects.end(), b), selectedObjects.end());
                } else {
                    //otherwise, select it
                    selectedObjects.push_back(b);
                }
            }
        }

        return true;
    }
    return false;
}
