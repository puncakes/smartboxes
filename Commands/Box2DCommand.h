//
// Created by Radl, Adam J. on 1/3/20.
//

#ifndef EDITOR_BOX2DCOMMAND_H
#define EDITOR_BOX2DCOMMAND_H


#include "ICommand.h"
#include "../physicshelper.h"

class Box2DCommand : public ICommand {
public:
    Box2DCommand(b2World* world);

private:
    b2World* mWorld;

};


#endif //EDITOR_BOX2DCOMMAND_H
