#ifndef KMAINITEM_H 
#define KMAINITEM_H 
#include <QWidget> 
#include <QLabel>


class KMainItem : public QWidget 
{
	Q_OBJECT 
	public: 
         KMainItem(QWidget *parent=0); 
         virtual ~KMainItem(); 
         QLabel *label;
         void loadIcon(const char* buf);
         void setTitle(QString buf);
         void selectFocus(bool focus);
         bool m_isFocus;
         QPixmap *m_pIcon;
	protected: 
		void paintEvent(QPaintEvent *event); 
}; 
#endif // KMAINITEM_H 
