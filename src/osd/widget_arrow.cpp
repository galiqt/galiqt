#include "QtGui" 
#include "QtGlobal" 
#include "widget_arrow.h" 

#define ARROW_WIDTH		20
#define ARROW_HEIGHT	32

#define ARROW_WIDGET_WIDTH	100
#define ARROW_WIDGET_HEIGHT	100

KArrow::KArrow(QWidget *parent): QWidget(parent) 
{ 
	m_pIcon=0;
	resize(ARROW_WIDGET_WIDTH,ARROW_WIDGET_HEIGHT);
} 

void KArrow::loadIcon(const char* buf)
{
	 if(m_pIcon!=NULL){delete m_pIcon;}
	 m_pIcon=new QPixmap(buf);
}

KArrow::~KArrow() 
{ 
	if(m_pIcon!=NULL){delete m_pIcon;}
} 

void KArrow::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	if(m_pIcon)
	{	
		painter.drawPixmap((ARROW_WIDGET_WIDTH-ARROW_WIDTH)/2,
							(ARROW_WIDGET_HEIGHT-ARROW_HEIGHT)/2, *m_pIcon);
	}	
}

