#include "CSVWatchList.h"
#include "exceptions.h"
#include <fstream>

void CSVWatchList::writeToFile() const
{
    std::ofstream CSVOutputFile(this->fileName.c_str());



    CSVOutputFile << "Index, Name, Genre, Year Of Release, Trailer, Likes Count\n";
    int index = 0;
    for (auto movie : this->watchListMovie)
        CSVOutputFile << index++ << ", " << movie.getTitle() << "," << movie.getGenre() << "," << movie.getYearRelease() << "," << movie.getTrailer() << "," << movie.getLikes() << "\n";

    CSVOutputFile.close();
}