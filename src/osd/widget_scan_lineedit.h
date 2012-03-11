#ifndef KScanLineEdit_H 
#define KScanLineEdit_H 
 
#include <QtGui> 
 
class KScanLineEdit : public QLineEdit
{
	Q_OBJECT
public: 
    KScanLineEdit(QWidget *parent);
	~KScanLineEdit(void);
	
protected:
	virtual void keyPressEvent(QKeyEvent *e);


}; 
 
#endif // KScanLineEdit_H