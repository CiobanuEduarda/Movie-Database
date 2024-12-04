//
// Created by E Ciobanu on 20.05.2024.
//


#include <QMessageBox>
#include <QInputDialog>
#include "adminGUI.h"

AdminGUI::AdminGUI(Service &_service, QWidget *parent) : QWidget(parent), service(_service) {
    // Set up the main layout
    this->mainAdminLayout = new QVBoxLayout(this);

    // Create and add the title label
    this->adminTitle = new QLabel("Welcome to Admin Mode!", this);
    this->adminTitle->setAlignment(Qt::AlignHCenter);
    this->mainAdminLayout->addWidget(this->adminTitle);

    // Create the movie info layout and input fields
    this->createMovieInfoLayout();

    // Add the movie info layout to the main layout
    this->mainAdminLayout->addLayout(this->moviesInfoLayout);

    // Create and add the admin buttons
    this->createAdminButtons();

    // Add the buttons layout to the main layout
    this->mainAdminLayout->addLayout(this->buttonsLayout);

    // Create and add the back button
    this->backButton = new QPushButton("Exit", this);
    connect(this->backButton, &QPushButton::clicked, this, &AdminGUI::closeButtonClicked);
    this->mainAdminLayout->addWidget(this->backButton, 0, Qt::AlignRight);

    // Set the fixed size of the widget
    this->setFixedSize(1200, 270);
}
void AdminGUI::createMovieInfoLayout() {
    this->moviesInfoLayout = new QHBoxLayout;
    this->moviesInfo = new QVBoxLayout;

    // Create the input fields
    this->createTitleLayout();
    this->createGenreLayout();
    this->createTrailerLayout();
    this->createYearReleaseLayout();
    this->createNrLikesLayout();

    // Add the input fields to the movie info layout
    this->moviesInfo->addLayout(this->titleLayout);
    this->moviesInfo->addLayout(this->genreLayout);
    this->moviesInfo->addLayout(this->trailerLayout);
    this->moviesInfo->addLayout(this->yearLayout);
    this->moviesInfo->addLayout(this->likesLayout);

    // Add the movie info layout to the horizontal layout
    this->moviesInfoLayout->addLayout(this->moviesInfo);
}
void AdminGUI::closeButtonClicked() {
    emit CloseAdminWindow();
}
void  AdminGUI::createAdminButtons() {

    this->buttonsLayout = reinterpret_cast<QHBoxLayout *>(new QVBoxLayout);
    this->addButton = new QPushButton("Add Movie", this);
    connect(this->addButton, &QPushButton::clicked, this, &AdminGUI::addButtonClicked);
    this->deleteButton = new QPushButton("Delete Movie", this);
    connect(this->deleteButton, &QPushButton::clicked, this, &AdminGUI::deleteButtonClicked);
    this->updateButton = new QPushButton("Update Movie", this);
    connect(this->updateButton, &QPushButton::clicked, this, &AdminGUI::updateButtonClicked);
    this->printButton = new QPushButton("Print All Movies", this);
    connect(this->printButton, &QPushButton::clicked, this, &AdminGUI::printAllMovies);
    this->buttonsLayout->addWidget(this->addButton);
    this->buttonsLayout->addWidget(this->deleteButton);
    this->buttonsLayout->addWidget(this->updateButton);
    this->buttonsLayout->addWidget(this->printButton);
}



void AdminGUI::createTitleLayout() {
    this->titleLayout=new QHBoxLayout;
    this->titleLabel=new QLabel("Enter title");
    this->titleInput=new QLineEdit(this);
    this->titleLayout->addWidget(this->titleLabel);
    this->titleLayout->addWidget(this->titleInput);


}

void AdminGUI::createGenreLayout() {
    this->genreLayout=new QHBoxLayout;
    this->genreLabel=new QLabel("Enter genre");
    this->genreInput=new QLineEdit(this);
    this->genreLayout->addWidget(this->genreLabel);
    this->genreLayout->addWidget(this->genreInput);


}

void AdminGUI::createTrailerLayout() {
    this->trailerLayout=new QHBoxLayout;
    this->trailerLabel=new QLabel("Enter trailer");
    this->trailerInput=new QLineEdit(this);
    this->trailerLayout->addWidget(this->trailerLabel);
    this->trailerLayout->addWidget(this->trailerInput);


}
void AdminGUI::createYearReleaseLayout() {
    this->yearLayout=new QHBoxLayout;
    this->yearLabel=new QLabel("Enter year");
    this->yearInput=new QLineEdit(this);
    this->yearLayout->addWidget(this->yearLabel);
    this->yearLayout->addWidget(this->yearInput);


}
void AdminGUI::createNrLikesLayout()  {
    this->likesLayout=new QHBoxLayout;
    this->likesLabel=new QLabel("Enter likes");
    this->likesInput=new QLineEdit(this);
    this->likesLayout->addWidget(this->likesLabel);
    this->likesLayout->addWidget(this->likesInput);


}

void AdminGUI::createTableWidget() {
    this->moviesTable=new QTableWidget;
    QStringList header={"Title", "Genre" ,"Trailer", "Year Release" , "Nr likes"};
    this->moviesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->moviesTable->setColumnCount(5);
    this->moviesTable->setColumnWidth(0, 80);
    this->moviesTable->setColumnWidth(1, 60);
    this->moviesTable->setColumnWidth(2, 60);
    this->moviesTable->setColumnWidth(3, 60);
    this->moviesTable->setColumnWidth(4, 300);
    this->moviesTable->setHorizontalHeaderLabels(header);

    std::vector<Movie> movies = this->service.getAllMovies();
    for (auto movie : movies)
    {
        int rowCount = this->moviesTable->rowCount();
        this->moviesTable->insertRow(rowCount);
        this->moviesTable->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(movie.getTitle())));
        this->moviesTable->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
        this->moviesTable->setItem(rowCount, 2, new QTableWidgetItem(QString::fromStdString(movie.getTrailer())));
        this->moviesTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(movie.getYearRelease())));
        this->moviesTable->setItem(rowCount, 4, new QTableWidgetItem(QString::number(movie.getLikes())));
    }


}


void AdminGUI::addButtonClicked() {
    QString title = this->titleInput->text();
    QString genre = this->genreInput->text();
    QString trailer = this->trailerInput->text();
    int year = this->yearInput->text().toInt();
    int likes = this->likesInput->text().toInt();
    Movie movie = Movie(title.toStdString(), genre.toStdString(), trailer.toStdString(), year, likes);

    try {
        this->service.addMovieService(movie);
        QMessageBox::information(this, "Success", "Movie added successfully!");
    } catch (const DuplicateMovie &e) {
        QMessageBox::warning(this, "Error", "Movie already exists!");
    }
}

void AdminGUI::deleteButtonClicked() {
    bool ok;
    int index = QInputDialog::getInt(this, "Delete Movie", "Enter the movie position:", 0, 0, service.getSize() - 1, 1, &ok);
    if (ok) {
        this->service.deleteMovieByPosition(index);
        QMessageBox::information(this, "Success", "Movie deleted successfully!");
    }
}

void AdminGUI::updateButtonClicked() {
    bool ok;
    int index = QInputDialog::getInt(this, "Update Movie", "Enter the movie position:", 0, 0, service.getSize() - 1, 1, &ok);
    if (ok) {
        QString title = this->titleInput->text();
        QString genre = this->genreInput->text();
        QString trailer = this->trailerInput->text();
        int year = this->yearInput->text().toInt();
        int likes = this->likesInput->text().toInt();

        Movie movie = Movie(title.toStdString(), genre.toStdString(), trailer.toStdString(), year, likes);
        this->service.updateMovie(index, movie);
        QMessageBox::information(this, "Success", "Movie updated successfully!");
    }
}

Movie AdminGUI::extractMovieInfo()  {
    QString title = this->titleInput->text();
    QString genre = this->genreInput->text();
    QString trailer = this->trailerInput->text();
    QString year = this->yearInput->text();
    QString likes = this->likesInput->text();

    int yearInt = year.toInt();
    int likesInt = likes.toInt();

    Movie movie{title.toStdString(), genre.toStdString(), trailer.toStdString(),yearInt,likesInt};

    return movie;
}
void AdminGUI::printAllMovies() {

    std::vector<Movie> movies = this->service.getAllMovies();
    QString movieList;
    int i=0;
    for (const auto &movie : movies) {

        movieList += QString::fromStdString(std::to_string(i) + " " +movie.getTitle() + " (" + movie.getGenre() + movie.getTrailer()+", " + std::to_string(movie.getYearRelease()) + ", " + std::to_string(movie.getLikes()) + " likes)\n");
        i++;
    }
    QMessageBox::information(this, "All Movies", movieList);
}
void AdminGUI::reloadMovie() {
    this->moviesTable->setRowCount(0);
    std::vector<Movie> movies = this->service.getAllMovies();
    for (auto movie:movies)
    {

        int rowCount = this->moviesTable->rowCount();
        this->moviesTable->insertRow(rowCount);
        this->moviesTable->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(movie.getTitle())));
        this->moviesTable->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
        this->moviesTable->setItem(rowCount, 2, new QTableWidgetItem(QString::fromStdString(movie.getTrailer())));
        this->moviesTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(movie.getYearRelease())));
        this->moviesTable->setItem(rowCount, 4, new QTableWidgetItem(QString::number(movie.getLikes())));
    }
}
