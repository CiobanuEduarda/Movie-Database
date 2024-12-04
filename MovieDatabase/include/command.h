//
// Created by E Ciobanu on 31.05.2024.
//

#ifndef OOP_A10_CIOBANUEDUARDA_COMMAND_H
#define OOP_A10_CIOBANUEDUARDA_COMMAND_H

#endif //OOP_A10_CIOBANUEDUARDA_COMMAND_H
// Command.h
#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

#endif // COMMAND_H
