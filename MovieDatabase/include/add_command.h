#pragma once
#include "command.h"
#include "movie.h"

class Service; // Forward declaration

class AddCommand : public Command {
private:
    Service &service;
    Movie movie;
public:
    AddCommand(Service& service, const Movie& movie);
    void execute() override;
    void undo() override;
};
