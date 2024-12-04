#pragma once
#include "command.h"
#include "movie.h"

class Service; // Forward declaration

class RemoveCommand : public Command {
private:
    Service& service;
    int index;
    Movie movie;
public:
    RemoveCommand(Service& service, int index);
    void execute() override;
    void undo() override;
};
