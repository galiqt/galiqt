#ifndef MENU_CHANNEL_LIST_H
#define MENU_CHANNEL_LIST_H

#include <QtGui>

class MenuChannelList : public QMainWindow
{
		 Q_OBJECT
		 
public:
    MenuChannelList();
		QLabel *label;
		
protected slots:
  	
protected:
    void keyPressEvent(QKeyEvent *event);
    
private:    

};

#endif // MENU_CHANNEL_LIST_H