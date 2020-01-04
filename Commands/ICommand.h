#ifndef EDITOR_ICOMMAND_H
#define EDITOR_ICOMMAND_H


#include <functional>

class ICommand {
public:
    ICommand() {};
    virtual ~ICommand() = default;

    virtual void Execute() = 0;
    virtual void Undo() = 0;

    //prolly won't use this but it's a cool idea
    virtual bool Triggered() { return false; };

	//to be used in a lambda command only
    std::function<void()> executeLambda = nullptr;
    std::function<void()> undoLambda = nullptr;
};


#endif //EDITOR_ICOMMAND_H
