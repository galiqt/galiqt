#include "globe.h"
#include "UIKit.h"
#include "ui_menu_manualsearch.h"
//////////////////////////////////// Menu local define  /////////////////////////

MenuManualSearch *UI_pMenuManualSearch=0;

//////////////////////////////////// Menu interface  /////////////////////////

MenuManualSearch* UI_MenuManualSearch_create()
{
	UI_pMenuManualSearch = new MenuManualSearch();
	UI_pMenuManualSearch->setWindowFlags(Qt::FramelessWindowHint);
	return UI_pMenuManualSearch;	
}

void UI_MenuManualSearch_show()
{
	UI_pMenuManualSearch->setGeometry(UI_menu_getx(UI_ID_MANUAL_SEARCH),UI_menu_gety(UI_ID_MANUAL_SEARCH),
									UI_menu_getw(UI_ID_MANUAL_SEARCH),UI_menu_geth(UI_ID_MANUAL_SEARCH));
	UI_pMenuManualSearch->show();
}

void UI_MenuManualSearch_hide()
{
	UI_pMenuManualSearch->hide();
}

bool UI_ManualSearch_set(int nStartFreq, int nEndFreq  ,int nSearchSymbol ,int nSearchQAM)
{
	if(UI_pMenuManualSearch)
	{
		return UI_pMenuManualSearch->ManualSearch_set(nStartFreq ,nEndFreq ,nSearchSymbol ,nSearchQAM);
	}else
	{	
		return false;
	}	
}

bool UI_ManualSearch_get(int *nStartFreq, int *nEndFreq ,int *nSearchSymbol ,int *nSearchQAM)
{
	if(UI_pMenuManualSearch)
	{	
		return	UI_pMenuManualSearch->ManualSearch_get(nStartFreq ,nEndFreq ,nSearchSymbol ,nSearchQAM);	
	}else
	{	
		return false;
	}
}

/////////////////////////////////// Menu Class instance /////////////////////////////

MenuManualSearch::MenuManualSearch(QWidget *parent) :
	QWidget(parent),
    ui(new Ui::MenuManualSearch)
{
	ui->setupUi(this);
	
	this->setStyleSheet("QWidget {font:16pt;background-color: rgb(35,35,35);} \
	QLineEdit {border-width:0;border-style:outset;color: rgb(255,255,255); background: rgb(92,92,92);} \
	QLineEdit:focus {border-width:0;border-style:outset; color: rgb(0,0,0); background: rgb(255,159,13);} \
	QPushButton {border-width:0; background-color: rgb(92,92,92);} \
	QPushButton:focus {background-color: rgb(255,159,13);}");	

	ui->label_title->setStyleSheet("QLabel {background-color: rgb(63,63,63);}");
	ui->label_help->setStyleSheet("QLabel {background-color: rgb(63,63,63);}");
	
	QRegExp regx("[1-9][0-9]{0,4}");

	QValidator *validator = new QRegExpValidator(regx, ui->letTPStart );
	ui->letTPStart->setValidator( validator ); 
	
	QValidator *validator2 = new QRegExpValidator(regx, ui->letTPEnd );
	ui->letTPEnd->setValidator( validator2 ); 

	QValidator *validator3 = new QRegExpValidator(regx, ui->letSymbol );
	ui->letSymbol->setValidator( validator3 ); 
	ui->cmbQam->addItem("QAM 16");//UI_QAM_16
	ui->cmbQam->addItem("QAM 32");//UI_QAM_32
	ui->cmbQam->addItem("QAM 64");//UI_QAM_54
	ui->cmbQam->addItem("QAM 128");//UI_QAM_128
	ui->cmbQam->addItem("QAM 256");//UI_QAM_256
	ui->cmbQam->addItem("QAM AUTO");//UI_QAM_AUTO
	ManualSearch_set(474,506,6875,UI_QAM_MIN);

}

MenuManualSearch::~MenuManualSearch()
{
    delete ui;
}

bool MenuManualSearch::ManualSearch_set(int nStartFreq, int nEndFreq ,int nSearchSymbol,int nSearchQAM )
{
	QString strnum;
	strnum = QString::number(nStartFreq);
	ui->letTPStart->setText(strnum);
	strnum = QString::number(nEndFreq);
	ui->letTPEnd->setText(strnum);
	strnum = QString::number(nSearchSymbol);	
	ui->letSymbol->setText(strnum);
	if((nSearchQAM>=UI_QAM_MIN)||(nSearchQAM<=UI_QAM_MAX))
	{
		ui->cmbQam->setRow(nSearchQAM - UI_QAM_MIN);
	}
	
	return true;	
}

bool MenuManualSearch::ManualSearch_get(int *nStartFreq, int *nEndFreq ,int *nSearchSymbol,int *nSearchQAM )
{
	QString numstr;
	int nQam;

	numstr = ui->letTPStart->text(); 
	*nStartFreq = numstr.toInt();
	
	numstr = ui->letTPEnd->text(); 
	*nEndFreq = numstr.toInt();
	
	numstr = ui->letSymbol->text(); 
	*nSearchSymbol = numstr.toInt();

	nQam = ui->cmbQam->getRow();
	numstr = QString::number(nQam);	
	*nSearchQAM = nQam;

	return true;	
}

void MenuManualSearch::on_btnScan_clicked(void)
{
	MenuManualSearch_on_scanClicked();
}

void MenuManualSearch::keyPressEvent(QKeyEvent *event)
{
	MenuManualSearch_key_press(event);  
    switch (event->key())
    {
        default:
            QWidget::keyPressEvent(event);
    }

}
