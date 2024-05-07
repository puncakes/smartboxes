//
// Created by Adam on 5/7/2024.
//

#ifndef SMART_BOXES_CREATE_ROBOT_H
#define SMART_BOXES_CREATE_ROBOT_H


#include "ICursor.h"

class CreateRobotCursor : public ICursor {
public:
    CreateRobotCursor();
    bool handleMouseInput(b2World &world, double x, double y, int button, int action, int modifiers) override;
};


#endif //SMART_BOXES_CREATE_ROBOT_H
