//
// Created by dev on 5/6/24.
//

#ifndef SMART_BOXES_CREATE_BOX_H
#define SMART_BOXES_CREATE_BOX_H

#include "ICursor.h"

class CreateBoxCursor : public ICursor {
public:
    CreateBoxCursor();
    bool handleMouseInput(b2World &world, double x, double y, int button, int action, int modifiers) override;

private:
    int x1, y1, x2, y2;
    int clicked = 0;
};


#endif //SMART_BOXES_CREATE_BOX_H
