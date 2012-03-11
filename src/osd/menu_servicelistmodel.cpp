#include "menu_servicelistmodel.h"
#include <QDebug>

MenuServiceListModel::MenuServiceListModel(QObject *parent)
    :QAbstractTableModel(parent)
{
}


int MenuServiceListModel::rowCount(const QModelIndex &parent) const
{
    return getServiceCount();
}

int MenuServiceListModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant MenuServiceListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
//    int column = index.column();

    switch (role)
    {
    case Qt::DisplayRole:
        return getServiceName(row);
        break;

    case Qt::UserRole:
        return getServiceProperties(row);
        break;

    default:
        break;
    }

    return QVariant();
}

void MenuServiceListModel::updateData()
{
    QModelIndex topLeft;
    QModelIndex bottomRight;

//    qDebug() << this->rowCount();
    topLeft = this->index(0,0);
    bottomRight = this->index(this->rowCount(),0);
    emit dataChanged(topLeft, bottomRight);
}

#ifdef Q_OS_WIN32
int32_t MenuServiceListModel::getServiceCount() const
{
    // TODO:Get service count from the service data base.
    return 50;
}
QString MenuServiceListModel::getServiceName(int32_t index) const
{
    return QString("CCTV-%1").arg(index);
}

int32_t MenuServiceListModel::getServiceProperties(int32_t index) const
{
    if (index % 5 == 0)
    {
        return SERVICE_PRO_ENCRYPT;
    }
    else if (index % 3 == 0)
    {
        return SERVICE_PRO_ENCRYPT | SERVICE_PRO_FAVOR;
    }
    else
    {
        return 0;
    }
}
QModelIndex MenuServiceListModel::getCurrentServiceIndex() const
{
    int curServiceIndex;

    // TODO: change the current service index;
    curServiceIndex = 45;

    qDebug() << "current line:" << curServiceIndex;


    return this->index(curServiceIndex,0);
}

int32_t MenuServiceListModel::playService(int32_t index) const
{
    int32_t result = -1;
    qDebug() << "play service:" << index;

    result = 0;
    return result;
}
#else
#endif
