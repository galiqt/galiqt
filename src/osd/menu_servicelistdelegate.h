#ifndef MENU_SERVICELISTDELEGATE_H
#define MENU_SERVICELISTDELEGATE_H

#include <QStyledItemDelegate>
#include <QSize>

class MenuServiceListDelegate : public QStyledItemDelegate
{
public:
    MenuServiceListDelegate(QObject *parent = NULL);

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // MENU_SERVICELISTDELEGATE_H
