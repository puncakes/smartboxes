//
// Created by Adam on 3/30/2023.
//

#include "CreateRobotCommand.h"
#include "../physicshelper.h"
#include "../RobotParts/RBody.h"

CreateRobotCommand::CreateRobotCommand(b2World& world, b2Vec2& worldPosition) {
    mWorld = &world;
    mPosition = worldPosition;

    //create robot body from mBody
    mBody = PhysicsHelper::createBox(mWorld, mPosition.x, mPosition.y);
    RBody* body = new RBody(*mBody);

    //set RBody texture
    body->setTexture("gfx/textures/robot_parts/chest1.png");

}

void CreateRobotCommand::Execute() {
    mBody = PhysicsHelper::createBox(mWorld, mPosition.x, mPosition.y);
}

void CreateRobotCommand::Undo() {
    mWorld->DestroyBody(mBody);
}