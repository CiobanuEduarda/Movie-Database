//
// Created by E Ciobanu on 20.05.2024.
//
#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>
#include "service.h"


#ifndef OOP_A8_9_CIOBANUEDUARDA_ADMINGUI_H
#define OOP_A8_9_CIOBANUEDUARDA_ADMINGUI_H

#endif //OOP_A8_9_CIOBANUEDUARDA_ADMINGUI_H

class AdminGUI : public QWidget{
Q_OBJECT
private:
    Service& service;
    void createTitleLayout();
    void createGenreLayout();
    void createTrailerLayout();
    void createYearReleaseLayout();
    void createNrLikesLayout();
    void createAdminButtons();
    void createTableWidget();
    Movie extractMovieInfo();
    void reloadMovie();
    void createMovieInfoLayout();
    void printAllMovies();
public:
    AdminGUI(Service& _service, QWidget* parent=nullptr);
    ~AdminGUI(){};
public slots:
    void closeButtonClicked();
    void addButtonClicked();
    void deleteButtonClicked();
    void updateButtonClicked();
    // void closeButtonClicked();
signals:
    void CloseAdminWindow();
private:
    QVBoxLayout *mainAdminLayout;
    QHBoxLayout *moviesInfoLayout;
    QVBoxLayout *moviesInfo;
    QLabel *adminTitle;
    QHBoxLayout *buttonsLayout;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;

    QHBoxLayout *titleLayout;
    QLabel *titleLabel;
    QLineEdit *titleInput;
    QHBoxLayout *genreLayout;
    QLabel *genreLabel;
    QLineEdit *genreInput;
    QHBoxLayout *trailerLayout;
    QLabel *trailerLabel;
    QLineEdit *trailerInput;

    QHBoxLayout *yearLayout;
    QLabel *yearLabel;
    QLineEdit *yearInput;
    QLabel *likesLabel;
    QLineEdit *likesInput;

    QHBoxLayout *likesLayout;
    QTableWidget *moviesTable;
    QPushButton *backButton;
    QPushButton *printButton;
};