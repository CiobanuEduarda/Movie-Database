//
// Created by E Ciobanu on 03.06.2024.
//
#include "add_command.h"
#include "service.h"

AddCommand::AddCommand(Service& service, const Movie& movie)
        : service(service), movie(movie) {}

void AddCommand::execute() {
    service.addMovieService(movie);
}

void AddCommand::undo() {
    int index = service.getAllMovies().size() - 1; // assuming the movie was added at the end
    service.deleteMovieByPosition(index);
}
