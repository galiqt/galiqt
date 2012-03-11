#ifndef MENU_UPDATE_H
#define MENU_UPDATE_H

#include <QtGui>

namespace Ui {
class MenuUpdate;
}

class MenuUpdate : public QWidget
{
	Q_OBJECT
		 
public:
    explicit MenuUpdate(QWidget *parent = 0);
    ~MenuUpdate();    

private:
    Ui::MenuUpdate *ui;
		
protected slots:
  	
protected:
    void keyPressEvent(QKeyEvent *event);
    
private:    

};

#endif // MENU_UPDATE_H