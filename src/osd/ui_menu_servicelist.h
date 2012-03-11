/********************************************************************************
** Form generated from reading UI file 'menu_servicelist.ui'
**
** Created: Fri Mar 2 19:09:47 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_SERVICELIST_H
#define UI_MENU_SERVICELIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuServiceList
{
public:
    QLabel *helpInfo;
    QListView *serviceList;

    void setupUi(QWidget *MenuServiceList)
    {
        if (MenuServiceList->objectName().isEmpty())
            MenuServiceList->setObjectName(QString::fromUtf8("MenuServiceList"));
        MenuServiceList->resize(960, 540);
        helpInfo = new QLabel(MenuServiceList);
        helpInfo->setObjectName(QString::fromUtf8("helpInfo"));
        helpInfo->setGeometry(QRect(460, 470, 331, 21));
        serviceList = new QListView(MenuServiceList);
        serviceList->setObjectName(QString::fromUtf8("serviceList"));
        serviceList->setGeometry(QRect(70, 90, 241, 361));

        retranslateUi(MenuServiceList);

        QMetaObject::connectSlotsByName(MenuServiceList);
    } // setupUi

    void retranslateUi(QWidget *MenuServiceList)
    {
        MenuServiceList->setWindowTitle(QApplication::translate("MenuServiceList", "MenuServiceList", 0, QApplication::UnicodeUTF8));
        helpInfo->setText(QApplication::translate("MenuServiceList", "Press [Exit] or [TV] to watch TV", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MenuServiceList: public Ui_MenuServiceList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_SERVICELIST_H
