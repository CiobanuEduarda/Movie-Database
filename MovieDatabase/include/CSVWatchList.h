//
// Created by E Ciobanu on 28.04.2024.
//

#ifndef OOP_A6_7_CIOBANUEDUARDA_CSVWATCHLIST_H_H
#define OOP_A6_7_CIOBANUEDUARDA_CSVWATCHLIST_H_H

#endif //OOP_A6_7_CIOBANUEDUARDA_CSVWATCHLIST_H_H
#pragma once
#include "fileWatchList.h"

class CSVWatchList : public FileWatchList
{
public:
    CSVWatchList(const std::string &fileName) : FileWatchList{fileName} {}
    void writeToFile() const override;
};