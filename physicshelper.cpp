#include "physicshelper.h"


b2Body* PhysicsHelper::createBox(b2World* world)
{
    assert(world != nullptr);

    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(0, 0); //set the starting position
    myBodyDef.angle = 0; //set the starting angle

    auto myBody = world->CreateBody(&myBodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(5,5);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 1;

    myBody->CreateFixture(&boxFixtureDef);

    return myBody;
}
