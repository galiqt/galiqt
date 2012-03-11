#ifndef MENU_NETWORK_H
#define MENU_NETWORK_H

#include <QWidget>

#define MENU_NETWORK_DATA_LEN 20

namespace Ui {
class MenuNetworkWidget;
}

class MenuNetworkWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MenuNetworkWidget(QWidget *parent = 0);
    ~MenuNetworkWidget();
    void setData(void);
protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void showEvent(QShowEvent *e);
protected Q_SLOTS:
    void on_dhcpCheck_stateChanged(int);
private:
    void customSetupUi(void);
    void saveData(void);
private:
    Ui::MenuNetworkWidget *ui;
};

#endif // MENU_NETWORK_H
