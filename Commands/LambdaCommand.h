//
// Created by Adam on 1/3/2020.
//

#ifndef EDITOR_LAMBDACOMMAND_H
#define EDITOR_LAMBDACOMMAND_H


#include "ICommand.h"

class LambdaCommand : public ICommand {
public:
    void Execute() override;

    void Undo() override;
};


#endif //EDITOR_LAMBDACOMMAND_H
