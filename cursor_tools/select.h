//
// Created by Adam on 5/7/2024.
//

#ifndef SMART_BOXES_SELECT_H
#define SMART_BOXES_SELECT_H


#include <vector>
#include "ICursor.h"

class SelectCursor : ICursor {
public:
    SelectCursor();
    bool handleMouseInput(b2World &world, double x, double y, int button, int action, int modifiers) override;
private:
    //vector of selected objects
    std::vector<b2Body*> selectedObjects;
};


#endif //SMART_BOXES_SELECT_H
