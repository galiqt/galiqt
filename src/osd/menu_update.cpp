#include "globe.h"
#include "UIKit.h"
#include "ui_menu_update.h"
//////////////////////////////////// Menu local define  /////////////////////////

MenuUpdate *UI_pMenuUpdate=0;

//////////////////////////////////// Menu interface  /////////////////////////

MenuUpdate* UI_MenuUpdate_create()
{
	UI_pMenuUpdate = new MenuUpdate();
	UI_pMenuUpdate->setWindowFlags(Qt::FramelessWindowHint);
	return UI_pMenuUpdate;	
}

void UI_MenuUpdate_show()
{
	UI_pMenuUpdate->setGeometry(UI_menu_getx(UI_ID_VIDEO_SET),UI_menu_gety(UI_ID_VIDEO_SET),
														UI_menu_getw(UI_ID_VIDEO_SET),UI_menu_geth(UI_ID_VIDEO_SET));
	UI_pMenuUpdate->show();
}

void UI_MenuUpdate_hide()
{
	UI_pMenuUpdate->hide();
}

/////////////////////////////////// Menu Class instance /////////////////////////////

MenuUpdate::MenuUpdate(QWidget *parent) :
	QWidget(parent),
    ui(new Ui::MenuUpdate)
{
	ui->setupUi(this);
}

MenuUpdate::~MenuUpdate()
{
    delete ui;
}

void MenuUpdate::keyPressEvent(QKeyEvent *event)
{
	MenuUpdate_key_press(event);  
    switch (event->key())
    {
        default:
            QWidget::keyPressEvent(event);
    }

}
