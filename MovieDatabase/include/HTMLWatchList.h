//
// Created by E Ciobanu on 28.04.2024.
//

#ifndef OOP_A6_7_CIOBANUEDUARDA_HTMLWATCHLIST_H
#define OOP_A6_7_CIOBANUEDUARDA_HTMLWATCHLIST_H

#endif //OOP_A6_7_CIOBANUEDUARDA_HTMLWATCHLIST_H
#pragma once
#include "fileWatchList.h"

class HTMLWatchList : public FileWatchList
{
public:
    HTMLWatchList(const std::string &fileName) : FileWatchList{fileName} {}
    void writeToFile() const override;
};