#ifndef MENU_MANUALSEARCH_H
#define MENU_MANUALSEARCH_H

#include <QtGui>

namespace Ui {
class MenuManualSearch;
}

class MenuManualSearch : public QWidget
{
	Q_OBJECT
		 
public:
    explicit MenuManualSearch(QWidget *parent = 0);
    ~MenuManualSearch();    
	bool ManualSearch_set(int nStartFreq, int nEndFreq  ,int nSearchSymbol ,int nSearchQAM);
	bool ManualSearch_get(int *nStartFreq, int *nEndFreq ,int *nSearchSymbol ,int *nSearchQAM);
	
	
private:
    Ui::MenuManualSearch *ui;
		
protected slots:
  	void on_btnScan_clicked(void);
  	
protected:
    void keyPressEvent(QKeyEvent *event);
    
private:    

};

#endif // MENU_MANUALSEARCH_H