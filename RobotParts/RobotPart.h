//
// Created by Radl, Adam J. on 1/7/20.
//

#ifndef EDITOR_RBODY_H
#define EDITOR_RBODY_H

#include <Box2D/Box2D.h>
#include <GLFW/glfw3.h>
#include "../Shader.h"

#include "Entity.h"
#include "../Sprite.h"


class RobotPart : public Entity{
public:
    RobotPart(b2Body& body);
    void setTexture(const char* texturePath);
    void Draw(GameCamera *pCamera) override;

private:
    //physics body
    b2Body* mBody;

    //sprite info
    GLuint mSpriteTexture;
    Shader mShader;
    Sprite* mSprite;

};


#endif //EDITOR_RBODY_H
