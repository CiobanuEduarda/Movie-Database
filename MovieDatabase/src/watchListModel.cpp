#include "watchListModel.h"

WatchListModel::WatchListModel(Service& service, QObject* parent)
        : QAbstractTableModel(parent), service(service) {}

int WatchListModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return service.getSizeWL();
}

int WatchListModel::columnCount(const QModelIndex& parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return 5;
}

QVariant WatchListModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    const Movie& movie = service.getMovieByPosition(index.row());
    switch (index.column()) {
        case 0: return QString::fromStdString(movie.getTitle());
        case 1: return QString::fromStdString(movie.getGenre());
        case 2: return movie.getYearRelease();
        case 3: return movie.getLikes();
        case 4: return QString::fromStdString(movie.getTrailer());
        default: return QVariant();
    }
}

QVariant WatchListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0: return tr("Title");
            case 1: return tr("Genre");
            case 2: return tr("Year");
            case 3: return tr("Likes");
            case 4: return tr("Trailer");
            default: return QVariant();
        }
    }

    return QVariant();
}

void WatchListModel::refresh() {
    beginResetModel();
    endResetModel();
}
