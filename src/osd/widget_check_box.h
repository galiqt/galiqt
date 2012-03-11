#ifndef WIDGET_CHECK_BOX_H
#define WIDGET_CHECK_BOX_H

#include <QCheckBox>
#include <QKeyEvent>

class KCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    KCheckBox(QWidget *parent = 0);
    ~KCheckBox(void);
protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // WIDGET_CHECK_BOX_H
