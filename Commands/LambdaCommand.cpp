//
// Created by Adam on 1/3/2020.
//

#include "LambdaCommand.h"

void LambdaCommand::Execute() {
    if(executeLambda) {
        executeLambda();
    }
}

void LambdaCommand::Undo() {
    if(undoLambda) {
        undoLambda();
    }
}
