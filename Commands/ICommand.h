//
// Created by Radl, Adam J. on 1/3/20.
//

#ifndef EDITOR_ICOMMAND_H
#define EDITOR_ICOMMAND_H


class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void Execute() = 0;
    virtual void Undo() = 0;

    //prolly won't use this but it's a cool idea
    virtual bool Triggered() {};
};


#endif //EDITOR_ICOMMAND_H
