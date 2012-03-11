#include "globe.h"
#include "UIKit.h"
#include "ui_menu_factory.h"
//////////////////////////////////// Menu local define  /////////////////////////

MenuFactory *UI_pMenuFactory=0;

//////////////////////////////////// Menu interface  /////////////////////////

MenuFactory* UI_MenuFactory_create()
{
	UI_pMenuFactory = new MenuFactory();
	UI_pMenuFactory->setWindowFlags(Qt::FramelessWindowHint);
	return UI_pMenuFactory;	
}

void UI_MenuFactory_show()
{
	UI_pMenuFactory->setGeometry(UI_menu_getx(UI_ID_VIDEO_SET),UI_menu_gety(UI_ID_VIDEO_SET),
														UI_menu_getw(UI_ID_VIDEO_SET),UI_menu_geth(UI_ID_VIDEO_SET));
	UI_pMenuFactory->show();
}

void UI_MenuFactory_hide()
{
	UI_pMenuFactory->hide();
}

/////////////////////////////////// Menu Class instance /////////////////////////////

MenuFactory::MenuFactory(QWidget *parent) :
	QWidget(parent),
    ui(new Ui::MenuFactory)
{
	ui->setupUi(this);
}

MenuFactory::~MenuFactory()
{
    delete ui;
}

void MenuFactory::keyPressEvent(QKeyEvent *event)
{
	MenuFactory_key_press(event);  
    switch (event->key())
    {
        default:
            QWidget::keyPressEvent(event);
    }

}
