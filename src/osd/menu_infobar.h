#ifndef MENU_INFOBAR_H
#define MENU_INFOBAR_H

#include <QWidget>

#define MENU_INFOBAR_ID_LEN 3
#define MENU_INFOBAR_PROGRAM_NAME_LEN 50
#define MENU_INFOBAR_NUM_LEN 50
#define MENU_INFOBAR_EVENT_NAME_LEN 50
#define MENU_INFOBAR_EVENT_TIME_LEN 50

namespace Ui {
class MenuInfobarWidget;
}

class MenuInfobarWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MenuInfobarWidget(QWidget *parent = 0);
    ~MenuInfobarWidget();
     void setData(void);
protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void showEvent(QShowEvent *e);
private:
    void customSetupUi(void);
private:
    Ui::MenuInfobarWidget *ui;
};

#endif // MENU_INFOBAR_H
