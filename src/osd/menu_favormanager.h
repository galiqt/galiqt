#ifndef MENU_FAVORMANAGER_H
#define MENU_FAVORMANAGER_H

#include <QWidget>
#include <QState>
#include <QStateMachine>
#include <QEventTransition>
#include <QKeyEvent>

#include "menu_servicelistmodel.h"
#include "menu_favormanagermodel.h"

namespace Ui {
class MenuFavorManager;
}

class MenuFavorManager : public QWidget
{
    Q_OBJECT
    
public:
    explicit MenuFavorManager(QWidget *parent = 0);
    ~MenuFavorManager();
    
protected:
    void keyPressEvent(QKeyEvent *event);
    void showEvent(QShowEvent *event);

private slots:
    void on_serviceList_activated(const QModelIndex &index);

    void on_favorList_activated(const QModelIndex &index);

private:
    Ui::MenuFavorManager *ui;
    MenuServiceListModel *serviceListModel;
    MenuFavorManagerModel *favorListModel;

    QState *addFavor;
    QState *removeFavor;
    QEventTransition *focusOnServiceList;
    QEventTransition *focusOnFavorList;
    QStateMachine *machine;
};

#endif // MENU_FAVORMANAGER_H
