#include "globe.h"
#include "UIKit.h"
#include "ui_menu_version.h"

MenuVersionWidget *UI_pMenuVersion=NULL;

/* menu interface defined in 'uikit.h' */
MenuVersionWidget* UI_MenuVersion_create()
{
    UI_pMenuVersion = new MenuVersionWidget();
	if(UI_pMenuVersion)
	{    
		UI_pMenuVersion->setWindowFlags(Qt::FramelessWindowHint);

	    QString* pStyleSheet = UI_styleSheet_get(UI_STYLESHEET_COMMON);
	    if (pStyleSheet)
	    {
	        UI_pMenuVersion->setStyleSheet(*pStyleSheet);
	    }
	}
	
    return UI_pMenuVersion;
}

void UI_MenuVersion_show()
{
	if(UI_pMenuVersion)
	{
    	UI_pMenuVersion->setGeometry(UI_menu_getx(UI_ID_VERSION),UI_menu_gety(UI_ID_VERSION),
                                                        UI_menu_getw(UI_ID_VERSION),UI_menu_geth(UI_ID_VERSION));
    	UI_pMenuVersion->show();
	}
}

void UI_MenuVersion_hide()
{
	if(UI_pMenuVersion)
	{
    	UI_pMenuVersion->hide();
	}
}

void UI_MenuVersion_update()
{
    if(UI_pMenuVersion)
    {
        UI_pMenuVersion->setData();
    }
}

/* menu class defined in 'menu_version.h' */
MenuVersionWidget::MenuVersionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuVersionWidget)
{
    if(NULL!=ui)
    {
        ui->setupUi(this);
    }
    customSetupUi();
}

MenuVersionWidget::~MenuVersionWidget()
{
    delete ui;
}

void MenuVersionWidget::setData(void)
{
    char num[MENU_VER_NUM_LEN]={0};
    char model[MENU_VER_MODEL_LEN]={0};
    char date[MENU_VER_DATE_LEN]={0};
    char hw[MENU_VER_HW_LEN]={0};
    char sw[MENU_VER_SW_LEN]={0};
    char loader[MENU_VER_LOADER_LEN]={0};
    char face[MENU_VER_FACE_LEN]={0};
    char app[MENU_VER_APP_LEN]={0};
    char area[MENU_VER_AREA_LEN]={0};
    bool ret = false;

    if(NULL==ui)
    {
        return;
    }

    ret = on_menuVersion_get(num, MENU_VER_NUM_LEN,
                             model, MENU_VER_MODEL_LEN,
                             date, MENU_VER_DATE_LEN,
                             hw, MENU_VER_HW_LEN,
                             sw, MENU_VER_SW_LEN,
                             loader, MENU_VER_LOADER_LEN,
                             face, MENU_VER_FACE_LEN,
                             app, MENU_VER_APP_LEN,
                             area, MENU_VER_AREA_LEN);
    if(ret)
    {
        if(NULL!=ui->numLabel)
        {
            ui->numLabel->setText(QObject::tr(num));
        }

        if(NULL!=ui->modelLabel)
        {
            ui->modelLabel->setText(QObject::tr(model));
        }

        if(NULL!=ui->dateLabel)
        {
            ui->dateLabel->setText(QObject::tr(date));
        }

        if(NULL!=ui->hwLabel)
        {
            ui->hwLabel->setText(QObject::tr(hw));
        }

        if(NULL!=ui->swLabel)
        {
            ui->swLabel->setText(QObject::tr(sw));
        }

        if(NULL!=ui->loaderLabel)
        {
            ui->loaderLabel->setText(QObject::tr(loader));
        }

        if(NULL!=ui->faceLabel)
        {
            ui->faceLabel->setText(QObject::tr(face));
        }

        if(NULL!=ui->appLabel)
        {
            ui->appLabel->setText(QObject::tr(app));
        }

        if(NULL!=ui->areaLabel)
        {
            ui->areaLabel->setText(QObject::tr(area));
        }
    }
}

void MenuVersionWidget::keyPressEvent(QKeyEvent *event)
{
	switch (event->key()){
		case KEY_RC_MENU:
			this->hide();
			UI_menu_back();
			break;
		default:
			QWidget::keyPressEvent(event);
	}	
}

void MenuVersionWidget::showEvent(QShowEvent *e)
{
    setData();
	QWidget::showEvent(e);
}

void MenuVersionWidget::customSetupUi(void)
{
    //language switch can be set here.
}
