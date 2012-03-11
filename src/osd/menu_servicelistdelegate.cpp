#include "menu_servicelistdelegate.h"
#include "menu_servicelistmodel.h"
#include <QPainter>
#include <QPixmap>

MenuServiceListDelegate::MenuServiceListDelegate(QObject *parent)
    :QStyledItemDelegate(parent)
{
}

#include <QDebug>
void MenuServiceListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int userFlag;
//    QStyleOptionViewItem opt = option;

//    opt.state &= ~QStyle::State_HasFocus;
    QStyledItemDelegate::paint(painter, option, index);

    userFlag = index.model()->data(index, Qt::UserRole).toInt();
//    qDebug() << "userFlag:" << userFlag;


    QPixmap encryptPixMap(":/menuServiceList/icon_lock_small.png");
    QPixmap favorPixMap(":/menuServiceList/icon_smile_small.png");

    if ((userFlag & MenuServiceListModel::SERVICE_PRO_ENCRYPT) != 0)
    {
        QRect rect(option.rect);
        painter->save();

        rect.setTop(rect.top() + (rect.height() / 10));
        rect.setBottom(rect.bottom() - (rect.height() / 10));
        rect.setLeft(rect.right() - encryptPixMap.width());
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->drawPixmap(rect, encryptPixMap);

        painter->restore();
    }
    if ((userFlag & MenuServiceListModel::SERVICE_PRO_FAVOR) != 0)
    {
        QRect rect(option.rect);
        painter->save();

        rect.setTop(rect.top() + (rect.height() / 10));
        rect.setBottom(rect.bottom() - (rect.height() / 10));
        rect.setLeft(rect.right() - (favorPixMap.width() + encryptPixMap.width()));
        rect.setRight(rect.left() + favorPixMap.width());
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->drawPixmap(rect, favorPixMap);

        painter->restore();
    }
}

QSize MenuServiceListDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}
