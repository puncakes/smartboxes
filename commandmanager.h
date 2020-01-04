#ifndef EDITOR_COMMANDMANAGER_H
#define EDITOR_COMMANDMANAGER_H

#include "Commands/ICommand.h"

#include <queue>

class CommandManager {
public:
    CommandManager();
    virtual ~CommandManager();

    static void Execute(ICommand* command);
    static void Undo();
    static void Redo();

    //unused atm
    static void Store(ICommand* command);
    static void CheckTriggers();

private:
    static std::queue<ICommand*> mExecutedCommands;

    //unused atm. for command triggers
    static std::vector<ICommand*> mStoredCommands;

};


#endif //EDITOR_COMMANDMANAGER_H
