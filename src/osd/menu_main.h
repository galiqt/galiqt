#ifndef MENU_MAIN_H
#define MENU_MAIN_H

#include <QtGui>

#include "widget_mainItem.h" 
#include "widget_titleBar.h"
#include "widget_arrow.h"

namespace Ui {
class MenuMain;
}

class MenuMain : public QWidget
{
	Q_OBJECT
		 
public:
    explicit MenuMain(QWidget *parent = 0);
    ~MenuMain();
    KTitleBar *m_pTitle;

	KMainItem *m_pMainTV;
	KMainItem *m_pMainRadio;
	KMainItem *m_pMainMedia;
	KMainItem *m_pMainBilling;
	KMainItem *m_pMainEpg;
	KMainItem *m_pMainSystem;
		
	KArrow *m_pMainArrowLeft;
	KArrow *m_pMainArrowRight;
	
	int m_index;

private:
    Ui::MenuMain *ui;
		
protected slots:
  	
protected:
    void keyPressEvent(QKeyEvent *event);
    void showEvent(QShowEvent *e);
private:    

};

#endif // MENU_MAIN_H