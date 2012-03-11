#ifndef MENU_VIDEOSET_H
#define MENU_VIDEOSET_H

#include <QtGui>

class MenuVideoSet : public QMainWindow
{
		 Q_OBJECT
		 
public:
    MenuVideoSet();
		QLabel *label;
		
protected slots:
  	
protected:
    void keyPressEvent(QKeyEvent *event);
    
private:    

};

#endif // MENU_SYSTEM_H