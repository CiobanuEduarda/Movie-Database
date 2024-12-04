//
// Created by E Ciobanu on 20.05.2024.
//

#ifndef OOP_A8_9_CIOBANUEDUARDA_USERGUI_H
#define OOP_A8_9_CIOBANUEDUARDA_USERGUI_H
#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QStackedWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QListWidget>
#include "service.h"
#endif //OOP_A8_9_CIOBANUEDUARDA_USERGUI_H

#include "watchListModel.h"

class UserGUI :  public QWidget  {
Q_OBJECT

public:
    UserGUI(Service &service, QWidget *parent = nullptr);

private:
    Service &service;
    QLineEdit *genreLineEdit;
    QPushButton *searchButton;
    QListWidget *moviesListWidget;
    QPushButton *nextButton;
    QPushButton *addToWatchlistButton;
    QListWidget *watchlistWidget;
    QPushButton *deleteButton;
    QPushButton *showWatchlistButton;
    QComboBox *fileTypeComboBox;
    QPushButton *saveWatchlistButton;
    QPushButton *viewWatchlistFileButton;
    int currentMovieIndex;
    std::vector<Movie> currentMovies;
    WatchListModel* model;
    QTableView* tableView;
    void buildGUI();
    void connectSignalsAndSlots();
    void displayCurrentMovie();

private slots:
    void searchMovies();
    void nextMovie();
    void addToWatchlist();
    void deleteFromWatchlist();
    //void showWatchlist();
    void saveWatchlist();
    void viewWatchlistFile();
    void updateWatchlistDisplay();
    void refreshWatchlist();
    void updateTableView();

};