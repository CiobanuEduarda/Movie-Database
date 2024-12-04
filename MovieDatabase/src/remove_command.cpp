//
// Created by E Ciobanu on 03.06.2024.
//
#include "remove_command.h"
#include "service.h"

RemoveCommand::RemoveCommand(Service& service, int index)
    : service(service), index(index), movie(service.getMovieByPosition(index)) {}

void RemoveCommand::execute() {
    service.deleteMovieByPosition(index);
}

void RemoveCommand::undo() {
    service.addMovieService(movie);
}
