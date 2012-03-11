#ifndef MENU_AV_SETUP_H
#define MENU_AV_SETUP_H

#include <QWidget>

#define MENU_AV_SETUP_DATA_MASK     (0xF0)

#define MENU_AV_SETUP_VIDEO_GROUP   (0x0)
#define MENU_AV_SETUP_AUDIO_GROUP   (0x10)
#define MENU_AV_SETUP_SIZE_GROUP    (0x20)

#define MENU_AV_SETUP_VIDEO_576I    (MENU_AV_SETUP_VIDEO_GROUP)
#define MENU_AV_SETUP_VIDEO_576P    (MENU_AV_SETUP_VIDEO_GROUP+1)
#define MENU_AV_SETUP_VIDEO_720P    (MENU_AV_SETUP_VIDEO_GROUP+2)
#define MENU_AV_SETUP_VIDEO_1080I   (MENU_AV_SETUP_VIDEO_GROUP+3)

#define MENU_AV_SETUP_AUDIO_LEFT    (MENU_AV_SETUP_AUDIO_GROUP)
#define MENU_AV_SETUP_AUDIO_RIGHT   (MENU_AV_SETUP_AUDIO_GROUP+1)
#define MENU_AV_SETUP_AUDIO_STEREO  (MENU_AV_SETUP_AUDIO_GROUP+2)

#define MENU_AV_SETUP_SIZE_4_3      (MENU_AV_SETUP_SIZE_GROUP)
#define MENU_AV_SETUP_SIZE_16_9     (MENU_AV_SETUP_SIZE_GROUP+1)

typedef struct
{
    int idx;
    const char*	str;
}MENU_AV_SETUP_DATA_S;

namespace Ui {
class MenuAVSetupWidget;
}

class MenuAVSetupWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MenuAVSetupWidget(QWidget *parent = 0);
    ~MenuAVSetupWidget();
    void setData(void);
protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void showEvent(QShowEvent *e);
protected Q_SLOTS:
    void on_videoEdit_textChanged(const QString &string);
    void on_audioEdit_textChanged(const QString &string);
    void on_sizeEdit_textChanged(const QString &string);
private:
    void customSetupUi(void);
private:
    Ui::MenuAVSetupWidget *ui;
};

#endif // MENU_AV_SETUP_H
