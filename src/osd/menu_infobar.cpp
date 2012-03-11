#include "globe.h"
#include "UIKit.h"
#include "ui_menu_infobar.h"

MenuInfobarWidget *UI_pMenuInfobar=NULL;

/* menu interface defined in 'UIKit.h' */
MenuInfobarWidget* UI_MenuInfobar_create()
{
    UI_pMenuInfobar = new MenuInfobarWidget();

    if(UI_pMenuInfobar)
    {
        UI_pMenuInfobar->setWindowFlags(Qt::FramelessWindowHint);

        QString* pStyleSheet = UI_styleSheet_get(UI_STYLESHEET_INFOBAR);
        if (pStyleSheet)
        {
            UI_pMenuInfobar->setStyleSheet(*pStyleSheet);
        }
    }

    return UI_pMenuInfobar;
}

void UI_MenuInfobar_show()
{
    if(UI_pMenuInfobar)
    {
        UI_pMenuInfobar->setGeometry(UI_menu_getx(UI_ID_INFORBAR),UI_menu_gety(UI_ID_INFORBAR),
                                                        UI_menu_getw(UI_ID_INFORBAR),UI_menu_geth(UI_ID_INFORBAR));
        UI_pMenuInfobar->show();
    }
}

void UI_MenuInfobar_hide()
{
    if(UI_pMenuInfobar)
    {
        UI_pMenuInfobar->hide();
    }
}

void UI_MenuInfobar_update()
{
    if(UI_pMenuInfobar)
    {
        UI_pMenuInfobar->setData();
    }
}

MenuInfobarWidget::MenuInfobarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuInfobarWidget)
{
    if(NULL!=ui)
    {
        ui->setupUi(this);
    }

    customSetupUi();
}

MenuInfobarWidget::~MenuInfobarWidget()
{
    delete ui;
}

void MenuInfobarWidget::setData(void)
{
    char id[MENU_INFOBAR_ID_LEN] = {0};
    char programName[MENU_INFOBAR_PROGRAM_NAME_LEN] = {0};
    char num[MENU_INFOBAR_NUM_LEN] = {0};
    char pEventName[MENU_INFOBAR_EVENT_NAME_LEN] = {0};
    char pEventTime[MENU_INFOBAR_EVENT_TIME_LEN] = {0};
    char fEventName[MENU_INFOBAR_EVENT_NAME_LEN] = {0};
    char fEventTime[MENU_INFOBAR_EVENT_TIME_LEN] = {0};
    bool ret = false;

    if(NULL==ui)
    {
        return;
    }

    ret = on_menuInfobar_get(id, MENU_INFOBAR_ID_LEN,
                             programName, MENU_INFOBAR_PROGRAM_NAME_LEN,
                             num, MENU_INFOBAR_NUM_LEN,
                             pEventName, MENU_INFOBAR_EVENT_NAME_LEN,
                             pEventTime, MENU_INFOBAR_EVENT_TIME_LEN,
                             fEventName, MENU_INFOBAR_EVENT_NAME_LEN,
                             fEventTime, MENU_INFOBAR_EVENT_TIME_LEN);
    if(ret)
    {
        if(NULL!=ui->idEdit)
        {
            ui->idEdit->setText(QObject::tr(id));
        }

        if(NULL!=ui->programNameLabel)
        {
            ui->programNameLabel->setText(QObject::tr(programName));
        }

        if(NULL!=ui->numDataLabel)
        {
           ui->numDataLabel->setText(QObject::tr(num));
        }

        if(NULL!=ui->pEventNameLabel)
        {
           ui->pEventNameLabel->setText(QObject::tr(pEventName));
        }

        if(NULL!=ui->pEventTimeLabel)
        {
           ui->pEventTimeLabel->setText(QObject::tr(pEventTime));
        }

        if(NULL!=ui->fEventNameLabel)
        {
           ui->fEventNameLabel->setText(QObject::tr(fEventName));
        }

        if(NULL!=ui->fEventTimeLabel)
        {
           ui->fEventTimeLabel->setText(QObject::tr(fEventTime));
        }
    }
}

void MenuInfobarWidget::keyPressEvent(QKeyEvent *e)
{
    QWidget::keyPressEvent(e);

    switch (e->key())
    {
        case KEY_RC_INFO:
            this->hide();
            UI_menu_back();
            break;
        case KEY_RC_OK:
            if((NULL!=ui)
                &&(NULL!=ui->idEdit))
            {
                on_menuInfobar_num_select(ui->idEdit->text().toInt());
            }
            break;
        case KEY_RC_UP:
            if((NULL!=ui)
                &&(NULL!=ui->idEdit))
            {
                on_menuInfobar_direct_select(MENU_INFOBAR_UP_SELECT);
            }
            break;
        case KEY_RC_DOWN:
            if((NULL!=ui)
                &&(NULL!=ui->idEdit))
            {
                on_menuInfobar_direct_select(MENU_INFOBAR_DOWN_SELECT);
            }
            break;
        default:
            break;
    }
}

void MenuInfobarWidget::showEvent(QShowEvent *e)
{
    setData();
    QWidget::showEvent(e);
}

void MenuInfobarWidget::customSetupUi(void)
{
    //language switch can be set here.
}
