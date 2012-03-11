#include "globe.h"
#include "UIKit.h"
#include <stdio.h>

bool on_MenuChannelList_key_press(QKeyEvent *event)
{
    switch (event->key()){

        case KEY_RC_UP:
						qDebug("Key_Up\n");
            break;
        case KEY_RC_DOWN:
						qDebug("Key_Down\n");
            break;
        case KEY_RC_LEFT:
						qDebug("Key_Left\n");
            break;
        case KEY_RC_RIGHT:
						qDebug("Key_Right\n");
            break;
        case KEY_RC_MENU:	
            UI_menu_hide(UI_ID_CHANNEL_LIST);
            UI_menu_back();
            break;

        default:
        		qDebug("keyPress [%d]\n",event->key());
    }
    return true;
}

////#include <QDebug>
////#include <QKeyEvent>
//void MenuServiceList::keyPressEvent(QKeyEvent *event)
//{
//    qDebug() << "MenuServiceList::key:" << event->key();
//    if (event->key() == KEY_RC_MENU
//       || event->key() == KEY_RC_EXIT)
//    {
//        UI_menu_hide(UI_ID_CHANNEL_LIST);
//        UI_menu_back();
//    }
//    // TODO: the code in #if 1 should be removed later. only for test temporary
//#if 1
//    if (event->key() == KEY_RC_F1)
//    {
//        UI_menu_hide(UI_ID_CHANNEL_LIST);
//        UI_menu_back();
//    }
//#endif
//}

#ifdef Q_OS_LINUX
#include "menu_servicelist.h"
#include "ui_menu_servicelist.h"
#include "menu_servicelistmodel.h"
#include "menu_servicelistdelegate.h"
#include "menu_favormanager.h"

int MenuServiceListModel::getServiceCount() const
{
//    qDebug() << "service Count:" << get_program_count();
    return get_program_count();
}

QString MenuServiceListModel::getServiceName(int32_t index) const
{
    char *name = get_program_name(index);
    return QString(" %1  ").arg(index+1) + QString(QObject::tr(name));
}

int MenuServiceListModel::getServiceProperties( int32_t index) const
{
    return get_program_properties(index);
#if 0// TODO: code in #if 1 should be replaced.
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
#endif
}
QModelIndex MenuServiceListModel::getCurrentServiceIndex() const
{
    int curServiceIndex = 0;

    // TODO: change the current service index;

    curServiceIndex = get_current_idx();

    qDebug() << "current service :" << curServiceIndex;

    return this->index(curServiceIndex,0);
}

int32_t MenuServiceListModel::playService(int32_t index) const
{
    int32_t result = -1;
    int32_t prog_idx;

    qDebug() << "play service:" << index;

    //play
    prog_idx = index;
    if (prog_idx != sys->curr_idx)
    {
        play_index(prog_idx);
        result = 0;
    }
    //end

    return result;
}


void MenuServiceList::on_serviceList_activated(const QModelIndex &index)
{
    int32_t result;
    result = serviceListModel->playService(index.row());
    if (result != 0)
    {
        UI_menu_hide(UI_ID_CHANNEL_LIST);
        UI_menu_back();
    }
}

void MenuServiceList::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Menu:
        UI_menu_hide(UI_ID_CHANNEL_LIST);
        UI_menu_back();
        break;
    case Qt::Key_Escape:
        UI_menu_hide(UI_ID_CHANNEL_LIST);
        UI_menu_entry(UI_ID_ROOT);
        break;
    case Qt::Key_Video:
        // TODO:Switch between the video and radio.
        change_program_type();      //louis add
        serviceListModel->updateData();
        break;
    case 0x1000034:    //test
        printf("change audio channel...\n");
        change_audio_channel(sys->curr_idx);
        play_index(sys->curr_idx);
        break;
    default:
        break;
    }
}


////////////////////////////////////////////////////////////////
void MenuFavorManager::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Menu:
        UI_menu_hide(UI_ID_FAVOR_MANAGER);
        UI_menu_back();
        break;
    case Qt::Key_Escape:
        UI_menu_hide(UI_ID_FAVOR_MANAGER);
        UI_menu_entry(UI_ID_ROOT);
        break;
    case Qt::Key_Right:
    case Qt::Key_Left:
        focusNextChild();
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}

int MenuFavorManagerModel::getServiceCount() const
{
    return get_program_count();
}
QString MenuFavorManagerModel::getServiceName(int32_t index) const
{
    char *name = get_program_name(index);
    return QString("%1").arg(index+1) + QString(QObject::tr(name));
}
int MenuFavorManagerModel::getServiceProperties(int32_t index) const
{
    return get_program_properties(index);

#if 0
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
#endif
}

bool MenuFavorManagerModel::removeRows(int row, int count, const QModelIndex &parent)
{
    bool result;

    beginRemoveRows(QModelIndex(), row, row+count-1);
    // TODO:Add a service to the favor data base.

    qDebug() << "remove rows:" << row << "count:" << count;

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

    result = true;

    endInsertRows();

    return result;
}

#endif


