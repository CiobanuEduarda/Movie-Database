//
// Created by E Ciobanu on 28.04.2024.
//
#include "HTMLWatchList.h"
#include "exceptions.h"
#include <fstream>

void HTMLWatchList::writeToFile() const
{
    std::ofstream HTMLOutputFile(this->fileName.c_str());


    HTMLOutputFile << "<!DOCTYPE html> <html> <head> <title> Movie WatchList</title> </head > <body> <table border=\"1\">";
    HTMLOutputFile << "<tr> <td> Index </td> <td> Title </td> <td> Genre </td> <td> Year Of Release </td> <td> Likes Count </td> <td> Trailer </td> </tr>";
    int index = 0;
    for (auto movie : this->watchListMovie)
        HTMLOutputFile << "<tr> <td>" << index++ << "</td> <td>" << movie.getTitle() << "</td> <td>" << movie.getGenre() << "</td> <td>" << movie.getYearRelease() << "</td> <td>" << movie.getLikes() << "</td> <td><a href=\"" << movie.getTrailer() << "\"> Link</a></ td> </tr>";

    HTMLOutputFile << "</table> </body> </html>";

    HTMLOutputFile.close();
}