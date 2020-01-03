//
// Created by Radl, Adam J. on 1/3/20.
//

#ifndef EDITOR_CREATEBOXCOMMAND_H
#define EDITOR_CREATEBOXCOMMAND_H


#include "ICommand.h"

class CreateBoxCommand : public ICommand {
public:

    void Execute() override;

    void Undo() override;

};


#endif //EDITOR_CREATEBOXCOMMAND_H
