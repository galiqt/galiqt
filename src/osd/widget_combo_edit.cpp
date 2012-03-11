#include "widget_combo_edit.h"

KComboEdit::KComboEdit(QWidget *parent)
    : QLineEdit(parent), parent(parent)
{
    init();
}

KComboEdit::~KComboEdit(void)
{
    unInit();
}

void KComboEdit::addItem(const QString &text)
{
    if(NULL!=dropDown)
    {
        QListWidgetItem *item = new QListWidgetItem(text, dropDown);
        item->setTextAlignment(Qt::AlignHCenter);
    }
}

int KComboEdit::getRow(void)
{
    int row = -1;

    if(NULL!=dropDown)
    {
        row = dropDown->currentRow();
    }

    return row;
}

void KComboEdit::setRow(int row)
{
    if(NULL!=dropDown)
    {
        dropDown->setCurrentRow(row);
        if ((NULL != dropDown->item(row))
            &&(dropDown->currentIndex().isValid()))
        {
            QString text = dropDown->item(row)->text();
            setText(text);
        }
    }
}

void KComboEdit::keyPressEvent(QKeyEvent *e)
{
    int count = 0;
    int row = 0;

    if((NULL==e)
        || (NULL==dropDown)
        || (NULL==buttonLeft)
        || (NULL==buttonRight))
    {
        return;
    }

    buttonLeft->setChecked(false);
    buttonRight->setChecked(false);

    count = dropDown->count();
    row = dropDown->currentRow();

    switch(e->key())
    {
        case Qt::Key_Up:
            if(!dropDown->isHidden())
            {
                row -= 1;
                if (row < 0) {
                    row = count - 1;
                }
                setRow(row);
            }
            else
            {
                focusPreviousChild();
            }
            break;
        case Qt::Key_Down:
            if(!dropDown->isHidden())
            {
                row += 1;;
                if (row >= count) {
                    row = 0;
                }
                setRow(row);
            }
            else
            {
                focusNextChild();
            }
            break;
        case Qt::Key_Left:
            if(dropDown->isHidden())
            {
                row -= 1;
                if (row < 0) {
                    row = count - 1;
                }
                setRow(row);
                buttonLeft->setChecked(true);
                buttonRight->setChecked(false);
            }
            break;
        case Qt::Key_Right:
            if(dropDown->isHidden())
            {
                row += 1;
                if (row >= count) {
                    row = 0;
                }
                setRow(row);
                buttonLeft->setChecked(false);
                buttonRight->setChecked(true);
            }
            break;
        case Qt::Key_Return:
        case Qt::Key_Enter:
            if(dropDown->isHidden())
            {
                dropDown->show();
            }
            else
            {
                dropDown->hide();
            }
            break;
        default:
            QLineEdit::keyPressEvent(e);
            break;
    }
}

void KComboEdit::focusOutEvent(QFocusEvent *e)
{
    if(NULL!=dropDown)
    {
        dropDown->hide();
    }
    QLineEdit::focusOutEvent(e);
}

void KComboEdit::showEvent(QShowEvent *e)
{
    construct();
    if(NULL!=dropDown)
    {
        dropDown->hide();
    }
    QLineEdit::showEvent(e);
}

void KComboEdit::init(void)
{
    dropDown = new QListWidget(parent);
    buttonLeft = new QPushButton(parent);
    buttonRight = new QPushButton(parent);
    labelLeft = new QLabel(parent);
    labelRight = new QLabel(parent);
}

void KComboEdit::unInit(void)
{
    if(NULL!=dropDown)
    {
        //delete all the items
        int i=0;
        int count = dropDown->count();
        for(i=0; i<count; i++)
        {
            dropDown->takeItem(i);
        }

        delete dropDown;
        dropDown = NULL;
    }

    if(NULL!=buttonLeft)
    {
        delete buttonLeft;
        buttonLeft = NULL;
    }

    if(NULL!=buttonRight)
    {
        delete buttonRight;
        buttonRight = NULL;
    }

    if(NULL!=labelLeft)
    {
        delete labelLeft;
        labelLeft = NULL;
    }

    if(NULL!=labelRight)
    {
        delete labelRight;
        labelRight = NULL;
    }
}

void KComboEdit::construct(void)
{
    int w = width();
    int h = height();
    int x = geometry().x();
    int y = geometry().y();

    lower();

    //Position the push button
    if(NULL!=buttonLeft)
    {
        buttonLeft->setGeometry(QRect(x-h, y, h, h));
        buttonLeft->setFocusPolicy(Qt::NoFocus);
        buttonLeft->setCheckable(true);
    }

    if(NULL!=buttonRight)
    {
        buttonRight->setGeometry(QRect(x+w, y, h, h));
        buttonRight->setFocusPolicy(Qt::NoFocus);
        buttonRight->setCheckable(true);
    }

    //Position the lable
    if(NULL!=labelLeft)
    {
        labelLeft->setGeometry(QRect(x-h+1, y+1, h-2, h-2));
        labelLeft->setStyleSheet(QString::fromUtf8("QLabel {\n"
                                "image:url(:/icon_arrow_l.png);\n"
                                "}"));
    }

    if(NULL!=labelRight)
    {
        labelRight->setGeometry(QRect(x+w+1, y+1, h-2, h-2));;
        labelRight->setStyleSheet(QString::fromUtf8("QLabel {\n"
                                "image:url(:/icon_arrow_r.png);\n"
                                "}"));
    }

    //Position the list widget
    if(NULL!=dropDown)
    {
        dropDown->setGeometry(QRect(x, y+h, w, 2*h));
    }
}
