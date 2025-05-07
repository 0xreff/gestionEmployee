#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMouseEvent>
#include <QPushButton>
#include <QEvent>
#include <QPoint>
#include "mainwindow.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_3_clicked();

    void on_pass_forgot_clicked();

    void on_pushButton_clicked();

    void on_pass_label_returnPressed();

    void on_pushButton_2_clicked();

    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::Login *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint cur_pos;
    QPoint new_pos;
};

#endif // LOGIN_H
