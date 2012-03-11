#ifndef MENU_SERVICELISTMODEL_H
#define MENU_SERVICELISTMODEL_H

#include <QAbstractTableModel>

class MenuServiceListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum
    {
        SERVICE_PRO_ENCRYPT = 0x01,
        SERVICE_PRO_FAVOR = 0x02,

        SERVICE_PRO_MAX
    }SERVICE_PRO;
    MenuServiceListModel(QObject *parent);

    QModelIndex getCurrentServiceIndex() const;
    int32_t playService(int32_t index) const;
    void updateData();

protected:
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

private:
    int32_t getServiceCount() const;
    QString getServiceName(int32_t index) const;
    int32_t getServiceProperties(int32_t index) const;
};

#endif // MENU_SERVICELISTMODEL_H
