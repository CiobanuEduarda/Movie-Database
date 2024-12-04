//
// Created by E Ciobanu on 13.05.2024.
//

#ifndef OOP_A8_9_CIOBANUEDUARDA_MAINWINDOW_H
#define OOP_A8_9_CIOBANUEDUARDA_MAINWINDOW_H

#include "service.h"
#include "adminGUI.h"
#include "userGUI.h"

#include <QMainWindow>
#include <QStackedWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

namespace CONSTANTS
{
    const std::string FILENAME = "movies.txt";
    const int INITIAL_WIDTH = 300;
    const int INITIAL_HEIGHT = 300;
    const int ADMIN_WIDTH = 1500;
    const int ADMIN_HEIGHT = 400;
    const int USER_WIDTH = 800;
    const int USER_HEIGHT = 400;
    const int ADMIN_LAYOUT_INDEX = 1;
    const int USER_LAYOUT_INDEX = 2;
}

class GUI : public QMainWindow
{
Q_OBJECT

public:
    GUI(Service &_service, QWidget *parent = nullptr);
    ~GUI();

private slots:
    void openAdminWindow();
    void openUserWindow();
    void openMainWindow();

private:
    void buildGUI();
    void setUpChooseMode();

    Service &service;

    QStackedWidget *mainWidget;
    QWidget *chooseModeWidget;
    QVBoxLayout *chooseModeLayout;
    QLabel *chooseModeLabel;
    QPushButton *adminButton;
    QPushButton *userButton;
    AdminGUI *adminWindow;
    UserGUI *userWindow;
};

#endif // OOP_A8_9_CIOBANUEDUARDA_MAINWINDOW_H