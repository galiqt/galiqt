#ifndef MENU_SOUND_H
#define MENU_SOUND_H

#include <QtGui>

namespace Ui {
class MenuSound;
}

class MenuSound : public QWidget
{
	Q_OBJECT
		 
public:
    explicit MenuSound(QWidget *parent = 0);
    ~MenuSound();	
	QTimer *m_timer;
    void timerStart();
    void timerStop();	
	Ui::MenuSound *ui;
    	
protected slots:
  	void autoHide();
  	
protected:
		void keyPressEvent(QKeyEvent *event);

private:

};

#endif // MENU_SOUND_H