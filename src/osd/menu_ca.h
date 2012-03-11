#ifndef MENU_CA_H
#define MENU_CA_H

#include <QWidget>

#define MENU_CA_DATA_LEN 20

namespace Ui {
class MenuCaWidget;
}

class MenuCaWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MenuCaWidget(QWidget *parent = 0);
    ~MenuCaWidget();
    void setData(void);
protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void showEvent(QShowEvent *e);
private:
    void customSetupUi(void);
private:
    Ui::MenuCaWidget *ui;
};

#endif // MENU_CA_H
