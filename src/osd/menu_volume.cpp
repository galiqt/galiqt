#include "globe.h"
#include "UIKit.h"
#include "ui_menu_volume.h"
//////////////////////////////////// Menu local define  /////////////////////////

MenuVolume *UI_pMenuVolume=0;
int	UI_nVolume=24;

//////////////////////////////////// Menu interface  /////////////////////////

MenuVolume* UI_MenuVolume_create()
{
	UI_pMenuVolume = new MenuVolume();
	UI_pMenuVolume->setWindowFlags(Qt::FramelessWindowHint);
	return UI_pMenuVolume;	
}

void UI_MenuVolume_show()
{
	UI_pMenuVolume->setGeometry(UI_menu_getx(UI_ID_VOLUME),UI_menu_gety(UI_ID_VOLUME),
														UI_menu_getw(UI_ID_VOLUME),UI_menu_geth(UI_ID_VOLUME));
	UI_pMenuVolume->show();

	UI_pMenuVolume->timerStart();
}

void UI_MenuVolume_hide()
{
	UI_pMenuVolume->hide();
}

void UI_MenuVolume_setVolume(int volume)
{
	UI_pMenuVolume->ui->VolumeBar->setValue(volume);
}

/////////////////////////////////// Menu Class instance /////////////////////////////

MenuVolume::MenuVolume(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuVolume)
{
    ui->setupUi(this);
    ui->label->setText(__(STR_VOLUME_TITLE));

 	m_timer = new QTimer( this);
 	connect( m_timer, SIGNAL(timeout()), this, SLOT(autoHide()) ); 
}

MenuVolume::~MenuVolume()
{
    delete ui;
}

void MenuVolume::autoHide()
{
	qDebug(">> volume auto hide");
	timerStop();
	UI_menu_hide(UI_ID_VOLUME);
	UI_menu_entry(UI_ID_ROOT);
}

void MenuVolume::timerStart()
{
	if ( !(UI_pMenuVolume->m_timer->isActive()) )
  {
  	qDebug(">> volume timer start");
  	UI_pMenuVolume->m_timer->start( CLEAR_TIME_VOLUME );	
  }else
  {
  	timerStop();
  	qDebug(">> volume timer start");
  	UI_pMenuVolume->m_timer->start( CLEAR_TIME_VOLUME );
  }		
}

void MenuVolume::timerStop()
{
	if((UI_pMenuVolume->m_timer->isActive()))
  {
  	qDebug(">> volume timer stop");
  	UI_pMenuVolume->m_timer->stop();
  }		
}

void MenuVolume::keyPressEvent(QKeyEvent *event)
{
	on_MenuVolume_key_press(event);  
  switch (event->key())
  {
    case KEY_RC_LEFT:
			timerStart();
      break;						
    case KEY_RC_RIGHT:
			timerStart();			
      break;  	
    default:
      QWidget::keyPressEvent(event);
  }
}
