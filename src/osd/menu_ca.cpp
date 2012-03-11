#include "globe.h"
#include "UIKit.h"
#include "ui_menu_ca.h"

MenuCaWidget *UI_pMenuCa=NULL;

/* menu interface defined in 'UIKit.h' */
MenuCaWidget* UI_MenuCa_create()
{
    UI_pMenuCa = new MenuCaWidget();

    if(UI_pMenuCa)
    {
        UI_pMenuCa->setWindowFlags(Qt::FramelessWindowHint);

        #if 0
        QString* pStyleSheet = UI_styleSheet_get(UI_STYLESHEET_NETWORK);
        if (pStyleSheet)
        {
            UI_pMenuCa->setStyleSheet(*pStyleSheet);
        }
        #endif
    }

    return UI_pMenuCa;
}

void UI_MenuCa_show()
{
    if(UI_pMenuCa)
    {
        UI_pMenuCa->setGeometry(UI_menu_getx(UI_ID_CA),UI_menu_gety(UI_ID_CA),
                                                        UI_menu_getw(UI_ID_CA),UI_menu_geth(UI_ID_CA));
        UI_pMenuCa->show();
    }
}

void UI_MenuCa_hide()
{
    if(UI_pMenuCa)
    {
        UI_pMenuCa->hide();
    }
}

void UI_MenuCa_update()
{
    if(UI_pMenuCa)
    {
        UI_pMenuCa->setData();
    }
}

MenuCaWidget::MenuCaWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuCaWidget)
{
    if(NULL!=ui)
    {
        ui->setupUi(this);
    }

    customSetupUi();
}

MenuCaWidget::~MenuCaWidget()
{
    delete ui;
}

void MenuCaWidget::setData(void)
{
    char usr[MENU_CA_DATA_LEN] = {0};
    char card[MENU_CA_DATA_LEN] = {0};
    char pair[MENU_CA_DATA_LEN] = {0};
    bool ret = false;

    if(NULL==ui)
    {
        return;
    }

    ret = on_menuCa_get(usr, MENU_CA_DATA_LEN,
                        card, MENU_CA_DATA_LEN,
                        pair, MENU_CA_DATA_LEN);
    if(ret)
    {
        if(NULL!=ui->usrDataLabel)
        {
            ui->usrDataLabel->setText(QObject::tr(usr));
        }

        if(NULL!=ui->cardDataLabel)
        {
           ui->cardDataLabel->setText(QObject::tr(card));
        }

        if(NULL!=ui->pairDataLabel)
        {
           ui->pairDataLabel->setText(QObject::tr(pair));
        }
    }
}

void MenuCaWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()){
        case KEY_RC_MENU:
            this->hide();
            UI_menu_back();
            break;
        default:
            QWidget::keyPressEvent(e);
    }
}

void MenuCaWidget::showEvent(QShowEvent *e)
{
    setData();
    QWidget::showEvent(e);
}

void MenuCaWidget::customSetupUi(void)
{
    //language switch can be set here.
}
