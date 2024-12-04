//
// Created by E Ciobanu on 27.04.2024.
//
#include "exceptions.h"

RepoException ::RepoException() {
    this->message="";
}

RepoException ::RepoException(const std::string &message) {
    this->message=message;
}

const char *RepoException::what() {
    return this->message.c_str();
}

const char *DuplicateMovie::what() {
    return "The movie is already in the repository!";
}

const char *InvalidPositionException::what()
{
    return "The position of the movie is invalid!";
}