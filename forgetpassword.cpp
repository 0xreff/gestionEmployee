#include "forgetpassword.h"
#include "ui_forgetpassword.h"
#include "login.h"
#include "employee.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QRandomGenerator>
#include <src/SmtpMime>
#include <QtCore>
forgetpassword::forgetpassword(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::forgetpassword)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground,true);
    countdownTimer = new QTimer(this);
    countdownTimer->setInterval(1000); // 1 second interval
    connect(countdownTimer, &QTimer::timeout, this, &forgetpassword::updateCountdown);

    codeFields = {
        ui->lineEdit_2,
        ui->lineEdit_3,
        ui->lineEdit_4,
        ui->lineEdit_5,
        ui->lineEdit_6,
        ui->lineEdit_7
    };
    connect(ui->emailLineEdit, &QLineEdit::textChanged, this, [=](const QString &text) {
        QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
        bool isValid = emailRegex.match(text.trimmed()).hasMatch();

        if (isValid) {
            ui->emailLineEdit->setStyleSheet("border: 1px solid #01FE01;");
            ui->verifyButton->show();
        }
        else{
            ui->emailLineEdit->setStyleSheet("border: 1px solid #ff00af;");
        }
    });
    QRegularExpression regex("[A-Za-z0-9]");
    QValidator *validator = new QRegularExpressionValidator(regex, this);

    for (QLineEdit *field : codeFields) {
        field->setMaxLength(1);
        field->setAlignment(Qt::AlignCenter);
        field->setValidator(validator);
        field->installEventFilter(this);
    }
    ui->verifyButton->hide(); // hide initially

    connect(ui->emailLineEdit, &QLineEdit::textChanged, this, [=](const QString &text) {
        QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
        bool isValid = emailRegex.match(text.trimmed()).hasMatch();

        ui->verifyButton->setVisible(isValid);
    });

    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, [=]() {
        handleInputAndFocus(ui->lineEdit_2, ui->lineEdit_3);
    });
    connect(ui->lineEdit_3, &QLineEdit::textChanged, this, [=]() {
        handleInputAndFocus(ui->lineEdit_3, ui->lineEdit_4);
    });
    connect(ui->lineEdit_4, &QLineEdit::textChanged, this, [=]() {
        handleInputAndFocus(ui->lineEdit_4, ui->lineEdit_5);
    });
    connect(ui->lineEdit_5, &QLineEdit::textChanged, this, [=]() {
        handleInputAndFocus(ui->lineEdit_5, ui->lineEdit_6);
    });
    connect(ui->lineEdit_6, &QLineEdit::textChanged, this, [=]() {
        handleInputAndFocus(ui->lineEdit_6, ui->lineEdit_7);
    });
    connect(ui->lineEdit_7, &QLineEdit::textChanged, this, [=]() {
        QString text = ui->lineEdit_7->text();
        if (!text.isEmpty()) {
            ui->lineEdit_7->setText(text.toUpper());
        }
    });


    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_6->hide();
    ui->lineEdit_7->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_timer->hide();
    ui->pushButton_2->hide();
    ui->label_5->setAlignment(Qt::AlignCenter);
}

forgetpassword::~forgetpassword()
{
    delete ui;
}

void forgetpassword::on_pushButton_3_clicked()
{
    this->close();

    Login *l = new Login;
    l->show();
}



void forgetpassword::on_verifyButton_clicked()
{
    QString email = ui->emailLineEdit->text().trimmed();
    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,}$)");
    Employee emp;
    bool exists = emp.emailExists(email);
    if (!emailRegex.match(email).hasMatch()) {
        ui->label_5->setText("Wrong Email! \n Try Again");
        ui->emailLineEdit->setStyleSheet("border: 1px solid red;");
        return;
    }

    if (exists) {
        ui->label_5->setText("Email");
        ui->verifyButton->setCursor(Qt::ForbiddenCursor);
        ui->verifyButton->setText("--------🚫--------");
        ui->verifyButton->setEnabled(false);
        ui->lineEdit_2->show();
        ui->lineEdit_3->show();
        ui->lineEdit_4->show();
        ui->lineEdit_5->show();
        ui->lineEdit_6->show();
        ui->lineEdit_7->show();
        ui->label_6->show();
        ui->label_7->show();
        ui->label_timer->show();
        ui->pushButton_2->show();
        remainingSeconds = 60;
        /***********************************************************************/
        MimeMessage message;

        EmailAddress sender("asser.benbelgacem@esprit.tn", "examhub");
        message.setSender(sender);

        EmailAddress to(email, "Recipient's Name");
        message.addRecipient(to);

        message.setSubject("ExamHub: Reset Password");

        MimeText text;

        text.setText("Hi,\nYour Verification Code\n" + generateRandomCode() );
        message.addPart(&text);

        // Now we can send the mail
        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        smtp.connectToHost();
        if (!smtp.waitForReadyConnected()) {
            qDebug() << "Failed to connect to host!";
        }

        smtp.login("asser.benbelgacem@esprit.tn", "lhld bsfl oesi otjp");
        if (!smtp.waitForAuthenticated()) {
            qDebug() << "Failed to login!";
        }

        smtp.sendMail(message);
        if (!smtp.waitForMailSent()) {
            qDebug() << "Failed to send mail!";
        }

        smtp.quit();
        /*******************************************************************/
        ui->label_timer->setText(QString::number(remainingSeconds) + "s");
        countdownTimer->start();
    } else {
         ui->label_5->setText("Email not found in database.");
        ui->emailLineEdit->setStyleSheet("border: 1px solid red;");
        ui->lineEdit_2->hide();
        ui->lineEdit_3->hide();
        ui->lineEdit_4->hide();
        ui->lineEdit_5->hide();
        ui->lineEdit_6->hide();
        ui->lineEdit_7->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_timer->hide();
        ui->pushButton_2->hide();
    }



}

void forgetpassword::updateCountdown()
{
    remainingSeconds--;

    ui->label_timer->setText(QString::number(remainingSeconds) + "s");

    if (remainingSeconds <= 0) {
        countdownTimer->stop();
        ui->verifyButton->setEnabled(true);
        ui->verifyButton->setCursor(Qt::ArrowCursor);        // Re-enable verify button
        ui->label_timer->clear();
        ui->label_6->hide();
        ui->label_timer->hide();
        ui->verifyButton->setText("Try Again");            // Optional: Clear the label
    }
}


void forgetpassword::handleInputAndFocus(QLineEdit *current, QLineEdit *next)
{
    QString text = current->text();
    if (!text.isEmpty()) {
        current->setText(text.toUpper());  // Force uppercase
        next->setFocus();                 // Move to next field
    }
}



bool forgetpassword::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Backspace) {
            QLineEdit *current = qobject_cast<QLineEdit *>(obj);
            if (current && current->text().isEmpty()) {
                int index = codeFields.indexOf(current);
                if (index > 0) {
                    codeFields[index - 1]->setFocus();
                    codeFields[index - 1]->clear();
                }
            }
        }
    }
    return QWidget::eventFilter(obj, event);
}

void forgetpassword::on_pushButton_clicked()
{
    this->close();
}



QString forgetpassword::generateRandomCode() {
    const QString chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    QString code;
    for (int i = 0; i < 6; ++i) {
        int index = QRandomGenerator::global()->bounded(chars.length());
        code += chars[index];
    }
    verificationCode = code;
    return code;
}


void forgetpassword::on_pushButton_2_clicked()
{


    QString inputCode = ui->lineEdit_2->text().trimmed()
                        + ui->lineEdit_3->text().trimmed()
                        + ui->lineEdit_4->text().trimmed()
                        + ui->lineEdit_5->text().trimmed()
                        + ui->lineEdit_6->text().trimmed()
                        + ui->lineEdit_7->text().trimmed();

        if (inputCode.trimmed().toUpper() == verificationCode.trimmed().toUpper()) {
            ui->label_7->setAlignment(Qt::AlignCenter);
           ui->label_7->setText("Correct, Ckeck your Email");
        } else {
            ui->label_7->setAlignment(Qt::AlignCenter);
           ui->label_7->setText("False, Try Again");
        }
    }



