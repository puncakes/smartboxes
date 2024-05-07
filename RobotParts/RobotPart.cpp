#include "../GraphicsHelper.h"
#include "RobotPart.h"


RobotPart::RobotPart(b2Body& body) {
    mBody = &body;
    mShader = GraphicsHelper::LoadShader("gfx/shaders/sprite.vert", "gfx/shaders/sprite.frag");
    mSprite = new Sprite(mShader);
}

void RobotPart::Draw() {
    //get position and rotation
    b2Vec2 position = mBody->GetPosition();
    float32 angle = mBody->GetAngle();

    //draw sprite
    mSprite->DrawSprite(mSpriteTexture, glm::vec2(position.x, position.y), glm::vec2(1.0f, 1.0f), angle, glm::vec3(1.0f));

}

void RobotPart::setTexture(const char *texturePath) {
    mSpriteTexture = GraphicsHelper::LoadTexture2D(texturePath);
}


