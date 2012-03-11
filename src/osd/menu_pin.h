#ifndef MENU_PIN_H
#define MENU_PIN_H

#include <QWidget>

namespace Ui {
class MenuPinWidget;
}

class MenuPinWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuPinWidget(QWidget *parent = 0);
    ~MenuPinWidget();
protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void showEvent(QShowEvent *e);
protected Q_SLOTS:
    void on_okButton_clicked(void);
    void on_cancelButton_clicked(void);
    void on_exitButton_clicked(void);
private:
    void customSetupUi(void);
    void setData(void);
private:
    Ui::MenuPinWidget *ui;
};

#endif // MENU_PIN_H
