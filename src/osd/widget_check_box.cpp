#include "widget_check_box.h"

KCheckBox::KCheckBox(QWidget *parent/* = 0*/)
: QCheckBox(parent)
{
}

KCheckBox::~KCheckBox(void)
{
}

void KCheckBox::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Enter:
        case Qt::Key_Return:
            click();
            break;
        default:
            break;
    }
    QCheckBox::keyPressEvent(event);
}
