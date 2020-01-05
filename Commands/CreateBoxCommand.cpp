#include "CreateBoxCommand.h"
#include "../physicshelper.h"

CreateBoxCommand::CreateBoxCommand(b2World & world, b2Vec2& worldPosition)
{
	mWorld = &world;
	mPosition = worldPosition;
}

void CreateBoxCommand::Execute() {
	mBody = PhysicsHelper::createBox(mWorld, mPosition.x, mPosition.y);
}

void CreateBoxCommand::Undo() {
	mWorld->DestroyBody(mBody);
}
