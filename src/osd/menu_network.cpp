#include "globe.h"
#include "UIKit.h"
#include "ui_menu_network.h"

MenuNetworkWidget *UI_pMenuNetwork=NULL;

/* menu interface defined in 'UIKit.h' */
MenuNetworkWidget* UI_MenuNetwork_create()
{
    UI_pMenuNetwork = new MenuNetworkWidget();

    if(UI_pMenuNetwork)
    {
        UI_pMenuNetwork->setWindowFlags(Qt::FramelessWindowHint);

        QString* pStyleSheet = UI_styleSheet_get(UI_STYLESHEET_NETWORK);
        if (pStyleSheet)
        {
            UI_pMenuNetwork->setStyleSheet(*pStyleSheet);
        }
    }

    return UI_pMenuNetwork;
}

void UI_MenuNetwork_show()
{
    if(UI_pMenuNetwork)
    {
        UI_pMenuNetwork->setGeometry(UI_menu_getx(UI_ID_NETWORK),UI_menu_gety(UI_ID_NETWORK),
                                                        UI_menu_getw(UI_ID_NETWORK),UI_menu_geth(UI_ID_NETWORK));
        UI_pMenuNetwork->show();
    }
}

void UI_MenuNetwork_hide()
{
    if(UI_pMenuNetwork)
    {
        UI_pMenuNetwork->hide();
    }
}

void UI_MenuNetwork_update()
{
    if(UI_pMenuNetwork)
    {
        UI_pMenuNetwork->setData();
    }
}

MenuNetworkWidget::MenuNetworkWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuNetworkWidget)
{
    if(NULL!=ui)
    {
        ui->setupUi(this);
    }
    customSetupUi();
}

MenuNetworkWidget::~MenuNetworkWidget()
{
    delete ui;
}

void MenuNetworkWidget::setData(void)
{
    char ip[MENU_NETWORK_DATA_LEN]={0};
    char mask[MENU_NETWORK_DATA_LEN]={0};
    char gateway[MENU_NETWORK_DATA_LEN]={0};
    char dns[MENU_NETWORK_DATA_LEN]={0};
    bool ret = FALSE;

    if(NULL==ui)
    {
        return;
    }

    ret = on_menuNetwork_get(ip, MENU_NETWORK_DATA_LEN,
                        mask, MENU_NETWORK_DATA_LEN,
                        gateway, MENU_NETWORK_DATA_LEN,
                        dns, MENU_NETWORK_DATA_LEN);
    if(ret)
    {
        if(NULL!=ui->ipEdit)
        {
           ui->ipEdit->setText(ip);
        }

        if(NULL!=ui->maskEdit)
        {
           ui->maskEdit->setText(mask);
        }

        if(NULL!=ui->gatewayEdit)
        {
           ui->gatewayEdit->setText(gateway);
        }

        if(NULL!=ui->dnsEdit)
        {
           ui->dnsEdit->setText(dns);
        }
    }
}

void MenuNetworkWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()){
        case KEY_RC_MENU:
            this->hide();
            UI_menu_back();
            break;
        case KEY_RC_RED:
            if((NULL!=ui)&&(NULL!=ui->dhcpCheck))
            {
                if(Qt::Unchecked == ui->dhcpCheck->checkState())
                {
                    saveData();
                }
            }
            break;
        default:
            QWidget::keyPressEvent(e);
    }
}

void MenuNetworkWidget::showEvent(QShowEvent *e)
{
    setData();
    QWidget::showEvent(e);
}

void MenuNetworkWidget::on_dhcpCheck_stateChanged(int state)
{
    bool enable = true;

    qDebug("MenuNetworkWidget::on_dhcp_check_stateChanged->%d",state);
    if(state == Qt::Checked)
    {
        enable = false;
    }
    else if(state == Qt::Unchecked)
    {
        enable = true;
    }
    else
    {}

    if(NULL!=ui)
    {
        if(NULL!=ui->ipEdit)
        {
            ui->ipEdit->setEnabled(enable);
        }

        if(NULL!=ui->maskEdit)
        {
            ui->maskEdit->setEnabled(enable);
        }

        if(NULL!=ui->gatewayEdit)
        {
            ui->gatewayEdit->setEnabled(enable);
        }

        if(NULL!=ui->dnsEdit)
        {
            ui->dnsEdit->setEnabled(enable);
        }
    }

    (void)on_menuNetwork_dhcp();
}

void MenuNetworkWidget::customSetupUi(void)
{

    QString labelStyle = "QLabel{background: rgb(86, 86, 86);}";
    //QString editStyle = "QLineEdit{background: rgb(255, 170, 255);}";

    if(NULL==ui)
    {
        return;
    }

    if(NULL!=ui->ipEdit)
    {
        //ui->ipEdit->setEditStyleSheet(editStyle);
        ui->ipEdit->setLableStyleSheet(labelStyle);
    }

    if(NULL!=ui->maskEdit)
    {
        //ui->maskEdit->setEditStyleSheet(editStyle);
        ui->maskEdit->setLableStyleSheet(labelStyle);
    }

    if(NULL!=ui->gatewayEdit)
    {
        //ui->gatewayEdit->setEditStyleSheet(editStyle);
        ui->gatewayEdit->setLableStyleSheet(labelStyle);
    }

    if(NULL!=ui->dnsEdit)
    {
        //ui->dnsEdit->setEditStyleSheet(editStyle);
        ui->dnsEdit->setLableStyleSheet(labelStyle);
    }
}

void MenuNetworkWidget::saveData(void)
{
    if(NULL==ui)
    {
        return;
    }

    if((NULL!=ui->ipEdit)
        && (NULL!=ui->maskEdit)
        && (NULL!=ui->gatewayEdit)
        && (NULL!=ui->dnsEdit))
    {
        qDebug("ip:%s(%d), mask:%s(%d), gateway:%s(%d), dns:%s(%d)",
               (const char*)ui->ipEdit->text().toAscii().data(),
               ui->ipEdit->text().toAscii().length(),
               (const char*)ui->maskEdit->text().toAscii().data(),
               ui->maskEdit->text().toAscii().length(),
               (const char*)ui->gatewayEdit->text().toAscii().data(),
               ui->gatewayEdit->text().toAscii().length(),
               (const char*)ui->dnsEdit->text().toAscii().data(),
               ui->dnsEdit->text().toAscii().length());

        (void)on_menuNetwork_set(ui->ipEdit->text().toAscii().data(),
                                 ui->ipEdit->text().toAscii().length(),
                                 ui->maskEdit->text().toAscii().data(),
                                 ui->maskEdit->text().toAscii().length(),
                                 ui->gatewayEdit->text().toAscii().data(),
                                 ui->gatewayEdit->text().toAscii().length(),
                                 ui->dnsEdit->text().toAscii().data(),
                                 ui->dnsEdit->text().toAscii().length());
    }
}
