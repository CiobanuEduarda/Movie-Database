#pragma once
#include "command.h"
#include "movie.h"

class Service; // Forward declaration

class UpdateCommand : public Command {
private:
    Service& service;
    int index;
    Movie newMovie;
    Movie oldMovie;
public:
    UpdateCommand(Service& service, int index, const Movie& newMovie);
    void execute() override;
    void undo() override;
};
