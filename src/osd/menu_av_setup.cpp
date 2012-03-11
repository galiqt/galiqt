#include "globe.h"
#include "UIKit.h"
#include "ui_menu_av_setup.h"

MenuAVSetupWidget *UI_pMenuAVSetup=NULL;

MENU_AV_SETUP_DATA_S menu_av_setup_data[] =
{
    {MENU_AV_SETUP_VIDEO_576I, "576I"},
    {MENU_AV_SETUP_VIDEO_576P, "576P"},
    {MENU_AV_SETUP_VIDEO_720P, "720P"},
    {MENU_AV_SETUP_VIDEO_1080I, "1080I"},

    {MENU_AV_SETUP_AUDIO_LEFT, "左声道"},
    {MENU_AV_SETUP_AUDIO_RIGHT, "右声道"},
    {MENU_AV_SETUP_AUDIO_STEREO, "立体声"},

    {MENU_AV_SETUP_SIZE_4_3, "4:3"},
    {MENU_AV_SETUP_SIZE_16_9, "16:9"},
};

/* menu interface defined in 'UIKit.h' */
MenuAVSetupWidget* UI_MenuAVSetup_create()
{
    UI_pMenuAVSetup = new MenuAVSetupWidget();

    if(UI_pMenuAVSetup)
    {
        UI_pMenuAVSetup->setWindowFlags(Qt::FramelessWindowHint);

        QString* pStyleSheet = UI_styleSheet_get(UI_STYLESHEET_AV_SETUP);
        if (pStyleSheet)
        {
            UI_pMenuAVSetup->setStyleSheet(*pStyleSheet);
        }
    }

    return UI_pMenuAVSetup;
}

void UI_MenuAVSetup_show()
{
    if(UI_pMenuAVSetup)
    {
        UI_pMenuAVSetup->setGeometry(UI_menu_getx(UI_ID_AV_SETUP),UI_menu_gety(UI_ID_AV_SETUP),
                                                        UI_menu_getw(UI_ID_AV_SETUP),UI_menu_geth(UI_ID_AV_SETUP));
        UI_pMenuAVSetup->show();
    }
}

void UI_MenuAVSetup_hide()
{
    if(UI_pMenuAVSetup)
    {
        UI_pMenuAVSetup->hide();
    }
}

void UI_MenuAVSetup_update()
{
    if(UI_pMenuAVSetup)
    {
        UI_pMenuAVSetup->setData();
    }
}

MenuAVSetupWidget::MenuAVSetupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuAVSetupWidget)
{
    if(NULL!=ui)
    {
        ui->setupUi(this);
    }
    customSetupUi();
}

MenuAVSetupWidget::~MenuAVSetupWidget()
{
    delete ui;
}

void MenuAVSetupWidget::setData(void)
{
    int videoIdx = 0;
    int audioIdx = 0;
    int sizeIdx = 0;
    bool ret = 0;

    //get index from app
    ret = on_menuAVSetup_get(&videoIdx, &audioIdx, &sizeIdx);
    if(ret)
    {
        if(NULL!=ui->videoEdit)
        {
            ui->videoEdit->setRow(videoIdx);
        }

        if(NULL!=ui->audioEdit)
        {
            ui->audioEdit->setRow(audioIdx);
        }

        if(NULL!=ui->sizeEdit)
        {
            ui->sizeEdit->setRow(sizeIdx);
        }
    }
}

void MenuAVSetupWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()){
        case KEY_RC_MENU:
            #if 0
            if((NULL!=ui)
                &&(NULL!=ui->videoEdit)
                &&(NULL!=ui->audioEdit)
                &&(NULL!=ui->sizeEdit))
            {
                (void)on_menuAVSetup_set(ui->videoEdit->getRow(),
                                         ui->audioEdit->getRow(),
                                         ui->sizeEdit->getRow());
            }
            #endif
            this->hide();
            UI_menu_back();
            break;
        default:
            QWidget::keyPressEvent(e);
    }
}

void MenuAVSetupWidget::showEvent(QShowEvent *e)
{
    setData();
    QWidget::showEvent(e);
}

void MenuAVSetupWidget::on_videoEdit_textChanged(const QString &string)
{
    int row = 0;

    if((NULL != ui)
        && (NULL != ui->videoEdit))
    {
        row = ui->videoEdit->getRow();
    }

    qDebug("MenuAVSetupWidget::on_video_let_textChanged -> %s(%d)", string.toAscii().data(), row);
    #if 0
    switch((row|MENU_AV_SETUP_VIDEO_GROUP))
    {
        case MENU_AV_SETUP_VIDEO_576I:
            qDebug("MENU_AV_SETUP_VIDEO_576I");
            break;
        case MENU_AV_SETUP_VIDEO_576P:
            qDebug("MENU_AV_SETUP_VIDEO_576P");
            break;
        case MENU_AV_SETUP_VIDEO_720P:
            qDebug("MENU_AV_SETUP_VIDEO_720P");
            break;
        case MENU_AV_SETUP_VIDEO_1080I:
            qDebug("MENU_AV_SETUP_VIDEO_1080I");
            break;
        default:
            break;
    }
    #endif
    (void)on_menuAVSetup_videoSet(row);
}

void MenuAVSetupWidget::on_audioEdit_textChanged(const QString &string)
{
    int row = 0;

    if((NULL != ui)
        && (NULL != ui->audioEdit))
    {
        row = ui->audioEdit->getRow();
    }

    qDebug("MenuAVSetupWidget::on_audio_edit_textChanged -> %s(%d)", (const char*)string.toAscii().data(), row);
    #if 0
    switch((row|MENU_AV_SETUP_AUDIO_GROUP))
    {
        case MENU_AV_SETUP_AUDIO_LEFT:
            qDebug("MENU_AV_SETUP_AUDIO_LEFT");
            break;
        case MENU_AV_SETUP_AUDIO_RIGHT:
            qDebug("MENU_AV_SETUP_AUDIO_RIGHT");
            break;
        case MENU_AV_SETUP_AUDIO_STEREO:
            qDebug("MENU_AV_SETUP_AUDIO_STEREO");
            break;
        default:
            break;
    }
    #endif
    (void)on_menuAVSetup_audioSet(row);
}

void MenuAVSetupWidget::on_sizeEdit_textChanged(const QString &string)
{
    int row = 0;

    if((NULL != ui)
        && (NULL != ui->sizeEdit))
    {
        row = ui->sizeEdit->getRow();
    }

    qDebug("MenuAVSetupWidget::on_size_edit_textChanged -> %s(%d)", (const char*)string.toAscii().data(), row);
    #if 0
    switch((row|MENU_AV_SETUP_SIZE_GROUP))
    {
        case MENU_AV_SETUP_SIZE_4_3:
            qDebug("MENU_AV_SETUP_SZIE_4_3");
            break;
        case MENU_AV_SETUP_SIZE_16_9:
            qDebug("MENU_AV_SETUP_SZIE_16_9");
            break;
        default:
            break;
    }
    #endif
    (void)on_menuAVSetup_sizeSet(row);
}

void MenuAVSetupWidget::customSetupUi(void)
{
    int i = 0;
    int count = 0;

    if(NULL==ui)
    {
        return;
    }

    count = sizeof(menu_av_setup_data)/sizeof(MENU_AV_SETUP_DATA_S);

    //import data
    for(i=0; i<count; i++)
    {
        switch((menu_av_setup_data[i].idx)&MENU_AV_SETUP_DATA_MASK)
        {
            case MENU_AV_SETUP_VIDEO_GROUP:
                if(NULL!=ui->videoEdit)
                {
                    ui->videoEdit->addItem(tr(menu_av_setup_data[i].str));
                }
                break;
            case MENU_AV_SETUP_AUDIO_GROUP:
                if(NULL!=ui->audioEdit)
                {
                    ui->audioEdit->addItem(tr(menu_av_setup_data[i].str));
                }
                break;
            case MENU_AV_SETUP_SIZE_GROUP:
                if(NULL!=ui->sizeEdit)
                {
                    ui->sizeEdit->addItem(tr(menu_av_setup_data[i].str));
                }
                break;
            default:
                break;
        }
    }
}
