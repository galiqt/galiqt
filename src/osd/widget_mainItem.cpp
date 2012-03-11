#include "QtGui" 
#include "QtGlobal" 
#include "widget_mainItem.h" 

#define ICON_WIDTH		46
#define ICON_HEIGHT		64

#define WIDGET_WIDTH	110
#define WIDGET_HEIGHT	110
#define FRAME_PLY		4//2

#define ICON_Y_OFFSET	(-10)

KMainItem::KMainItem(QWidget *parent): QWidget(parent) 
{ 
	label = new QLabel(this);
	label->setText("hello 1");
	label->move(FRAME_PLY*4, (WIDGET_HEIGHT-ICON_HEIGHT)/2+ICON_HEIGHT-4 +ICON_Y_OFFSET);
	label->setAlignment(Qt::AlignCenter);
	label->resize(WIDGET_WIDTH-FRAME_PLY*8,24);	
	resize(WIDGET_WIDTH, WIDGET_HEIGHT);

	m_pIcon=0;
	m_isFocus=false;
} 
void KMainItem::loadIcon(const char* buf)
{
	 if(m_pIcon!=NULL){delete m_pIcon;}
	 m_pIcon=new QPixmap(buf);
}
void KMainItem::setTitle(QString buf)
{
	label->setText(buf);
}
void KMainItem::selectFocus(bool focus)
{
	m_isFocus=focus;
	update();
}	

KMainItem::~KMainItem() 
{ 
	delete label;
	delete m_pIcon;
} 

void KMainItem::paintEvent(QPaintEvent *event) 
{ 
	QPainter painter(this);
	if(m_pIcon)
	{	
		painter.drawPixmap((WIDGET_WIDTH-ICON_WIDTH)/2, (WIDGET_HEIGHT-ICON_HEIGHT)/2+ICON_Y_OFFSET, *m_pIcon);
	}	
	
  	if(m_isFocus)
	{
		QPen pen;
		painter.setPen(QPen(QColor(255,255,0), FRAME_PLY, Qt::SolidLine, Qt::RoundCap));
		painter.drawRoundRect(0,0,WIDGET_WIDTH - FRAME_PLY*2,WIDGET_HEIGHT - FRAME_PLY*2);		
	}

} 
