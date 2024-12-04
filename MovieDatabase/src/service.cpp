//
// Created by E Ciobanu on 23.03.2024.
//
#include <random>
#include "service.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

Service ::Service() {
    this->repo= Repo();
    //this->generateRandomMovies();
    // this->watchListMovie= nullptr;
    this->watchList= nullptr;
}

Service :: ~Service(){
    //delete this->watchListMovie;
    delete this->watchList;


}

void Service::generateRandomMovies() {
    std::vector<std::string> titles = {
            "The Matrix", "Inception", "The Shawshank Redemption", "Pulp Fiction", "The Godfather", "Fight Club", "Forrest Gump",
            "The Dark Knight", "The Lord of the Rings", "Interstellar", "The Silence of the Lambs", "Schindler's List", "The Green Mile",
            "Goodfellas", "The Departed", "The Usual Suspects", "Gladiator", "The Prestige", "Braveheart", "Se7en", "The Lion King",
            "The Godfather: Part II", "The Avengers", "Avatar", "The Sixth Sense", "Jurassic Park", "Saving Private Ryan", "Titanic",
            "The Terminator", "Die Hard"
    };

    std::vector<std::string> genres = {"Action", "Sci-Fi", "Drama", "Crime", "Adventure"};

    std::mt19937 rng(time(nullptr));
    std::uniform_int_distribution<int> yearDistribution(1980, 2023);
    std::uniform_int_distribution<int> nr_likes(1, 1000);
    std::uniform_int_distribution<int> trailer_nr(100000, 999999);

    for (int i = 0; i < 10; ++i) {
        Movie movie;
        std::string trailer = "https://www.youtube.com/watch?v=" + std::to_string(trailer_nr(rng));
        movie = Movie(titles[rng() % titles.size()], genres[rng() % genres.size()], trailer, yearDistribution(rng), nr_likes(rng));
        addMovieService(movie);
    }
}

int Service ::addMovieService(Movie movie) {
    if (this->repo.checkIfMovieExist(movie)!=-1)
        return 0;
    this->repo.addMovieRepo(movie);
    return 1;
}

std :: vector<Movie> Service :: getAllMovies(){
    return this->repo.getAllMovies();
}
std :: vector<Movie> Service:: getAllMoviesWatchList(){
    return watchlist;
}
int Service :: getSize(){
    return this->repo.getSize();
}
int Service :: getSizeWL(){
    return this->watchlist.size();


}
//void Service :: deleteMovieByPosition(int index){
//    this->repo.deleteMovieByPosition(index);
//}

void Service :: deleteMovieByPositionWL(int index){
    if (index >= 0 && index < watchlist.size()) {
        watchlist.erase(watchlist.begin() + index);
    }
}
void Service :: updateMovie(int index,Movie &movie){
    this->repo.updateMovie(index,movie);
}

//std :: vector<Movie> Service::getMoviesByGenre(std::string genre) {
//    return this->repo.getMoviesByGenre(genre);
//}

void Service::openTrailerOfMovie(Movie genreMovies){
    std :: string link=genreMovies.getTrailer();
    std::string commandToOpenTheLinkInBrowser = "open " + link;
    system(commandToOpenTheLinkInBrowser.c_str());
}

void Service::addMovieWatchList(const Movie& movie) {
    watchlist.push_back(movie);
    std::cout << "Movie added to watchlist: " << movie.getTitle() << std::endl;
}

std::vector<Movie> Service::getMoviesByGenre(const std::string& genre) {
    if (genre.empty()) {
        return repo.getAllMovies();
    }
    std::vector<Movie> filteredMovies;
    for (const auto& movie : repo.getAllMovies()) {
        if (movie.getGenre() == genre) {
            filteredMovies.push_back(movie);
        }
    }
    return filteredMovies;
}

//void Service::setLike(int i) {
//    this->repo.setLike(i);
//}

void Service::readMovie() {
    this->repo.readMovie();

}


void Service::writeMovie() {
    this->repo.writeMovie();

}

void Service::setTypeOfWatchList(FileWatchList *watchList)
{
    this->watchList = watchList;
}

void Service::displayPlaylist()
{
    this->watchList->openInApp();
}

void Service::saveWatchlistToFile(const std::string& filename, const std::string& filetype) {
    std::ofstream file;
    file.open(filename);

    if (filetype == "csv") {
        for (const Movie& movie : watchlist) {
            file << movie.getTitle() << "," << movie.getGenre() << ","
                 << movie.getYearRelease() << "," << movie.getLikes() << ","
                 << movie.getTrailer() << "\n";
        }
    } else if (filetype == "html") {
        file << "<html><body><table border=\"1\"><tr><th>Title</th><th>Genre</th><th>Year</th><th>Likes</th><th>Trailer</th></tr>";
        for (const Movie& movie : watchlist) {
            file << "<tr><td>" << movie.getTitle() << "</td><td>" << movie.getGenre() << "</td><td>"
                 << movie.getYearRelease() << "</td><td>" << movie.getLikes() << "</td><td>"
                 << "<a href=\"" << movie.getTrailer() << "\">Watch</a></td></tr>";
        }
        file << "</table></body></html>";
    }

    file.close();
}

void Service::openWatchlistFile(const std::string& filename, const std::string& filetype) {
    std::string command;

    if (filetype == "csv") {
        command = "open -a TextEdit " + filename;
    } else if (filetype == "html") {
        command = "open " + filename;
    }

    system(command.c_str());
}

void Service::incrementLikes(const Movie& movie) {
    for (auto& m : repo.getAllMovies()) {
        if (m == movie) {
            m.setLikes(m.getLikes() + 1);
            repo.writeMovie(); // Save changes
            return;
        }
    }
}

void Service::deleteMovieByPosition(int index) {
    if (index >= 0 && index < watchlist.size()) {
        watchlist.erase(watchlist.begin() + index);
    }
}

Movie Service::getMovieByPosition(int index) {
    if (index >= 0 && index < watchlist.size()) {
        return watchlist[index];
    }
    // Return a default constructed Movie or handle the error as needed
    return Movie();
}

Movie Service::getMovieFromWatchlist(int index) {
    if (index < 0 || index >= watchlist.size()) {
        throw std::out_of_range("Invalid movie index");
    }
    return watchlist[index];
}