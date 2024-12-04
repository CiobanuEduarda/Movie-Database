
//
// Created by E Ciobanu on 23.03.2024.
//
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication mainApplication(argc, argv);
//    QCoreApplication::setApplicationName("Movie Rental");

    Service service;
    GUI gui{service};
    gui.show();
    return mainApplication.exec();
}

