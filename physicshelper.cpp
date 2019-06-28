#include "physicshelper.h"
#include "utils.h"

b2Body* PhysicsHelper::createBox(b2World* world, float32 x, float32 y)
{
    assert(world != nullptr);

    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(x, y); //set the starting position
    myBodyDef.angle = 0; //set the starting angle

    auto myBody = world->CreateBody(&myBodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(1,1);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 1;
    boxFixtureDef.restitution = 0.5;

    myBody->CreateFixture(&boxFixtureDef);

    return myBody;
}

b2Body* PhysicsHelper::createGround(b2World* world)
{
    assert(world != nullptr);

    b2BodyDef myBodyDef;
    myBodyDef.type = b2_staticBody; //this will be a static body
    myBodyDef.position.Set(0, -10); //set the starting position
    myBodyDef.angle = 0; //set the starting angle

    auto myBody = world->CreateBody(&myBodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(100,1);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 1;

    myBody->CreateFixture(&boxFixtureDef);

    return myBody;
}

void PhysicsHelper::reshapeBox(b2Body* body, float32 x, float32 y)
{
    assert(body != nullptr);

    for (b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext())
    {
        if(instanceof<b2PolygonShape>(f->GetShape())) {

        }
    }

}
