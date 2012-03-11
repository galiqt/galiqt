#ifndef WIDGET_INFOBAR_EDIT_H
#define WIDGET_INFOBAR_EDIT_H

#include <QLineEdit>
#include <QKeyEvent>
#include <QValidator>

class KInfobarEdit : public QLineEdit
{
    Q_OBJECT
public:
    KInfobarEdit(QWidget *parent = 0);
    ~KInfobarEdit(void);
protected:
    virtual void keyPressEvent(QKeyEvent *event);
private:
    QValidator *validator;
};

#endif // WIDGET_INFOBAR_EDIT_H
