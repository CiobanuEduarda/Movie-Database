
#include "movie.h"
#include <stdexcept>
#include <regex>
#include <sstream>

using namespace std;

Movie::Movie(const std::string &title,const std::string &genre, const std::string &trailer, int year_release, int nr_likes){
    this->title=title;
    this->genre=genre;
    this->trailer=trailer;
    this->year_release=year_release;
    this->nr_likes=nr_likes;
}

Movie::Movie(const Movie &movie)
{
    this->title = movie.title;
    this->genre = movie.genre;
    this->trailer = movie.trailer;
    this->year_release = movie.year_release;
    this->nr_likes = movie.nr_likes;
}

Movie :: ~Movie() = default;

// operators
Movie &Movie::operator=(const Movie &movie)
{
    if (this == &movie)
        return *this;

    this->title = movie.title;
    this->genre = movie.genre;
    this->trailer = movie.trailer;
    this->year_release = movie.year_release;
    this->nr_likes = movie.nr_likes;

    return *this;
}

//bool Movie::operator==(const Movie &movie) const
//{
//    return this->title == movie.title && this->genre == movie.genre && this->year_release == movie.year_release && this->nr_likes==movie.nr_likes;
//}

//getters

std :: string Movie :: getTitle()const
{
    return this->title;
}

std :: string Movie :: getGenre()const
{
    return this->genre;
}

std :: string Movie :: getTrailer()const
{
    return this->trailer;
}

int Movie::getLikes() const {
    return this->nr_likes;
}

int Movie::getYearRelease() const {
    return this->year_release;
}


//validators
void Movie::validateLikes(int nr_likes)
{
    if (nr_likes<0)
        throw std::invalid_argument("Likes count must be a positive integer");
}

void Movie::validateYear(int year)
{
    if (year<0)
        throw std::invalid_argument("Year of release must be a positive integer");
}

void Movie ::validate_trailer(const std::string& trailer) {
    std::regex pattern("^https://www\\.youtube\\.com/watch\\?v=\\w{1,11}$");


    if (!std::regex_match(trailer, pattern)) {
        throw std::invalid_argument("Invalid trailer link format. Trailer link must be in the format: https://www.youtube.com/watch?v=VIDEO_ID");
    }
}
//setters

void Movie::setTitle(const std::string &title)
{
    this->title = title;
}

void Movie::setGenre(const std::string &genre)
{
    this->genre = genre;
}

void Movie::setTrailer(const std::string &trailer)
{
    this->trailer = trailer;
}

//void Movie::setLikes(int like) {
//    this->validateLikes(like);
//    this->nr_likes=like;
//}

void Movie::setYearRelease(int yea_release) {
    this->validateYear(yea_release);
    this->year_release=yea_release;
}


vector<string> tokenize(string str,char delimiter){
    vector <string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;



}
std :: istream & operator >> (std :: istream & is,Movie &movie){
    string line;
    getline(is,line);

    vector<string> tokens=tokenize(line,',');


    if (tokens.size() != 5)
        return is;
    movie.setTitle(tokens[0]);
    movie.setGenre(tokens[1]);
    movie.setTrailer(tokens[2]);
    int year= stoi(tokens[3]);
    int like= stoi(tokens[4]);
    movie.setYearRelease(year);
    movie.setLikes(like);

    return is;

}

std::ostream & operator << (std::ostream & os, const Movie &movie) {
    os << movie.getTitle() << "," << movie.getGenre() << "," << movie.getTrailer() << "," << movie.getYearRelease()
       << "," << movie.getLikes() << "\n";
    return os;
}

bool Movie::operator==(const Movie& other) const {
    return title == other.title &&
           genre == other.genre &&
           year_release == other.year_release;
}

void Movie::setLikes(int newLikes) {
    nr_likes = newLikes;
}