//
// Created by Radl, Adam J. on 1/7/20.
//

#ifndef EDITOR_RBODY_H
#define EDITOR_RBODY_H


#include <Box2D/Box2D.h>
#include <GLFW/glfw3.h>

#include "IRobotPart.h"

class RBody : public IRobotPart{
public:
    RBody(b2Body& body);
    void setTexture(const char* texturePath);
    void Draw() override;

private:
    //physics body
    b2Body* mBody;

    //sprite info
    GLuint mSpriteTexture;

};


#endif //EDITOR_RBODY_H
