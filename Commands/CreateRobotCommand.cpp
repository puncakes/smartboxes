//
// Created by Adam on 3/30/2023.
//

#include "CreateRobotCommand.h"
#include "../physicshelper.h"
#include "../entitymanager.h"

CreateRobotCommand::CreateRobotCommand(b2World& world, b2Vec2& worldPosition) {
    mWorld = &world;
    mPosition = worldPosition;
}

void CreateRobotCommand::Execute() {
    mBody = PhysicsHelper::createBox(mWorld, mPosition.x, mPosition.y);
    mRobotPart = new RobotPart(*mBody);

    //set RobotPart texture
    mRobotPart->setTexture("gfx/textures/robot_parts/chest1.png");
    EntityManager::AddEntity(mRobotPart);
}

void CreateRobotCommand::Undo() {
    EntityManager::RemoveEntity(mRobotPart);
    mWorld->DestroyBody(mBody);
}