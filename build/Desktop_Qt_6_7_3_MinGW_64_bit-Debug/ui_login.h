/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFrame *frame;
    QLineEdit *email_label;
    QLineEdit *pass_label;
    QPushButton *pass_forgot;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(552, 346);
        Login->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color:#251F33;\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton{\n"
"background-color: #251F33;\n"
"}"));
        frame = new QFrame(Login);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 30, 481, 311));
        frame->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #251F33;\n"
"}\n"
"QLineEdit{\n"
"border: 1px solid #FA1E4E;\n"
"color: #aaaaaa;\n"
"border-radius:5px;\n"
"background-color:#251F33;\n"
"}\n"
"\n"
"QLineEdit:hover{\n"
"color: #aaaaaa;\n"
"border: 1px solid #01FE01;\n"
"}\n"
"#pass_forgot{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"border:none;\n"
"border-left: 1px solid #aaaaaa;\n"
"}\n"
"#pass_forgot:hover{\n"
"color:#bbbbbb;\n"
"}\n"
"#pushButton_2{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"border:none;\n"
"}\n"
"#pushButton_2:hover{\n"
"color:#bbbbbb;\n"
"}\n"
"#pushButton_3{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"border-radius:2px;\n"
"border:1px solid #aaaaaa;\n"
"}\n"
"#pushButton_3:hover{\n"
"color:#251f33;\n"
"border :1px solid #bbbbbb;\n"
"background-color: #aaaaaa;\n"
"}\n"
"#label{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"}\n"
"#label_2{\n"
""
                        "color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"}\n"
"#label_3{\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"color:#aaaaaa;\n"
"font-size:25px;\n"
"font-weight:bold;\n"
"font-style:normal;\n"
"}\n"
"#textEdit{\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"color:#aaaaaa;\n"
"font-style:normal;\n"
"}\n"
"#label_4{\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"color:#aaaaaa;\n"
"font-size:25px;\n"
"font-weight:bold;\n"
"font-style:normal;\n"
"}\n"
"#label_5{\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"color:#aaaaaa;\n"
"font-size:25px;\n"
"font-weight:bold;\n"
"font-style:normal;\n"
"}\n"
"#pushButton{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"border-radius:2px;\n"
"border:1px solid #aaaaaa;\n"
"}\n"
"#pushButton:hover{\n"
"color:#ff1f33;\n"
"border :1px solid #ffbbbb;\n"
"background-color: #aaaaaa;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        email_label = new QLineEdit(frame);
        email_label->setObjectName("email_label");
        email_label->setGeometry(QRect(42, 111, 391, 31));
        email_label->setStyleSheet(QString::fromUtf8(""));
        pass_label = new QLineEdit(frame);
        pass_label->setObjectName("pass_label");
        pass_label->setGeometry(QRect(40, 180, 391, 31));
        pass_label->setStyleSheet(QString::fromUtf8(""));
        pass_forgot = new QPushButton(frame);
        pass_forgot->setObjectName("pass_forgot");
        pass_forgot->setGeometry(QRect(230, 270, 131, 24));
        pass_forgot->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(160, 270, 61, 24));
        pushButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(120, 230, 231, 24));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 160, 61, 16));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 90, 61, 16));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 20, 71, 31));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 50, 71, 31));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(450, 10, 20, 20));
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(40, 80, 401, 181));
        textEdit->raise();
        label_4->raise();
        email_label->raise();
        pass_label->raise();
        pass_forgot->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        pushButton->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        pass_forgot->setText(QCoreApplication::translate("Login", "Mot de Passe oubli\303\251", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Login", "About us", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Login", "Login", nullptr));
        label->setText(QCoreApplication::translate("Login", "Password", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Email", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "Exam", nullptr));
        label_4->setText(QCoreApplication::translate("Login", "HUB", nullptr));
        pushButton->setText(QCoreApplication::translate("Login", "X", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Special Gothic Condensed One','sans-serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">is a central examination platform dedicated to managing academic evaluations efficiently</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">It handles diverse exam formats and offers int"
                        "elligent problem-solving tools for administrators and students alike</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Special thanks to Ben Belgacem, El Mezni, Ramma, Gmati, and Ghaith for their contributions to this initiative</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
