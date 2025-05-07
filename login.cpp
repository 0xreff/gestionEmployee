#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include "forgetpassword.h"
#include <QRegularExpression>
#include <QSqlRecord>
#include <QFontDatabase>
Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->pushButton_2->installEventFilter(this);

    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground,true);
    ui->pass_label->setEchoMode(QLineEdit::Password);

    int id = QFontDatabase::addApplicationFont(":/fonts/SpecialGothicCondensedOne-Regular.ttf");
    if (id != -1) {
        QString fontFamily = QFontDatabase::applicationFontFamilies(id).at(0);
        QFont customFont(fontFamily, 12); // You can change the size
        ui->label->setFont(customFont);   // Apply it to any widget
    } else {
        qDebug() << "Font loading failed!";
    }
    ui->textEdit->hide();

}







void Login::mousePressEvent(QMouseEvent *event){
    cur_pos = event->globalPosition().toPoint();
}
void Login::mouseMoveEvent(QMouseEvent *event){
    new_pos = QPoint(event->globalPosition().toPoint() - cur_pos);
    move(x()+new_pos.x(),y()+new_pos.y());
    cur_pos = event->globalPosition().toPoint();
}
Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_3_clicked()
{
    QString email = ui->email_label->text().trimmed();
    QString password = ui->pass_label->text().trimmed();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both email and password.");
        return;
    }

    if (Employee::validateCredentials(email, password)) {
        this->close();
        MainWindow *mainWin = new MainWindow();
        mainWin->show();
    } else {
        QMessageBox::critical(this, "Login Failed", "Invalid email or password.");
    }
}



void Login::on_pass_forgot_clicked()
{
    this->close(); // Hide the login window

    forgetpassword *forgetDialog = new forgetpassword;
    forgetDialog->show();
}



void Login::on_pushButton_clicked()
{
    this->close();
}


void Login::on_pass_label_returnPressed()
{
    on_pushButton_3_clicked();
}

bool Login::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->pushButton_2 && event->type() == QEvent::Enter) {
        ui->label_2->hide();
        ui->label->hide();
        ui->email_label->hide();
        ui->pass_label->hide();
        ui->pushButton_3->hide();
        ui->textEdit->show();
        return true;
    }

    if(obj == ui->pushButton_2 && event->type() == QEvent::Leave){
        ui->label_2->show();
        ui->label->show();
        ui->email_label->show();
        ui->pass_label->show();
        ui->pushButton_3->show();
        ui->textEdit->hide();
        return true;
    }

    return QWidget::eventFilter(obj, event);

}

void Login::on_pushButton_2_clicked()
{

}

