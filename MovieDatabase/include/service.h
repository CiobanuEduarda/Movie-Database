//
// Created by E Ciobanu on 23.03.2024.
//



#ifndef OOP_A4_5_CIOBANUEDUARDA_SERVICE_H
#define OOP_A4_5_CIOBANUEDUARDA_SERVICE_H

#endif //OOP_A4_5_CIOBANUEDUARDA_SERVICE_H

#pragma once
#include "repo.h"
#include "fileWatchList.h"
#include "watchList.h"

class Service{
private:
    Repo repo;
    FileWatchList *watchList;
    std::vector<Movie> watchlist;
public:

    Service();
    ~Service();
    void generateRandomMovies();
    int addMovieService(Movie movie);
    std :: vector<Movie>  getAllMovies();
    std :: vector<Movie> getMoviesByGenre(const std::string& genre);
    int  getSize();
    int getSizeWL();
    void deleteMovieByPosition(int index);
    void updateMovie(int index,Movie &movie);
    void openTrailerOfMovie(Movie genreMovies);
    void addMovieWatchList(const Movie& movie);
    std :: vector<Movie>getAllMoviesWatchList();
    void  deleteMovieByPositionWL(int index);
    void readMovie();
    void writeMovie();
    void displayPlaylist();

    void setTypeOfWatchList(FileWatchList *watchList);
    void saveWatchlistToFile(const std::string& filename, const std::string& filetype);
    void openWatchlistFile(const std::string& filename, const std::string& filetype);
    void incrementLikes(const Movie& movie);
    Movie getMovieByPosition(int index);
    Movie getMovieFromWatchlist(int index);


    //void setLike(int i);


};