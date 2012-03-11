#include "menu_favormanagermodel.h"

#include <QDebug>

MenuFavorManagerModel::MenuFavorManagerModel(QObject *parent)
    :QAbstractTableModel(parent)
{
}

int MenuFavorManagerModel::rowCount(const QModelIndex &parent) const
{
    return getServiceCount();
}

int MenuFavorManagerModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}
QVariant MenuFavorManagerModel::data(const QModelIndex &index, int role) const
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

void MenuFavorManagerModel::updateData()
{
    QModelIndex topLeft;
    QModelIndex bottomRight;

//    qDebug() << this->rowCount();
    topLeft = this->index(0,0);
    bottomRight = this->index(this->rowCount(),0);
    emit dataChanged(topLeft, topLeft);
}



#ifdef Q_OS_WIN32

#include <QStringList>
QStringList testStr = QStringList() << "a" << "b"<< "c"<< "d"<< "e"<< "f"<< "g"<< "h"<< "i"<< "j"<< "k" << "l"<< "m"<< "n"<< "o"<< "p"<< "q";

int MenuFavorManagerModel::getServiceCount() const
{
    // TODO:Get service count from the favor data base.
//    qDebug() << "GetServiceCount:" << testStr.count();
    return testStr.count();
}
QString MenuFavorManagerModel::getServiceName(int32_t index) const
{
//    return QString("FAV-CCTV-%1").arg(index);
    return testStr.at(index);
}
int MenuFavorManagerModel::getServiceProperties(int32_t index) const
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

bool MenuFavorManagerModel::removeRows(int row, int count, const QModelIndex &parent)
{
    bool result;

    beginRemoveRows(QModelIndex(), row, row+count-1);
    // TODO:Add a service to the favor data base.

    qDebug() << "remove rows:" << row << "count:" << count;
    testStr.removeAt(row);
    result = true;
    endRemoveRows();

    return result;
}
bool MenuFavorManagerModel::insertRows(int row, int count, const QModelIndex &parent)
{
    bool result;

    beginInsertRows(QModelIndex(), row, row+count-1);

    // TODO:Remove a service from the favor data base.
    qDebug() << "add rows:" << row << "count:" << count;
    qDebug() << parent.model()->data(parent,Qt::DisplayRole).toString() << "index:" << parent.row();
    testStr.append(parent.model()->data(parent,Qt::DisplayRole).toString());
    result = true;

    endInsertRows();

    return result;
}

#else
#endif
