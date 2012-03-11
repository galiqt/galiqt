#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include <QtGui>

namespace Ui {
class MenuSystem;
}

class MenuSystem : public QWidget
{
	Q_OBJECT
		 
public:
    explicit MenuSystem(QWidget *parent = 0);
    ~MenuSystem();

private:
    Ui::MenuSystem *ui;
    
public slots:
  	void on_btnAutoSearch_clicked();
  	void on_btnManualSearch_clicked();
  	void on_btnSystemSetting_clicked();
  	void on_btnUpdate_clicked();
    void on_btnFactory_clicked();
  	void on_btnNetworkSetting_clicked();
  	void on_btnVersion_clicked();
  	void on_btnCACard_clicked();

protected:
    void keyPressEvent(QKeyEvent *event);
    
private:    

};

#endif // MENU_SYSTEM_H