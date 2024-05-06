//
// Created by dev on 5/6/24.
//

#ifndef SMART_BOXES_ICURSOR_H
#define SMART_BOXES_ICURSOR_H

class ICursor {
public:
    virtual bool handleMouseInput(int button, int action, int modifiers) = 0;
};
#endif //SMART_BOXES_ICURSOR_H
