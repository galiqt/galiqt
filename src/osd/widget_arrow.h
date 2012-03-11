#ifndef KARROW_H 
#define KARROW_H 
#include <QWidget> 
#include <QLabel>

class KArrow : public QWidget 
{
	Q_OBJECT 
	public: 
		KArrow(QWidget *parent=0); 
		virtual ~KArrow(); 
		void loadIcon(const char* buf);
		QPixmap *m_pIcon;

	protected: 
		void paintEvent(QPaintEvent *event);  		
}; 
#endif // KARROW_H 
