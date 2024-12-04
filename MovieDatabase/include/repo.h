//
// Created by E Ciobanu on 23.03.2024.
//

#ifndef OOP_A4_5_CIOBANUEDUARDA_REPO_H
#define OOP_A4_5_CIOBANUEDUARDA_REPO_H

#endif //OOP_A4_5_CIOBANUEDUARDA_REPO_H
#pragma once
#include "movie.h"
//#include "exceptions.h"

class Repo{
private:

    std :: vector<Movie> movies;
   // std :: vector<Movie>watchListMovie;
public:
    Repo();
    ~Repo();
    void addMovieRepo( Movie &movie) ;
    int checkIfMovieExist(Movie &movie) ;
    std :: vector<Movie> getAllMovies();
    std :: vector<Movie> getMoviesByGenre(std::string genre);
    int getSize();
    void  deleteMovieByPosition(int index);
    void updateMovie(int index,Movie &movie);
    void readMovie();
    void writeMovie();
    void incrementLikes(const Movie& movie);


};