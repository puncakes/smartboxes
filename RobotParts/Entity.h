//
// Created by Radl, Adam J. on 1/7/20.
//

#ifndef EDITOR_Entity_H
#define EDITOR_Entity_H


#include "../camera.h"

class Entity {
public:
    virtual void Draw(GameCamera *pCamera) = 0;
    bool isManaged = false;
    bool isSelected = false;
    bool isVisible = true;
    bool isCollidable = true;

};


#endif //EDITOR_Entity_H
