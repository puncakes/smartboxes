#include "commandmanager.h"

std::queue<ICommand*> CommandManager::mExecutedCommands;
std::vector<ICommand*> CommandManager::mStoredCommands;

void CommandManager::Execute(ICommand* command) {
    if(command) {
        command->Execute();
        mExecutedCommands.push(command);
    }
}

void CommandManager::Undo() {

}
