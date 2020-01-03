#ifndef EDITOR_COMMANDMANAGER_H
#define EDITOR_COMMANDMANAGER_H

#include "Commands/ICommand.h"

#include <queue>

class CommandManager {
public:
    CommandManager();
    virtual ~CommandManager();

    void Execute(ICommand* command);
    void Undo();
    void Redo();

    //unused atm
    void Store(ICommand* command);
    void CheckTriggers();

private:
    std::queue<ICommand*> mExecutedCommands;

    //unused atm. for command triggers
    std::vector<ICommand*> mStoredCommands;

};


#endif //EDITOR_COMMANDMANAGER_H
