#include "commandmanager.h"

CommandManager::CommandManager() {}

CommandManager::~CommandManager() {

}

void CommandManager::Execute(ICommand* command) {
    if(command) {
        command->Execute();
        mExecutedCommands.push(command);
    }
}
