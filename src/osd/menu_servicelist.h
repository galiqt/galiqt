#ifndef MENU_SERVICELIST_H
#define MENU_SERVICELIST_H

#include <QWidget>
#include <QModelIndex>
#include <QKeyEvent>
#include "menu_servicelistmodel.h"
#include "menu_servicelistdelegate.h"

namespace Ui {
class MenuServiceList;
}

class MenuServiceList : public QWidget
{
    Q_OBJECT
    
public:
    explicit MenuServiceList(QWidget *parent = 0);
    ~MenuServiceList();

protected:
    void keyPressEvent(QKeyEvent * event);
    void showEvent(QShowEvent *event);

private slots:
    void on_serviceList_activated(const QModelIndex &index);

private:
    Ui::MenuServiceList *ui;
    MenuServiceListModel *serviceListModel;
    MenuServiceListDelegate *serviceListDelegate;
};

#endif // MENU_SERVICELIST_H
