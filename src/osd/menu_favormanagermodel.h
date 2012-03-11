#ifndef MENU_FAVORMANAGERMODEL_H
#define MENU_FAVORMANAGERMODEL_H

#include <QAbstractTableModel>
#include <QVariant>

class MenuFavorManagerModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum
    {
        SERVICE_PRO_ENCRYPT = 0x01,
        SERVICE_PRO_FAVOR = 0x02,

        SERVICE_PRO_MAX
    }SERVICE_PRO;
    MenuFavorManagerModel(QObject *parent);

    bool removeRows(int row, int count, const QModelIndex &parent);
    bool insertRows(int row, int count, const QModelIndex &parent);
    void updateData();

protected:
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

private:
    int getServiceCount() const;
    QString getServiceName(int32_t index) const;
    int getServiceProperties( int32_t index) const;
};

#endif // MENU_FAVORMANAGERMODEL_H
