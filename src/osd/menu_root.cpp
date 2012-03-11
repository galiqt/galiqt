#include "globe.h"
#include "UIKit.h"

//////////////////////////////////// Menu local define  /////////////////////////

MenuRoot *UI_pMenuRoot=0;

//////////////////////////////////// Menu interface  /////////////////////////

MenuRoot* UI_menuRoot_create()
{
	UI_pMenuRoot = new MenuRoot();
	UI_pMenuRoot->setWindowFlags(Qt::FramelessWindowHint);

	QString* pStyleSheet = UI_styleSheet_get(UI_STYLESHEET_ROOT);
	if (pStyleSheet)
	{
		UI_pMenuRoot->setStyleSheet(*pStyleSheet);	
	}		
		
	return UI_pMenuRoot;	
}

void UI_menuRoot_show()
{
	UI_pMenuRoot->setGeometry(UI_menu_getx(UI_ID_ROOT),UI_menu_gety(UI_ID_ROOT),
														UI_menu_getw(UI_ID_ROOT),UI_menu_geth(UI_ID_ROOT));
	UI_pMenuRoot->show();
}

void UI_menuRoot_hide()
{
	UI_pMenuRoot->hide();	
}

/////////////////////////////////// Menu Class instance /////////////////////////////

MenuRoot::MenuRoot()
{
  label = new QLabel(this);
  label->setObjectName(QString::fromUtf8("label"));
  label->setGeometry(QRect(60, 60, 191, 16));      
  label->setText(QObject::tr("ÎÒÊÇroot"));
}

void MenuRoot::keyPressEvent(QKeyEvent *event)
{
		on_menuRoot_key_press(event); 

    switch (event->key())
    {
        default:
            QWidget::keyPressEvent(event);
    }
}
