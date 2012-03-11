#include "globe.h"
#include "UIKit.h"
#include "ui_menu_autosearch.h"
//////////////////////////////////// Menu local define  /////////////////////////

MenuAutoSearch *UI_pMenuAutoSearch=0;

//////////////////////////////////// Menu interface  /////////////////////////

MenuAutoSearch* UI_MenuAutoSearch_create()
{
	UI_pMenuAutoSearch = new MenuAutoSearch();
	UI_pMenuAutoSearch->setWindowFlags(Qt::FramelessWindowHint);
	return UI_pMenuAutoSearch;	
}

void UI_MenuAutoSearch_show()
{
	UI_pMenuAutoSearch->setGeometry(UI_menu_getx(UI_ID_VIDEO_SET),UI_menu_gety(UI_ID_VIDEO_SET),
														UI_menu_getw(UI_ID_VIDEO_SET),UI_menu_geth(UI_ID_VIDEO_SET));
	UI_pMenuAutoSearch->show();
}

void UI_MenuAutoSearch_hide()
{
	UI_MenuAutoSearch_setTVNumber(0);
	UI_MenuAutoSearch_setRadioNumber(0);
	UI_MenuAutoSearch_setOtherNumber(0);
	UI_MenuAutoSearch_setProgress(0);
	UI_MenuAutoSearch_setTitle(UI_ID_AUTO_SEARCH);
	UI_pMenuAutoSearch->hide();
}

void UI_MenuAutoSearch_setTVNumber(int number)
{
	UI_pMenuAutoSearch->setTVNumber(number);
}

void UI_MenuAutoSearch_setRadioNumber(int number)
{
	UI_pMenuAutoSearch->setRadioNumber(number);	
}

void UI_MenuAutoSearch_setOtherNumber(int number)
{
	UI_pMenuAutoSearch->setOtherNumber(number);
}

void UI_MenuAutoSearch_setTitle(int index)
{
	UI_pMenuAutoSearch->setTitle(index);
}

void UI_MenuAutoSearch_setProgress(int progress)
{
	UI_pMenuAutoSearch->setProgress(progress);
}

/////////////////////////////////// Menu Class instance /////////////////////////////

MenuAutoSearch::MenuAutoSearch(QWidget *parent) :
	QWidget(parent),
    ui(new Ui::MenuAutoSearch)
{
	ui->setupUi(this);
	
	this->setStyleSheet("QWidget {font:16pt;background-color: rgb(35,35,35);} ");
	ui->label_title->setStyleSheet("QLabel {background-color: rgb(63,63,63);}");
	ui->label_help->setStyleSheet("QLabel {background-color: rgb(63,63,63);}");

	ui->label_help->setText("Press RED key to stop");	
	
//	ui->label_tv_number->setText("100");
//	ui->label_radio_number->setText("100");
//	ui->label_other_number->setText("100");
}

MenuAutoSearch::~MenuAutoSearch()
{
    delete ui;
}

void MenuAutoSearch::setProgress(int progress)
{
	ui->progressBar->setValue(progress);
}

void MenuAutoSearch::setTVNumber(int number)
{
	QString strnum = QString::number(number);
	ui->label_tv_number->setText(strnum);
}

void MenuAutoSearch::setRadioNumber(int number)
{
	QString strnum = QString::number(number);
	ui->label_radio_number->setText(strnum);	
}

void MenuAutoSearch::setOtherNumber(int number)
{
	QString strnum = QString::number(number);
	ui->label_other_number->setText(strnum);	
}

void MenuAutoSearch::setTitle(int index)
{
	switch(index)
	{
		case UI_ID_AUTO_SEARCH:
			ui->label_title->setText("Auto Search");
			break;
		case UI_ID_MANUAL_SEARCH:
			ui->label_title->setText("Manual Search");
			break;
		default:
			break;	
	}
}


void MenuAutoSearch::keyPressEvent(QKeyEvent *event)
{
	MenuAutoSearch_key_press(event);  
    switch (event->key())
    {
        
        default:
            QWidget::keyPressEvent(event);
    }

}
