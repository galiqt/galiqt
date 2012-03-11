#include "globe.h"
#include "UIKit.h"
#include "ui_menu_system.h"
//////////////////////////////////// Menu local define  /////////////////////////

MenuSystem *UI_pMenuSystem=0;

//////////////////////////////////// Menu interface  /////////////////////////

MenuSystem* UI_MenuSystem_create()
{
	UI_pMenuSystem = new MenuSystem();
	UI_pMenuSystem->setWindowFlags(Qt::FramelessWindowHint);
	return UI_pMenuSystem;	
}

void UI_MenuSystem_show()
{
	UI_pMenuSystem->setGeometry(UI_menu_getx(UI_ID_CONFIG),UI_menu_gety(UI_ID_CONFIG),
														UI_menu_getw(UI_ID_CONFIG),UI_menu_geth(UI_ID_CONFIG));
	UI_pMenuSystem->show();
}

void UI_MenuSystem_hide()
{
	UI_pMenuSystem->hide();
}

/////////////////////////////////// Menu Class instance /////////////////////////////
MenuSystem::MenuSystem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuSystem)
{
    ui->setupUi(this);
    
    QString* pStyleSheet = UI_styleSheet_get(UI_STYLESHEET_LABEL_TITLE);
	ui->label->setStyleSheet(*pStyleSheet);	

	ui->label->setText(__(STR_SYSTEM_TITLE));
	ui->btnAutoSearch->setText(__(STR_SYSTEM_AUTO_SEARCH));
	ui->btnManualSearch->setText(__(STR_SYSTEM_MANUAL_SEARCH));
	ui->btnSystemSetting->setText(__(STR_SYSTEM_SETTING));
	ui->btnUpdate->setText(__(STR_SYSTEM_UPDATE));
	ui->btnFactory->setText(__(STR_SYSTEM_FACTORY));
	ui->btnNetworkSetting->setText(__(STR_SYSTEM_NETWORK_SETTING));
	ui->btnVersion->setText(__(STR_SYSTEM_VERSION));
	ui->btnCACard->setText(__(STR_SYSTEM_CACARD));

}

MenuSystem::~MenuSystem()
{
    delete ui;
}

void MenuSystem::on_btnCACard_clicked()
{
	on_MenuSystem_CACardClicked();
}

void MenuSystem::on_btnVersion_clicked()
{
	on_MenuSystem_VersionClicked();
}

void MenuSystem::on_btnNetworkSetting_clicked()
{
	on_MenuSystem_NetworkSettingClicked();
}

void MenuSystem::on_btnFactory_clicked()
{
	on_MenuSystem_FactoryClicked();
}

void MenuSystem::on_btnUpdate_clicked()
{
	on_MenuSystem_UpdateClicked();
}

void MenuSystem::on_btnSystemSetting_clicked()
{
	on_MenuSystem_SystemSettingClicked();
}

void MenuSystem::on_btnManualSearch_clicked()
{
	on_MenuSystem_ManualSearchClicked();
}

void MenuSystem::on_btnAutoSearch_clicked()
{
	on_MenuSystem_AutoSearchClicked();
}

void MenuSystem::keyPressEvent(QKeyEvent *event)
{
	on_MenuSystem_key_press(event);  
    switch (event->key())
    {
        default:
            QWidget::keyPressEvent(event);
    }
}
