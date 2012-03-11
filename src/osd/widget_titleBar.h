#ifndef KTITLEBAR_H 
#define KTITLEBAR_H 
#include <QWidget> 
#include <QLabel>
#include <QString>

class KTitleBar : public QWidget 
{
	Q_OBJECT 
	public: 
		KTitleBar(QWidget *parent=0); 
		virtual ~KTitleBar(); 
		QLabel *label_left;
		QLabel *label_right;
		QLabel *label_start;
		QLabel *label_end;
		
		void setTitleLeft(QString buf);
		void setTitleRight(QString buf);
	protected: 
		void paintEvent(QPaintEvent *event);  		
}; 
#endif // KTITLEBAR_H 
