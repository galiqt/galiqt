#include "globe.h"
#include "UIKit.h"

//////////////////////////////////// Menu local define  /////////////////////////

MenuVideoSet *UI_pMenuVideoSet=0;

//////////////////////////////////// Menu interface  /////////////////////////

MenuVideoSet* UI_MenuVideoSet_create()
{
	UI_pMenuVideoSet = new MenuVideoSet();
	UI_pMenuVideoSet->setWindowFlags(Qt::FramelessWindowHint);
	return UI_pMenuVideoSet;	
}

void UI_MenuVideoSet_show()
{
	UI_pMenuVideoSet->setGeometry(UI_menu_getx(UI_ID_VIDEO_SET),UI_menu_gety(UI_ID_VIDEO_SET),
														UI_menu_getw(UI_ID_VIDEO_SET),UI_menu_geth(UI_ID_VIDEO_SET));
	UI_pMenuVideoSet->show();
}

void UI_MenuVideoSet_hide()
{
	UI_pMenuVideoSet->hide();
}

/////////////////////////////////// Menu Class instance /////////////////////////////

MenuVideoSet::MenuVideoSet()
{
  label = new QLabel(this);
  label->setObjectName(QString::fromUtf8("label"));
  label->setGeometry(QRect(30, 70, 300, 31));      

  label->setText("I am video set window, press MENU key goto System setting");
  
}


void MenuVideoSet::keyPressEvent(QKeyEvent *event)
{
    //on_MenuVideoSet_key_press(event);
    switch (event->key())
    {
        default:
            QWidget::keyPressEvent(event);
    }

}
