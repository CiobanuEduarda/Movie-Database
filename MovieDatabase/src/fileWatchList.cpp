//
// Created by E Ciobanu on 28.04.2024.
//
#include "fileWatchList.h"
#include <fstream>

void FileWatchList::openInApp() const
{
    this->writeToFile();
    std::string commandToOpenFile = "open " + this->fileName;
    system(commandToOpenFile.c_str());
}