//
// Created by E Ciobanu on 28.04.2024.
//

#ifndef OOP_A6_7_CIOBANUEDUARDA_WATCHLIST_H
#define OOP_A6_7_CIOBANUEDUARDA_WATCHLIST_H

#endif //OOP_A6_7_CIOBANUEDUARDA_WATCHLIST_H

#include "movie.h"
#pragma once

class WatchList{
protected:
    std :: vector<Movie> watchListMovie;
public:
    WatchList(){};
    virtual ~WatchList() {};
    int checkIfMovieExistWL(const Movie &) ;
    std :: vector<Movie>getAllMoviesWatchList();
    int getSizeWL();
    void  deleteMovieByPositionWL(int index);
    void addMovieWatchList(const Movie &);
    //void setLike(int i);



};

