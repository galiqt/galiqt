#include "globe.h"
#include "UIKit.h"
#include "ui_menu_pin.h"

MenuPinWidget *UI_pMenuPin=NULL;

/* menu interface defined in 'UIKit.h' */
MenuPinWidget* UI_MenuPin_create()
{
    UI_pMenuPin = new MenuPinWidget();
    if(UI_pMenuPin)
	{    
        UI_pMenuPin->setWindowFlags(Qt::FramelessWindowHint);
        QString* pStyleSheet = UI_styleSheet_get(UI_STYLESHEET_PIN);
	    if (pStyleSheet)
	    {
            UI_pMenuPin->setStyleSheet(*pStyleSheet);
	    }
	}
	
    return UI_pMenuPin;
}

void UI_MenuPin_show()
{
    if(UI_pMenuPin)
	{
        UI_pMenuPin->setGeometry(UI_menu_getx(UI_ID_PIN),UI_menu_gety(UI_ID_PIN),
                                 UI_menu_getw(UI_ID_PIN),UI_menu_geth(UI_ID_PIN));
        UI_pMenuPin->show();
	}
}

void UI_MenuPin_hide()
{
    if(UI_pMenuPin)
	{
        UI_pMenuPin->hide();
	}
}

/* menu class defined in 'menu_pin.h' */
MenuPinWidget::MenuPinWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPinWidget)
{
    if(NULL!=ui)
    {
        ui->setupUi(this);
    }
    customSetupUi();
}

MenuPinWidget::~MenuPinWidget()
{
    delete ui;
}

void MenuPinWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case KEY_RC_DOWN:
            focusNextChild();
            break;
        default:
            QWidget::keyPressEvent(event);
            break;
    }
}

void MenuPinWidget::showEvent(QShowEvent *e)
{
    setData();
    QWidget::showEvent(e);
}

void MenuPinWidget::on_okButton_clicked()
{
    bool ret = 0;

    if((NULL==ui) || (NULL==ui->pinEdit))
    {
        return;
    }

    ret = on_MenuPin_checkPassword(ui->pinEdit->text().toAscii().data());
    if(ret)
    {
        hide();
    }
    else
    {
        if(NULL!=ui->errLabel)
        {
            ui->errLabel->setText(tr("ÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë£¡"));
            if(NULL!=ui->pinEdit)
            {
                ui->pinEdit->clear();
                ui->pinEdit->setFocus();
            }
        }
    }
}

void MenuPinWidget::on_cancelButton_clicked()
{
    if(NULL==ui)
    {
        return;
    }

    if(NULL!=ui->pinEdit)
    {
        ui->pinEdit->clear();
        ui->pinEdit->setFocus();
    }

    if(NULL!=ui->pinEdit)
    {
        ui->errLabel->clear();
    }
}

void MenuPinWidget::on_exitButton_clicked()
{
    hide();
}

void MenuPinWidget::customSetupUi(void)
{
    //language switch can be set here.
}

void MenuPinWidget::setData(void)
{
    if(NULL==ui)
    {
        return;
    }

    if(NULL!=ui->pinEdit)
    {
        ui->pinEdit->clear();
        ui->pinEdit->setFocus();
    }
}
