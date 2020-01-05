#ifndef EDITOR_COMMANDMANAGER_H
#define EDITOR_COMMANDMANAGER_H

#include "Commands/ICommand.h"

#include <stack>
#include <vector>

class CommandManager {
public:
    CommandManager();
    virtual ~CommandManager();

    static void Execute(ICommand* command);
    static void UndoLastCommand();
    static void Redo();

    //unused atm
    static void Store(ICommand* command);
    static void CheckTriggers();

private:
    static std::stack<ICommand*> mExecutedCommands;

    //unused atm. for command triggers
    static std::vector<ICommand*> mStoredCommands;

};


#endif //EDITOR_COMMANDMANAGER_H
