#ifndef WIDGET_IP_EDIT_H
#define WIDGET_IP_EDIT_H

#include <QRegExpValidator>
#include <QLineEdit>
#include <QKeyEvent>
#include <QWidget>
#include <QLabel>

class KIPLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    KIPLineEdit(QWidget *parent = 0);
    ~KIPLineEdit(void);

    void set_nexttab_edit(QLineEdit *nexttab) { next_tab_ = nexttab; }
protected:
    virtual void focusInEvent(QFocusEvent *e);
    virtual void keyPressEvent(QKeyEvent *event);
private slots:
    void text_edited(const QString& text);
private:
    QLineEdit *next_tab_;
    QValidator *validator;
};

class KIPEdit : public QWidget
{
    Q_OBJECT
public:
    KIPEdit(QWidget* pParent = 0);
    ~KIPEdit();

    void setText(const QString &text);
    QString text();
    void setEditStyleSheet(const QString &styleSheet);
    void setLableStyleSheet(const QString &styleSheet);
signals:
    void textchanged(const QString& text);
    void textedited(const QString &text);
private slots:
    void textchangedslot(const QString& text);
    void texteditedslot(const QString &text);
protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void showEvent(QShowEvent *e);
private:
    void construct(void);
private:
    KIPLineEdit *ip_part1_;
    KIPLineEdit *ip_part2_;
    KIPLineEdit *ip_part3_;
    QLineEdit *ip_part4_;

    QLabel *labeldot1_;
    QLabel *labeldot2_;    
    QLabel *labeldot3_;
};
#endif // WIDGET_IP_EDIT_H
