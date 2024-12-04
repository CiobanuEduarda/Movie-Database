//
// Created by E Ciobanu on 03.06.2024.
//
#include "update_command.h"
#include "service.h"

UpdateCommand::UpdateCommand(Service& service, int index, const Movie& newMovie)
        : service(service), index(index), newMovie(newMovie), oldMovie(service.getMovieByPosition(index)) {}

void UpdateCommand::execute() {
    service.updateMovie(index, newMovie);
}

void UpdateCommand::undo() {
    service.updateMovie(index, oldMovie);
}
