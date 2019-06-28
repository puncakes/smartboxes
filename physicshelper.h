#ifndef PHYSICSHELPER_H
#define PHYSICSHELPER_H

#include <Box2D/Box2D.h>

class PhysicsHelper
{
public:
    static b2Body* createBox(b2World* world, float32 x, float32 y);
    static b2Body* createGround(b2World* world);
    static void reshapeBox(b2Body* body, float32 x, float32 y);
};

#endif // PHYSICSHELPER_H
