#include "globe.h"
#include "UIKit.h"
#include "ui_menu_main.h"
//////////////////////////////////// Menu local define  /////////////////////////

MenuMain *UI_pMenuMain=0;

typedef enum
{
	MENU_MAIN_TV=0,
	MENU_MAIN_RADIO,
	MENU_MAIN_MEDIA,
	MENU_MAIN_BILLING,
	MENU_MAIN_EPG,
	MENU_MAIN_SYSTEM,
	MENU_MAIN_MAX	
} E_MENUMAIN_ITEM_S;

#define	MENU_MAIN_START	MENU_MAIN_TV

//////////////////////////////////// Menu interface  /////////////////////////

MenuMain* UI_menuMain_create()
{
	UI_pMenuMain = new MenuMain();
	UI_pMenuMain->setWindowFlags(Qt::FramelessWindowHint);	
	return UI_pMenuMain;	
}

void UI_menuMain_show()
{
	UI_pMenuMain->setGeometry(UI_menu_getx(UI_ID_MAIN_MENU),UI_menu_gety(UI_ID_MAIN_MENU),
								UI_menu_getw(UI_ID_MAIN_MENU),UI_menu_geth(UI_ID_MAIN_MENU));

	UI_pMenuMain->show();
}

void UI_menuMain_hide()
{
	UI_pMenuMain->hide();
}

/////////////////////////////////// Menu Class instance /////////////////////////////
MenuMain::MenuMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuMain)
{
    int x=0;
    
    ui->setupUi(this);
    //ui->label->setText(__(STR_MAINMENU_TITLE));
	ui->label->setText("");

	m_pTitle = new KTitleBar(this);
	//m_pTitle->setAutoFillBackground(true);
	m_pTitle->setTitleLeft(__(STR_MAINMENU_TITLE));
	m_pTitle->setTitleRight(__(STR_MAINMENU_NUMBER));
	m_pTitle->setGeometry (1,1,960,100);
/*
	m_pTitle->setStyleSheet("QWidget {background-color: rgb(121,37,37);} \
		QLabel {font:20pt; background-color: rgb(121,37,37); color: rgb(255,255,255);}");
*/
    QString* pStyleSheet = UI_styleSheet_get(UI_STYLESHEET_TITLEBAR);
    if (pStyleSheet)
    {
		m_pTitle->setStyleSheet(*pStyleSheet);
    }

	x+=20;
	m_pMainArrowLeft = new KArrow(this);
	m_pMainArrowLeft->loadIcon(":/icon_arrow_l.png");	
	m_pMainArrowLeft->move(x,40);

	x+=100;
	m_pMainTV = new KMainItem(this);
	m_pMainTV->move(x,40);
	m_pMainTV->setTitle(__(STR_MAINMENU_TV));
	m_pMainTV->loadIcon(":/CategoryTitle_Broadcast.png");	
	m_pMainTV->selectFocus(true);
	
	x+=120;
	m_pMainRadio = new KMainItem(this);
	m_pMainRadio->move(x,40);
	m_pMainRadio->loadIcon(":/CategoryTitle_MultiMedia.png");	
    m_pMainRadio->setTitle(__(STR_MAINMENU_RADIO));

	x+=120;         
	m_pMainMedia = new KMainItem(this);
	m_pMainMedia->move(x,40);
    m_pMainMedia->loadIcon(":/CategoryTitle_PVR.png");	
    m_pMainMedia->setTitle(__(STR_MAINMENU_MEDIA));

	x+=120;
	m_pMainBilling = new KMainItem(this);
	m_pMainBilling->move(x,40);
    m_pMainBilling->loadIcon(":/CategoryTitle_VOD.png");	
    m_pMainBilling->setTitle(__(STR_MAINMENU_BILLING));   

	x+=120;
	m_pMainEpg = new KMainItem(this);
	m_pMainEpg->move(x,40);
    m_pMainEpg->loadIcon(":/CategoryTitle_EPG.png");	
    m_pMainEpg->setTitle(__(STR_MAINMENU_EPG));  
    
    x+=120;
	m_pMainSystem = new KMainItem(this);
	m_pMainSystem->move(x,40);
    m_pMainSystem->loadIcon(":/CategoryTitle_SystemSetting.png");	
    m_pMainSystem->setTitle(__(STR_MAINMENU_SYSTEM));      
	
	x+=100;
 	m_pMainArrowRight=new KArrow(this);
	m_pMainArrowRight->loadIcon(":/icon_arrow_r.png");	
	m_pMainArrowRight->move(x,40);
    
    m_index=MENU_MAIN_START;

}

MenuMain::~MenuMain()
{
    delete ui;
    
	delete	m_pMainTV;
	delete	m_pMainRadio;
	delete	m_pMainMedia;  
	
	delete m_pMainArrowLeft;
	delete m_pMainArrowRight;  
}

void MenuMain::keyPressEvent(QKeyEvent *event)
{
	on_menuMain_key_press(event);  
    switch (event->key())
    {
		case Qt::Key_Left:
			if(m_index>MENU_MAIN_START)
			{
				m_index--;
			}else
			{
				m_index=MENU_MAIN_MAX-1;	
			}	
			switch(m_index)
			{
				case MENU_MAIN_TV:
					m_pMainTV->selectFocus(true);
					m_pMainRadio->selectFocus(false);
					break;
				case MENU_MAIN_RADIO:
					m_pMainRadio->selectFocus(true);
					m_pMainMedia->selectFocus(false);
					break;
				case MENU_MAIN_MEDIA:
					m_pMainMedia->selectFocus(true);
					m_pMainBilling->selectFocus(false);
					break;
				case MENU_MAIN_BILLING:
					m_pMainBilling->selectFocus(true);
					m_pMainEpg->selectFocus(false);
					break;
				case MENU_MAIN_EPG:
					m_pMainEpg->selectFocus(true);
					m_pMainSystem->selectFocus(false);					
					break;
				case MENU_MAIN_SYSTEM:
					m_pMainSystem->selectFocus(true);
					m_pMainTV->selectFocus(false);					
					break;		
			}
//			qDebug("left [%d]",m_index);
			break;
		case Qt::Key_Right:
			if(m_index<(MENU_MAIN_MAX-1))
			{
				m_index++;
			}else
			{
				m_index=MENU_MAIN_START;
			}				
			switch(m_index)
			{
				case MENU_MAIN_TV:
					m_pMainTV->selectFocus(true);
					m_pMainSystem->selectFocus(false);
					break;
				case MENU_MAIN_RADIO:
					m_pMainRadio->selectFocus(true);
					m_pMainTV->selectFocus(false);
					break;
				case MENU_MAIN_MEDIA:
					m_pMainMedia->selectFocus(true);
					m_pMainRadio->selectFocus(false);
					break;
				case MENU_MAIN_BILLING:
					m_pMainBilling->selectFocus(true);
					m_pMainMedia->selectFocus(false);
					break;
				case MENU_MAIN_EPG:
					m_pMainEpg->selectFocus(true);
					m_pMainBilling->selectFocus(false);					
					break;
				case MENU_MAIN_SYSTEM:
					m_pMainSystem->selectFocus(true);
					m_pMainEpg->selectFocus(false);					
					break;	
			}
//			qDebug("right [%d]",m_index);
			break;
		case Qt::Key_Return:
		case Qt::Key_Enter:	
			if(m_index==MENU_MAIN_TV){MenuMain_on_TVClicked();}
			if(m_index==MENU_MAIN_RADIO){MenuMain_on_RadioClicked();}					
			if(m_index==MENU_MAIN_MEDIA){MenuMain_on_MediaClicked();}				
			if(m_index==MENU_MAIN_BILLING){MenuMain_on_BillingClicked();}				
			if(m_index==MENU_MAIN_EPG){MenuMain_on_EPGClicked();}				
			if(m_index==MENU_MAIN_SYSTEM){MenuMain_on_SystemClicked();}																
			qDebug("select [%d]",m_index);
			break;		
        default:
            QWidget::keyPressEvent(event);
    }
}

void MenuMain::showEvent(QShowEvent *e)
{
	
}
