#ifndef MENU_VOLUME_H
#define MENU_VOLUME_H

#include <QtGui>

namespace Ui {
class MenuVolume;
}

class MenuVolume : public QWidget
{
	Q_OBJECT
		 
public:
    explicit MenuVolume(QWidget *parent = 0);
    ~MenuVolume();	
	QTimer *m_timer;
    void timerStart();
    void timerStop();
    Ui::MenuVolume *ui;
		
protected slots:
  	void autoHide();
  	
protected:
		void keyPressEvent(QKeyEvent *event);

private:

};

#endif // MENU_VOLUME_H