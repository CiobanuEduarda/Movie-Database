//
// Created by E Ciobanu on 23.03.2024.
//
#pragma once
#include <iostream>
#ifndef OOP_A4_5_CIOBANUEDUARDA_DOMAIN_H
#define OOP_A4_5_CIOBANUEDUARDA_DOMAIN_H

#endif //OOP_A4_5_CIOBANUEDUARDA_DOMAIN_H
#include "exceptions.h"
class Movie
{
    private:
        std::string title,genre,trailer;
        int year_release,nr_likes;

    public:

    Movie(const std::string &title = "", const std::string &genre = "", const std::string &trailer = "", int year_release=0,int likes=0);
    ~Movie();
    Movie(const Movie &movie);
    Movie &operator=(const Movie &movie);
   // bool operator==(const Movie &movie) const;
    std :: string getTitle() const;
    std::string getGenre() const;
    std::string getTrailer() const;
    int getYearRelease() const;
    int getLikes() const;
    void setTitle(const std::string &title);
    void setGenre(const std::string &genre);
    void setTrailer(const std::string &trailer);
    void setYearRelease(int yea_release);
    //void setLikes(int like);
    static void validateYear(int year);
    static void validateLikes(int nr_likes);
    void validate_trailer(const std::string& trailer);
    friend std::ostream& operator<<(std::ostream& os, const Movie &m);
    friend std::istream& operator>>(std::istream& is,Movie &m);
    bool operator==(const Movie& other) const;
    void setLikes(int newLikes);


};

