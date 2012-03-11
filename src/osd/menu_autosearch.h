#ifndef MENU_AUTOSEARCH_H
#define MENU_AUTOSEARCH_H

#include <QtGui>

namespace Ui {
class MenuAutoSearch;
}



class MenuAutoSearch : public QWidget
{
	Q_OBJECT
		 
public:
    explicit MenuAutoSearch(QWidget *parent = 0);
    ~MenuAutoSearch();    
	void setTVNumber(int number);
	void setRadioNumber(int number);
	void setOtherNumber(int number);
	void setTitle(int index);
	void setProgress(int progress);
	
private:
    Ui::MenuAutoSearch *ui;
		
protected slots:
  	
protected:
    void keyPressEvent(QKeyEvent *event);
    
private:    

};

#endif // MENU_AUTOSEARCH_H