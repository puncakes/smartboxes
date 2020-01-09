#include "RBody.h"
#include "../GraphicsHelper.h"

RBody::RBody(b2Body& body) {
    mBody = &body;
}

void RBody::Draw() {

}

void RBody::setTexture(const char *texturePath) {
    mSpriteTexture = GraphicsHelper::LoadTexture2D(texturePath);
}


