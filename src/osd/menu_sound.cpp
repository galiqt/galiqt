#include "globe.h"
#include "UIKit.h"
#include "ui_menu_sound.h"
//////////////////////////////////// Menu local define  /////////////////////////

MenuSound *UI_pMenuSound=0;
bool	UI_bIsMute=false;
int UI_nSoundChannel=0;
//////////////////////////////////// Menu interface  /////////////////////////

MenuSound* UI_MenuSound_create()
{
	UI_pMenuSound = new MenuSound();
	UI_pMenuSound->setWindowFlags(Qt::FramelessWindowHint);
	return UI_pMenuSound;	
}

void UI_MenuSound_show()
{
	UI_pMenuSound->setGeometry(UI_menu_getx(UI_ID_SOUND),UI_menu_gety(UI_ID_SOUND),
								UI_menu_getw(UI_ID_SOUND),UI_menu_geth(UI_ID_SOUND));
	UI_pMenuSound->show();
	
	UI_pMenuSound->timerStart();
}

void UI_MenuSound_hide()
{
	UI_pMenuSound->ui->label->setText(__(STR_VOLUME_MUTE));
	UI_pMenuSound->hide();
}

void UI_MenuSound_set(int id)
{
	switch(id)
	{
		case UI_SOUND_STEREO:
			UI_pMenuSound->ui->label->setText(__(STR_SOUND_STEREO));
			break;
		case UI_SOUND_LEFT:
			UI_pMenuSound->ui->label->setText(__(STR_SOUND_LEFT));
			break;
		case UI_SOUND_RIGHT:	
			UI_pMenuSound->ui->label->setText(__(STR_SOUND_RIGHT));
			break;
		default:
			UI_pMenuSound->ui->label->setText(__(STR_VOLUME_MUTE));
			break;	
	}
}

/////////////////////////////////// Menu Class instance /////////////////////////////

MenuSound::MenuSound(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuSound)
{
    ui->setupUi(this);
    ui->label->setText(__(STR_VOLUME_MUTE));
 	m_timer = new QTimer( this);
 	connect( m_timer, SIGNAL(timeout()), this, SLOT(autoHide()) ); 
}

MenuSound::~MenuSound()
{
    delete ui;
}

void MenuSound::autoHide()
{
	qDebug(">> sound auto hide");
	timerStop();
	UI_menu_hide(UI_ID_SOUND);

	UI_menu_entry(UI_ID_ROOT);
}

void MenuSound::timerStart()
{
	if ( !(UI_pMenuSound->m_timer->isActive()) )
  	{
		qDebug(">> sound timer start");
  		UI_pMenuSound->m_timer->start( CLEAR_TIME_VOLUME );	
	}else
	{
		timerStop();
		qDebug(">> sound timer start");
		UI_pMenuSound->m_timer->start( CLEAR_TIME_VOLUME );
	}		
}

void MenuSound::timerStop()
{
	if((UI_pMenuSound->m_timer->isActive()))
  {
  	qDebug(">> sound timer stop");
  	UI_pMenuSound->m_timer->stop();
  }		
}

void MenuSound::keyPressEvent(QKeyEvent *event)
{
	on_MenuSound_key_press(event);
  switch (event->key())
  {
    case KEY_RC_RED:
    	timerStart();
		break;						
 	
    default:
      QWidget::keyPressEvent(event);
  }
}
