#include "widget_scan_lineedit.h" 

KScanLineEdit::KScanLineEdit(QWidget *parent = 0) 
: QLineEdit(parent)
{
	
}

KScanLineEdit::~KScanLineEdit(void)
{
	
}

void KScanLineEdit::keyPressEvent(QKeyEvent *e)
{
	switch( e->key())
	{
		case Qt::Key_Up:
//			qDebug("key up ");
			focusPreviousChild();
			break;
			
		case Qt::Key_Down:
//			qDebug("key down ");
			focusNextChild();	
			break;

		default:
//			qDebug("key [0x%x]",e->key());
			QLineEdit::keyPressEvent(e);
			QWidget::keyPressEvent(e);	
	}	
}	

