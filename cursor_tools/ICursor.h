//
// Created by dev on 5/6/24.
//

#ifndef SMART_BOXES_ICURSOR_H
#define SMART_BOXES_ICURSOR_H

#include <GLFW/glfw3.h>
#include "Box2D/Dynamics/b2World.h"

class ICursor {
public:
    virtual bool handleMouseInput(b2World &world, double x, double y, int button, int action, int modifiers) = 0;
};
#endif //SMART_BOXES_ICURSOR_H
