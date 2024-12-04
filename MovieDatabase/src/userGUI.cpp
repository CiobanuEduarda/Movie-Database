#include <QInputDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QDebug>
#include <QStyledItemDelegate>
#include "userGUI.h"
#include "watchListModel.h"

UserGUI::UserGUI(Service& service, QWidget* parent)
        : QWidget(parent), service(service) {
    this->buildGUI();
    this->connectSignalsAndSlots();
   // connect(model, &WatchListModel::watchlistUpdated, this, &UserGUI::updateTableView);
}

void UserGUI::buildGUI() {
    model = new WatchListModel(service, this);
    tableView = new QTableView(this);
    tableView->setModel(model);

    searchButton = new QPushButton("Search", this);
    nextButton = new QPushButton("Next", this);
    addToWatchlistButton = new QPushButton("Add to Watchlist", this);
    deleteButton = new QPushButton("Delete from Watchlist", this);
    saveWatchlistButton = new QPushButton("Save Watchlist", this);
    viewWatchlistFileButton = new QPushButton("View Watchlist File", this);
    genreLineEdit = new QLineEdit(this);
    moviesListWidget = new QListWidget(this);
    fileTypeComboBox = new QComboBox(this);
    fileTypeComboBox->addItems({"html", "csv"});

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(genreLineEdit);
    layout->addWidget(searchButton);
    layout->addWidget(nextButton);
    layout->addWidget(addToWatchlistButton);
    layout->addWidget(deleteButton);
    layout->addWidget(saveWatchlistButton);
    layout->addWidget(viewWatchlistFileButton);
    layout->addWidget(moviesListWidget);
    layout->addWidget(fileTypeComboBox);
    layout->addWidget(tableView);
    this->setLayout(layout);
}

void UserGUI::connectSignalsAndSlots() {
    connect(searchButton, &QPushButton::clicked, this, &UserGUI::searchMovies);
    connect(nextButton, &QPushButton::clicked, this, &UserGUI::nextMovie);
    connect(addToWatchlistButton, &QPushButton::clicked, this, &UserGUI::addToWatchlist);
    connect(deleteButton, &QPushButton::clicked, this, &UserGUI::deleteFromWatchlist);
    connect(saveWatchlistButton, &QPushButton::clicked, this, &UserGUI::saveWatchlist);
    connect(viewWatchlistFileButton, &QPushButton::clicked, this, &UserGUI::viewWatchlistFile);
}

void UserGUI::saveWatchlist() {
    QString fileType = fileTypeComboBox->currentText();
    QString filename = "watchlist." + fileType;
    qDebug() << "Saving watchlist to file:" << filename << "with type:" << fileType;
    service.saveWatchlistToFile(filename.toStdString(), fileType.toStdString());
}

void UserGUI::viewWatchlistFile() {
    QString fileType = fileTypeComboBox->currentText();
    QString filename = "watchlist." + fileType;
    qDebug() << "Opening watchlist file:" << filename << "with type:" << fileType;
    service.openWatchlistFile(filename.toStdString(), fileType.toStdString());
}

void UserGUI::searchMovies() {
    QString genre = genreLineEdit->text();
    qDebug() << "Searching movies for genre:" << genre;
    currentMovies = service.getMoviesByGenre(genre.toStdString());
    currentMovieIndex = 0;

    if (currentMovies.empty()) {
        qDebug() << "No movies found.";
        moviesListWidget->clear();
        moviesListWidget->addItem("No movies found.");
    } else {
        displayCurrentMovie();
    }
}

void UserGUI::displayCurrentMovie() {
    if (currentMovies.empty()) {
        qDebug() << "No movies to display.";
        moviesListWidget->clear();
        moviesListWidget->addItem("No movies found.");
        return;
    }

    const Movie& movie = currentMovies[currentMovieIndex];
    qDebug() << "Displaying movie:" << QString::fromStdString(movie.getTitle());

    moviesListWidget->clear();
    moviesListWidget->addItem(QString::fromStdString(movie.getTitle()));
    moviesListWidget->addItem(QString::fromStdString(movie.getGenre()));
    moviesListWidget->addItem(QString::number(movie.getYearRelease()));
    moviesListWidget->addItem(QString::number(movie.getLikes()));

    QString command = QString::fromStdString("open " + movie.getTrailer());
    system(command.toStdString().c_str());
}

void UserGUI::nextMovie() {
    if (!currentMovies.empty()) {
        currentMovieIndex = (currentMovieIndex + 1) % currentMovies.size();
        qDebug() << "Next movie index:" << currentMovieIndex;
        displayCurrentMovie();
    }
}

void UserGUI::addToWatchlist() {
    if (!currentMovies.empty()) {
        qDebug() << "Adding movie to watchlist:" << QString::fromStdString(currentMovies[currentMovieIndex].getTitle());
        service.addMovieWatchList(currentMovies[currentMovieIndex]);
        model->refresh();  // Refresh the table view after adding a movie
    }
}


void UserGUI::deleteFromWatchlist() {
    if (watchlistWidget->count() == 0) {
        QMessageBox::warning(this, "Delete Movie", "Watchlist is empty.");
        return;
    }

    bool ok;
    int index = QInputDialog::getInt(this, tr("Delete Movie"),
                                     tr("Enter the index of the movie to delete:"), 0, 0, watchlistWidget->count() - 1, 1, &ok);
    if (!ok) {
        return; // User canceled the input dialog
    }

    QString movieTitle = watchlistWidget->item(index)->text();

    // Confirm deletion
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Movie",
                                  QString("Do you want to delete the movie '%1' from your watchlist?").arg(movieTitle),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Ask if the user wants to like the movie before deletion
        bool likeMovie = QMessageBox::question(this, "Rate Movie", "Do you want to like this movie?",
                                               QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes;

        // Get the movie object before deleting
        try {
            Movie movieToDelete = service.getMovieFromWatchlist(index);

            // Delete the movie from the watchlist
            service.deleteMovieByPositionWL(index);

            // Increment likes if the user chose to like the movie
            if (likeMovie) {
                service.incrementLikes(movieToDelete);
            }

            // Update the watchlist display
            refreshWatchlist();
        } catch (const std::exception& e) {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}

void UserGUI::updateWatchlistDisplay() {
    watchlistWidget->clear();
    std::vector<Movie> watchlist = service.getAllMoviesWatchList();
    for (const auto& movie : watchlist) {
        watchlistWidget->addItem(QString::fromStdString(movie.getTitle()));
    }
}

void UserGUI::refreshWatchlist() {
    watchlistWidget->clear();
    auto watchlistMovies = service.getAllMoviesWatchList();
    for (const auto& movie : watchlistMovies) {
        watchlistWidget->addItem(QString::fromStdString(movie.getTitle()));
    }
}

void UserGUI::updateTableView() {

    model->refresh();
}