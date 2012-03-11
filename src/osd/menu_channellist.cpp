#include "globe.h"
#include "UIKit.h"

//////////////////////////////////// Menu local define  /////////////////////////

MenuChannelList *UI_pMenuChannelList=0;

//////////////////////////////////// Menu interface  /////////////////////////

MenuChannelList* UI_MenuChannelList_create()
{
	UI_pMenuChannelList = new MenuChannelList();
	UI_pMenuChannelList->setWindowFlags(Qt::FramelessWindowHint);
	return UI_pMenuChannelList;	
}

void UI_MenuChannelList_show()
{
	UI_pMenuChannelList->setGeometry(UI_menu_getx(UI_ID_CHANNEL_LIST),UI_menu_gety(UI_ID_CHANNEL_LIST),
														UI_menu_getw(UI_ID_CHANNEL_LIST),UI_menu_geth(UI_ID_CHANNEL_LIST));
	UI_pMenuChannelList->show();
}

void UI_MenuChannelList_hide()
{
	UI_pMenuChannelList->hide();
}

/////////////////////////////////// Menu Class instance /////////////////////////////

MenuChannelList::MenuChannelList()
{
 
  label = new QLabel(this);
  label->setObjectName(QString::fromUtf8("label"));
  label->setGeometry(QRect(30, 70, 200, 31));      

  label->setText("I am channel list window");
}

void MenuChannelList::keyPressEvent(QKeyEvent *event)
{
	on_MenuChannelList_key_press(event);  
  switch (event->key())
  {
    default:
    QWidget::keyPressEvent(event);
  }
}
