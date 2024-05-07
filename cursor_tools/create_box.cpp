//
// Created by dev on 5/6/24.
//

#include "create_box.h"
#include "../debugdraw.h"
#include "../Commands/CreateBoxCommand.h"
#include "../commandmanager.h"

CreateBoxCursor::CreateBoxCursor() {
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    clicked = 0;
}

bool CreateBoxCursor::handleMouseInput(b2World &world, double x, double y, int button, int action, int modifiers) {
    b2Vec2 ps((float32)x, (float32)y);

    if (button == GLFW_MOUSE_BUTTON_1) {
        b2Vec2 pw = g_camera.ConvertScreenToWorld(ps);
        if (action == GLFW_RELEASE) {
            x1 = x;
            y1 = y;
            b2Vec2 pw1 = g_camera.ConvertScreenToWorld(b2Vec2(x1, y1));
            CreateBoxCommand *command = new CreateBoxCommand(world, pw1);
            CommandManager::Execute(command);

            return true;
        }
    }

    return false;
}