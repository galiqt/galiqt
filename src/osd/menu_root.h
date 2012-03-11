#ifndef MENU_ROOT_H
#define MENU_ROOT_H

#include <QtGui>

class MenuRoot : public QMainWindow
{
		 Q_OBJECT
		 
public:
    MenuRoot();
		QLabel *label;

protected slots:
  
protected:
    void keyPressEvent(QKeyEvent *event);
    
private:    

};

#endif // MENUROOT_H