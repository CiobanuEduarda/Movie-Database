//
// Created by E Ciobanu on 23.03.2024.
//


#include "repo.h"
#include <fstream>
#include <iostream>
using namespace std;

Repo :: Repo() {
    this->movies=std :: vector<Movie>();
    this->readMovie();


}

Repo :: ~Repo()= default;

void Repo::readMovie ()
{
    ifstream f("Movie.txt");
    if (!f.is_open())
        return;

    movies.clear();
    Movie movie{};
    while (f >> movie)
    {

        this->movies.push_back(movie);
    }

    f.close();
}

void Repo::writeMovie()
{
    ofstream f("Movie.txt");
    if (!f.is_open())
        return;



    vector<Movie> movies = this->getAllMovies();

    for (const auto& movie : movies)
    {
        f << movie;

    }

    f.close();
}
int Repo:: checkIfMovieExist(Movie &movie) {
    for (int i=0;i< this->movies.size();i++)
    {
        if (this->movies[i]==movie)
            throw DuplicateMovie();
    }

    return -1;
}

//int Repo:: checkIfMovieExistWL(Movie &movie) {
//    for (int i=0;i< this->watchListMovie.size();i++)
//    {
//        if (this->watchListMovie[i]==movie)
//            throw DuplicateMovie();
//    }
//
//    return -1;
//}

void Repo ::addMovieRepo(Movie &movie) {
    this->movies.push_back(movie);
    this->writeMovie();

}

//void Repo ::addMovieWatchList(Movie &movie) {
//    this->watchListMovie.push_back(movie);
//
//}
std :: vector<Movie> Repo :: getAllMovies() {
    return this->movies;
}
//std :: vector<Movie> Repo :: getAllMoviesWatchList() {
//    return this->watchListMovie;
//}


void Repo :: deleteMovieByPosition(int index){
    this->movies.erase(this->movies.begin()+index);
    this->writeMovie();
}
//void Repo :: deleteMovieByPositionWL(int index){
//    this->watchListMovie.erase(this->watchListMovie.begin()+index);
//}
void Repo :: updateMovie(int index,Movie &movie){
    this->movies[index]=movie;
    this->writeMovie();
}

std :: vector<Movie> Repo::getMoviesByGenre(std::string genre) {
    std :: vector<Movie> genreMovies;
    for (auto & movie : this->movies)
        if (movie.getGenre()==genre)
            genreMovies.push_back(movie);
    return genreMovies;

}

//void Repo::setLike(int i) {
//
//    for (int index=0;index<this->movies.size();index++)
//    { if (this->movies[index]== this->watchListMovie[i])
//        {
//
//            movies[index].setLikes(int(movies[index].getLikes())+1);
//            return;
//        }
//        }
//}

int Repo::getSize() {
    return this->movies.size();
}
//
//int Repo::getSizeWL() {
//    return this->watchListMovie.size();
//}


void Repo::incrementLikes(const Movie& movie) {
    for (auto& m : movies) {
        if (m == movie) {
            m.setLikes(m.getLikes() + 1);
            return;
        }
    }
}

