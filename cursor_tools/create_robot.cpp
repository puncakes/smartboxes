//
// Created by Adam on 5/7/2024.
//

#include "create_robot.h"
#include "../commandmanager.h"
#include "../Commands/CreateRobotCommand.h"
#include "../debugdraw.h"

bool CreateRobotCursor::handleMouseInput(b2World &world, double x, double y, int button, int action, int modifiers) {
    b2Vec2 ps((float32)x, (float32)y);

    if (button == GLFW_MOUSE_BUTTON_1) {
        b2Vec2 pw = g_camera.ConvertScreenToWorld(ps);
        if (action == GLFW_RELEASE) {
            b2Vec2 pw1 = g_camera.ConvertScreenToWorld(b2Vec2(x, y));
            CreateRobotCommand *command = new CreateRobotCommand(world, pw1);
            CommandManager::Execute(command);

            return true;
        }
    }

    return false;
}

CreateRobotCursor::CreateRobotCursor() {

}
