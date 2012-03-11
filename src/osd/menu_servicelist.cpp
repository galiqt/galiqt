#include "menu_servicelist.h"
#include "ui_menu_servicelist.h"
#include "menu_servicelistdelegate.h"

#include <QDebug>

MenuServiceList *UI_pMenuServiceList;

MenuServiceList::MenuServiceList(QWidget *parent) :
    QWidget(parent, Qt::FramelessWindowHint),
    ui(new Ui::MenuServiceList)
{
    ui->setupUi(this);
    serviceListModel = new MenuServiceListModel(this);
    ui->serviceList->setModel(serviceListModel);
    serviceListDelegate = new MenuServiceListDelegate(this);
    ui->serviceList->setItemDelegate(serviceListDelegate);
}

MenuServiceList::~MenuServiceList()
{
    delete serviceListDelegate;
    delete serviceListModel;
    delete ui;
}


void MenuServiceList::showEvent(QShowEvent *event)
{
//    qDebug() << "showEvent";
    ui->serviceList->selectionModel()->setCurrentIndex(serviceListModel->getCurrentServiceIndex()
                                                       ,QItemSelectionModel::SelectCurrent);
    serviceListModel->updateData();
    QWidget::showEvent(event);
}

MenuServiceList *UI_MenuServiceList_create()
{
    if (UI_pMenuServiceList == NULL)
    {
        UI_pMenuServiceList = new MenuServiceList;
    }
    return UI_pMenuServiceList;
}

void UI_MenuServiceList_show()
{
    if (UI_pMenuServiceList != NULL)
    {
        UI_pMenuServiceList->show();
    }
}
void UI_MenuServiceList_hide()
{
    if (UI_pMenuServiceList != NULL)
    {
        UI_pMenuServiceList->hide();
    }
}


#ifdef Q_OS_WIN32

void MenuServiceList::on_serviceList_activated(const QModelIndex &index)
{
    int32_t result;
    result = serviceListModel->playService(index.row());
//    if (result != 0)
//    {
//        this->close();
//    }
}

void MenuServiceList::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Menu:
        break;
    case Qt::Key_Escape:
        break;
    case Qt::Key_Video:
        // TODO:Switch between the video and radio.

        serviceListModel->updateData();
        break;
    default:
        break;
    }
}
#endif
