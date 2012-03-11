#include "widget_ip_edit.h"

KIPLineEdit::KIPLineEdit(QWidget *parent/* = 0*/)
: QLineEdit(parent)
{
    next_tab_ = NULL;

    this->setMaxLength(3);
    this->setFrame(false);
    this->setAlignment(Qt::AlignCenter);

    validator = NULL;
    validator = new QIntValidator(0, 255, this);
    this->setValidator(validator);

    connect(this, SIGNAL(textEdited(const QString&)), this, SLOT(text_edited(const QString&)));
}

KIPLineEdit::~KIPLineEdit(void)
{
    if(NULL!=validator)
    {
        delete validator;
        validator = NULL;
    }
}

void KIPLineEdit::focusInEvent(QFocusEvent *e)
{
    this->selectAll();
    QLineEdit::focusInEvent(e);
}

void KIPLineEdit::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Period:
            if (next_tab_)
            {
                next_tab_->setFocus();
                next_tab_->selectAll();
            }
            break;
        case Qt::Key_Right:
            if(this->cursorPosition() == this->text().length())
            {
                if(this->text().isEmpty())
                {
                    this->setText("0");
                }
                focusNextChild();
            }
            break;
        case Qt::Key_Left:
            if(this->cursorPosition() == 0)
            {
                if(this->text().isEmpty())
                {
                    this->setText("0");
                }
                focusPreviousChild();
            }
            break;
        default:
            break;
    }

    QLineEdit::keyPressEvent(event);
    QWidget::keyPressEvent(event);
}

void KIPLineEdit::text_edited(const QString& text)
{
    QIntValidator v(0, 255, this);
    QString ipaddr = text;
    int pos = 0;
    QValidator::State state = v.validate(ipaddr, pos);
    if (state == QValidator::Acceptable)
    {
        if (ipaddr.size() > 1)
        {
            if (ipaddr.size() == 2)
            {
                int ipnum = ipaddr.toInt();

                if (ipnum > 25)
                {
                    if (next_tab_)
                    {
                        next_tab_->setFocus();
                        next_tab_->selectAll();
                    }
                }
            }
            else
            {
                if (next_tab_)
                {
                    next_tab_->setFocus();
                    next_tab_->selectAll();
                }
            }
        }
    }
}

KIPEdit::KIPEdit(QWidget* pParent /* = 0 */)
: QWidget(pParent)
{
    ip_part1_ = new KIPLineEdit(this);
    ip_part2_ = new KIPLineEdit(this);
    ip_part3_ = new KIPLineEdit(this);
    ip_part4_ = new KIPLineEdit(this);

    labeldot1_ = new QLabel(this);
    labeldot2_ = new QLabel(this);
    labeldot3_ = new QLabel(this);

    QWidget::setTabOrder(ip_part1_, ip_part2_);
    QWidget::setTabOrder(ip_part2_, ip_part3_);
    QWidget::setTabOrder(ip_part3_, ip_part4_);
    ip_part1_->set_nexttab_edit(ip_part2_);
    ip_part2_->set_nexttab_edit(ip_part3_);
    ip_part3_->set_nexttab_edit(ip_part4_);


    connect(ip_part1_, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&)));
    connect(ip_part2_, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&)));
    connect(ip_part3_, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&)));
    connect(ip_part4_, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&)));

    connect(ip_part1_, SIGNAL(textEdited (const QString&)), this, SLOT(texteditedslot(const QString&)));
    connect(ip_part2_, SIGNAL(textEdited (const QString&)), this, SLOT(texteditedslot(const QString&)));
    connect(ip_part3_, SIGNAL(textEdited (const QString&)), this, SLOT(texteditedslot(const QString&)));
    connect(ip_part4_, SIGNAL(textEdited (const QString&)), this, SLOT(texteditedslot(const QString&)));

}

KIPEdit::~KIPEdit()
{
    if(NULL!=ip_part1_)
    {
        delete ip_part1_;
        ip_part1_ = NULL;
    }

    if(NULL!=ip_part2_)
    {
        delete ip_part2_;
        ip_part2_ = NULL;
    }

    if(NULL!=ip_part3_)
    {
        delete ip_part3_;
        ip_part3_ = NULL;
    }

    if(NULL!=ip_part4_)
    {
        delete ip_part4_;
        ip_part4_ = NULL;
    }

    if(NULL!=labeldot1_)
    {
        delete labeldot1_;
        labeldot1_ = NULL;
    }

    if(NULL!=labeldot2_)
    {
        delete labeldot2_;
        labeldot2_ = NULL;
    }

    if(NULL!=labeldot3_)
    {
        delete labeldot3_;
        labeldot3_ = NULL;
    }
}

void KIPEdit::textchangedslot(const QString& /*text*/)
{
    QString ippart1, ippart2, ippart3, ippart4;
    ippart1 = ip_part1_->text();
    ippart2 = ip_part2_->text();
    ippart3 = ip_part3_->text();
    ippart4 = ip_part4_->text();

    QString ipaddr = QString("%1.%2.%3.%4")
                     .arg(ippart1)
                     .arg(ippart2)
                     .arg(ippart3)
                     .arg(ippart4);

    emit textchanged(ipaddr);
}

void KIPEdit::texteditedslot(const QString &/*text*/)
{
    QString ippart1, ippart2, ippart3, ippart4;
    ippart1 = ip_part1_->text();
    ippart2 = ip_part2_->text();
    ippart3 = ip_part3_->text();
    ippart4 = ip_part4_->text();

    QString ipaddr = QString("%1.%2.%3.%4")
        .arg(ippart1)
        .arg(ippart2)
        .arg(ippart3)
        .arg(ippart4);

    emit textedited(ipaddr);
}

void KIPEdit::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Down:
            if(NULL!=ip_part4_)
            {
                ip_part4_->setFocus();
                focusNextChild();
            }
            break;
        case Qt::Key_Up:
            if(NULL!=ip_part1_)
            {
                ip_part1_->setFocus();
                focusPreviousChild();
            }
            break;
        default:
            break;
    }

    QWidget::keyPressEvent(event);
}

void KIPEdit::showEvent(QShowEvent *e)
{
    construct();
    QWidget::showEvent(e);
}

void KIPEdit::setText(const QString &text)
{
    QString ippart1, ippart2, ippart3, ippart4;
    QString qstring_validate = text;

    // IP地址验证
    QRegExp regexp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
    QRegExpValidator regexp_validator(regexp, this);
    int nPos = 0;
    QValidator::State state = regexp_validator.validate(qstring_validate, nPos);
    // IP合法
    if (state == QValidator::Acceptable)
    {
        QStringList ippartlist = text.split(".");
    
        int strcount = ippartlist.size();
        int index = 0;
        if (index < strcount)
        {
            ippart1 = ippartlist.at(index);
        }
        if (++index < strcount)
        {
            ippart2 = ippartlist.at(index);
        }
        if (++index < strcount)
        {
            ippart3 = ippartlist.at(index);
        }
        if (++index < strcount)
        {
            ippart4 = ippartlist.at(index);
        }
    }

    ip_part1_->setText(ippart1);
    ip_part2_->setText(ippart2);
    ip_part3_->setText(ippart3);
    ip_part4_->setText(ippart4);
}

QString KIPEdit::text()
{
    QString ippart1, ippart2, ippart3, ippart4;
    ippart1 = ip_part1_->text();
    ippart2 = ip_part2_->text();
    ippart3 = ip_part3_->text();
    ippart4 = ip_part4_->text();

    return QString("%1.%2.%3.%4")
        .arg(ippart1)
        .arg(ippart2)
        .arg(ippart3)
        .arg(ippart4);
}

void KIPEdit::setEditStyleSheet(const QString &styleSheet)
{
    ip_part1_->setStyleSheet(styleSheet);
    ip_part2_->setStyleSheet(styleSheet);
    ip_part3_->setStyleSheet(styleSheet);
    ip_part4_->setStyleSheet(styleSheet);
}

void KIPEdit::setLableStyleSheet(const QString &styleSheet)
{
    labeldot1_->setStyleSheet(styleSheet);
    labeldot2_->setStyleSheet(styleSheet);
    labeldot3_->setStyleSheet(styleSheet);
}

void KIPEdit::construct(void)
{
    int w = width();
    int h = height();

    w = w/4;
    ip_part1_->setGeometry(QRect(0, 0, w, h));
    ip_part2_->setGeometry(QRect(w, 0, w, h));
    ip_part3_->setGeometry(QRect(2*w, 0, w, h));
    ip_part4_->setGeometry(QRect(3*w, 0, w, h));

    labeldot1_->setText(".");
    labeldot1_->setGeometry(QRect(w-3, 0, 5, h));
    labeldot1_->setAlignment(Qt::AlignCenter);

    labeldot2_->setText(".");
    labeldot2_->setGeometry(QRect(2*w-3, 0, 5, h));
    labeldot2_->setAlignment(Qt::AlignCenter);

    labeldot3_->setText(".");
    labeldot3_->setGeometry(QRect(3*w-3, 0, 5, h));
    labeldot3_->setAlignment(Qt::AlignCenter);
}
