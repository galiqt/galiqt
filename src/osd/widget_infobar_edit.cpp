#include "widget_infobar_edit.h"

KInfobarEdit::KInfobarEdit(QWidget *parent/* = 0*/)
: QLineEdit(parent)
{
    QRegExp regx("[0-9]+$");

    validator = NULL;
    QValidator *validator = new QRegExpValidator(regx, this);

    setValidator( validator );
    setMaxLength(3);
}

KInfobarEdit::~KInfobarEdit(void)
{
    if(NULL!=validator)
    {
        delete validator;
        validator = NULL;
    }
}

void KInfobarEdit::keyPressEvent(QKeyEvent *event)
{
    QLineEdit::keyPressEvent(event);
    QWidget::keyPressEvent(event);
}
