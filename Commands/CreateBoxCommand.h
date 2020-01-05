#ifndef EDITOR_CREATEBOXCOMMAND_H
#define EDITOR_CREATEBOXCOMMAND_H


#include "ICommand.h"
#include "Box2D/Box2D.h"

class CreateBoxCommand : public ICommand {
public:
	CreateBoxCommand(b2World& world, b2Vec2& worldPosition);

	void Execute() override;

    void Undo() override;

private:
	b2World* mWorld = nullptr;
	b2Body* mBody = nullptr;
	b2Vec2 mPosition;
	
};


#endif //EDITOR_CREATEBOXCOMMAND_H
