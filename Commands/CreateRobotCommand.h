//
// Created by Adam on 3/30/2023.
//

#ifndef EDITOR_CREATEROBOTCOMMAND_H
#define EDITOR_CREATEROBOTCOMMAND_H


#include "ICommand.h"
#include "Box2D/Box2D.h"
#include "../Robot.h"

class CreateRobotCommand : public ICommand {
    CreateRobotCommand(b2World& world, b2Vec2& worldPosition);

    void Execute() override;

    void Undo() override;

private:
    Robot mRobot;
    b2World* mWorld = nullptr;
    b2Body* mBody = nullptr;
    b2Vec2 mPosition;
};


#endif //EDITOR_CREATEROBOTCOMMAND_H
