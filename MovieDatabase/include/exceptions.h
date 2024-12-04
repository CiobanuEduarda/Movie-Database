//
// Created by E Ciobanu on 27.04.2024.
//

#ifndef OOP_A6_7_CIOBANUEDUARDA_EXCEPTIONS_H
#define OOP_A6_7_CIOBANUEDUARDA_EXCEPTIONS_H

#endif //OOP_A6_7_CIOBANUEDUARDA_EXCEPTIONS_H
#include <iostream>
#pragma once
class RepoException : public std::exception{
protected:
    std :: string message;
public:
    RepoException();
    RepoException(const std::string &message);
    virtual ~RepoException(){};
    virtual const char *what();
};

class DuplicateMovie : public RepoException{
public:
    const char *what();

};

class InvalidPositionException : public RepoException
{
public:
    const char *what();
};