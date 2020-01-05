#include "commandmanager.h"

std::stack<ICommand*> CommandManager::mExecutedCommands;
std::vector<ICommand*> CommandManager::mStoredCommands;

void CommandManager::Execute(ICommand* command) {
    if(command) {
        command->Execute();
        mExecutedCommands.push(command);
    }
}

void CommandManager::UndoLastCommand() {
    if(mExecutedCommands.size() <= 0) {
        return;
    }
    ICommand* lastCommand = mExecutedCommands.top();
    lastCommand->Undo();
    mExecutedCommands.pop();

}
