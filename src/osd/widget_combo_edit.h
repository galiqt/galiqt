#ifndef WIDGET_COMBO_EDIT_H
#define WIDGET_COMBO_EDIT_H

#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>

class QListWidget;
class QPushButton;
class QLabel;

class KComboEdit : public QLineEdit {

    Q_OBJECT
public:
    explicit KComboEdit(QWidget *parent = 0);
    ~KComboEdit(void);
    void addItem(const QString &text);
    int getRow(void);
    void setRow(int row);
protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void focusOutEvent(QFocusEvent *e);
    virtual void showEvent(QShowEvent *e);
private:
    void init(void);
    void unInit(void);
    void construct();
private:
    QListWidget *dropDown;
    QPushButton *buttonLeft;
    QPushButton *buttonRight;
    QLabel *labelLeft;
    QLabel *labelRight;
    QWidget *parent;
};

#endif // WIDGET_COMBO_EDIT_H
