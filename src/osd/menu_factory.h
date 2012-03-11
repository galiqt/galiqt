#ifndef MENU_FACTORY_H
#define MENU_FACTORY_H

#include <QtGui>

namespace Ui {
class MenuFactory;
}

class MenuFactory : public QWidget
{
	Q_OBJECT
		 
public:
    explicit MenuFactory(QWidget *parent = 0);
    ~MenuFactory();    

private:
    Ui::MenuFactory *ui;
		
protected slots:
  	
protected:
    void keyPressEvent(QKeyEvent *event);
    
private:    

};

#endif // MENU_FACTORY_H