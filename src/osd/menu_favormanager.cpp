#include "menu_favormanager.h"
#include "ui_menu_favormanager.h"


#include <QDebug>

MenuFavorManager *UI_pMenuFavorManager;

MenuFavorManager::MenuFavorManager(QWidget *parent) :
    QWidget(parent, Qt::FramelessWindowHint),
    ui(new Ui::MenuFavorManager)
{
    ui->setupUi(this);
    serviceListModel = new MenuServiceListModel(this);
    favorListModel = new MenuFavorManagerModel(this);
    ui->serviceList->setModel(serviceListModel);
    ui->favorList->setModel(favorListModel);

//    ui->serviceList->setCurrentIndex(serviceListModel->getCurrentServiceIndex());
//    ui->favorList->setCurrentIndex(favorListModel->index(0,0));


    machine = new QStateMachine(this);
    addFavor = new QState();
    addFavor->assignProperty(ui->helpInfo,
                           "text",
                           tr("Press OK to add focus service to favor list"));
    removeFavor = new QState();
    removeFavor->assignProperty(ui->helpInfo,
                             "text",
                             tr("Press OK to remove focus service from favor list"));
    focusOnServiceList = new QEventTransition(ui->serviceList, QEvent::FocusIn);
    focusOnServiceList->setTargetState(addFavor);
    removeFavor->addTransition(focusOnServiceList);

    focusOnFavorList = new QEventTransition(ui->serviceList, QEvent::FocusOut);
    focusOnFavorList->setTargetState(removeFavor);
    addFavor->addTransition(focusOnFavorList);

    machine->addState(addFavor);
    machine->addState(removeFavor);
    machine->setInitialState(addFavor);
    machine->start();

}

MenuFavorManager::~MenuFavorManager()
{
    addFavor->removeTransition(focusOnFavorList);
    removeFavor->removeTransition(focusOnServiceList);
    delete addFavor;
    delete removeFavor;
    delete focusOnServiceList;
    delete focusOnFavorList;
    delete machine;

    delete serviceListModel;
    delete favorListModel;

    delete ui;
}

MenuFavorManager *UI_MenuFavorManager_create()
{
    if (UI_pMenuFavorManager == NULL)
    {
        UI_pMenuFavorManager = new MenuFavorManager;
    }
    return UI_pMenuFavorManager;
}

void UI_MenuFavorManager_show()
{
    if (UI_pMenuFavorManager != NULL)
    {
        UI_pMenuFavorManager->show();
    }
}

void UI_MenuFavorManager_hide()
{
    if (UI_pMenuFavorManager != NULL)
    {
        UI_pMenuFavorManager->hide();
    }
}

void MenuFavorManager::showEvent(QShowEvent *event)
{
    serviceListModel->updateData();
    favorListModel->updateData();

    ui->serviceList->setCurrentIndex(serviceListModel->getCurrentServiceIndex());
    ui->favorList->setCurrentIndex(favorListModel->index(0,0));
    QWidget::showEvent(event);
}

void MenuFavorManager::on_serviceList_activated(const QModelIndex &index)
{
//    qDebug() << "serviceList actived:" << index.row();
    favorListModel->insertRows(index.row(),1,index);
}

void MenuFavorManager::on_favorList_activated(const QModelIndex &index)
{
//    qDebug() << "favorList actived:" << index.row();
    favorListModel->removeRows(index.row(),1,index);
}

#ifdef Q_OS_WIN32
void MenuFavorManager::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Menu:
        break;
    case Qt::Key_Escape:
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
#else
#endif


