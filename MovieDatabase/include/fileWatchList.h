//
// Created by E Ciobanu on 28.04.2024.
//

#ifndef OOP_A6_7_CIOBANUEDUARDA_FILEWATCHLIST_H
#define OOP_A6_7_CIOBANUEDUARDA_FILEWATCHLIST_H

#endif //OOP_A6_7_CIOBANUEDUARDA_FILEWATCHLIST_H

#include "watchList.h"
#pragma once

class FileWatchList : public WatchList
{
protected:
    std::string fileName;

public:
    FileWatchList(const std::string &fileName) : fileName{fileName} {}
    virtual void writeToFile() const = 0;
    void openInApp() const;
    virtual ~FileWatchList(){};
};