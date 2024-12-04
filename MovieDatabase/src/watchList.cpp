//
// Created by E Ciobanu on 28.04.2024.
//
#include "watchList.h"
#include "exceptions.h"



//void WatchList::setLike(int i) {
//
//    for (int index=0;index<movies.size();index++)
//    { if (movies[index]== this->watchListMovie[i])
//        {
//
//            movies[index].setLikes(int(movies[index].getLikes())+1);
//            return;
//        }
//    }
//}
int WatchList::getSizeWL() {

    return this->watchListMovie.size();
}

void WatchList :: addMovieWatchList(const Movie &movie) {
    this->watchListMovie.push_back(movie);

}


int WatchList :: checkIfMovieExistWL(const Movie &movie) {
    for (int i=0;i< this->watchListMovie.size(); i++)
    {
        if (this->watchListMovie[i] == movie)
            throw DuplicateMovie();
    }

    return -1;
}
void WatchList :: deleteMovieByPositionWL(int index){
    this->watchListMovie.erase(this->watchListMovie.begin() + index);
}

std :: vector<Movie>WatchList :: getAllMoviesWatchList() {
    return this->watchListMovie;
}


