#ifndef WATCHLISTMODEL_H
#define WATCHLISTMODEL_H

#include <QAbstractTableModel>
#include "service.h"

class WatchListModel : public QAbstractTableModel {
Q_OBJECT

public:
    explicit WatchListModel(Service& service, QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

public slots:
    void refresh();

private:
    Service& service;
};

#endif // WATCHLISTMODEL_H
