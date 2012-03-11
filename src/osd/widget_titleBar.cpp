#include "QtGui" 
#include "QtGlobal" 
#include "widget_titleBar.h" 
KTitleBar::KTitleBar(QWidget *parent): QWidget(parent) 
{ 
	resize(960,37);

	label_start = new QLabel(this);
	label_start->setGeometry(0, 0,100,37);// width 100
	
	label_left = new QLabel(this);
	label_left->setText("hello 1");
	label_left->setGeometry(100, 0,300,37);//width 300
	label_left->setAlignment(Qt::AlignLeft);
		
	label_right = new QLabel(this);
	label_right->setText("hello 1");
	label_right->setGeometry(400, 0,460,37);//width 460
	label_right->setAlignment(Qt::AlignRight);
	
//	label_right->setStyleSheet("QLabel {font:16pt; background-color: rgb(121,37,37); color: rgb(255,255,0);} ");
	
	label_end = new QLabel(this);
	label_end->setGeometry(860, 0,100,37);//width 100

} 

void KTitleBar::setTitleLeft(QString buf)
{
	label_left->setText(buf);
}

void KTitleBar::setTitleRight(QString buf)
{
	label_right->setText(buf);
}

KTitleBar::~KTitleBar() 
{ 
	delete label_left;
	delete label_right;
	delete label_start;
	delete label_end;
} 

void KTitleBar::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

}

