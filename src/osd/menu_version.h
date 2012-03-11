#ifndef MENU_VERSION_H
#define MENU_VERSION_H

#include <QWidget>

#define MENU_VER_NUM_LEN    30
#define MENU_VER_MODEL_LEN  20
#define MENU_VER_DATE_LEN   20
#define MENU_VER_HW_LEN     20
#define MENU_VER_SW_LEN     20
#define MENU_VER_LOADER_LEN 20
#define MENU_VER_FACE_LEN   20
#define MENU_VER_APP_LEN    20
#define MENU_VER_AREA_LEN   20

namespace Ui {
class MenuVersionWidget;
}

class MenuVersionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuVersionWidget(QWidget *parent = 0);
    ~MenuVersionWidget();
    void setData(void);
protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void showEvent(QShowEvent *e);
private:
    void customSetupUi(void);
private:
    Ui::MenuVersionWidget *ui;
};

#endif // MENU_VERSION_H
