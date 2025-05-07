/********************************************************************************
** Form generated from reading UI file 'forgetpassword.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGETPASSWORD_H
#define UI_FORGETPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_forgetpassword
{
public:
    QFrame *frame;
    QLabel *exam;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *emailLineEdit;
    QLabel *label_5;
    QPushButton *verifyButton;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_timer;
    QLabel *label_6;
    QPushButton *pushButton;
    QLabel *label_7;

    void setupUi(QDialog *forgetpassword)
    {
        if (forgetpassword->objectName().isEmpty())
            forgetpassword->setObjectName("forgetpassword");
        forgetpassword->resize(400, 551);
        forgetpassword->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color:#251F33;\n"
"border-radius: 10px;\n"
"}\n"
"QLineEdit {\n"
"    qproperty-alignment: 'AlignCenter';\n"
"}"));
        frame = new QFrame(forgetpassword);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 381, 531));
        frame->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #251F33;\n"
"}\n"
"#pushButton{\n"
"border-radius: 5px;\n"
"}\n"
"#pushButton:hover{\n"
"border-radius: 5px;\n"
"background-color:#ff1f33\n"
"}\n"
"QLineEdit{\n"
"border: 1px solid #FA1E4E;\n"
"color: #aaaaaa;\n"
"border-radius:5px;\n"
"background-color:#251F33;\n"
"text-align: center;\n"
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
"#verifyButton{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"border-radius:2px;\n"
"border:1px solid #aaaaaa;\n"
"}\n"
"#verifyButton:hover{\n"
"color:#251f33;\n"
"border :1px solid #bbbbbb;\n"
"background-color: #aaaaaa;\n"
"}\n"
"#pushButton_2{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"border-radius:2px;\n"
"border:1p"
                        "x solid #aaaaaa;\n"
"}\n"
"#pushButton_2:hover{\n"
"color:#251f33;\n"
"border :1px solid #bbbbbb;\n"
"background-color: #aaaaaa;\n"
"}\n"
"#pushButton_3{\n"
"color: #01FE01;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"border-radius:2px;\n"
"border:1px solid #01FE01;\n"
"}\n"
"#pushButton_3:hover{\n"
"color:#251f33;\n"
"border :1px solid #bbbbbb;\n"
"background-color: #aaaaaa;\n"
"}\n"
"#pushButton{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"border-radius:2px;\n"
"border:1px solid #aaaaaa;\n"
"}\n"
"#pushButton:hover{\n"
"color:#251f33;\n"
"border :1px solid #bbbbbb;\n"
"background-color: #aaaaaa;\n"
"}\n"
"#label{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"font-weight:bold;\n"
"}\n"
"#label_timer{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"font-weight:bold;\n"
"}\n"
"#label_2{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"}\n"
""
                        "#label_3{\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"}\n"
"#exam{\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"color:#aaaaaa;\n"
"font-size:25px;\n"
"font-weight:bold;\n"
"}\n"
"#label_4{\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"color:#aaaaaa;\n"
"font-size:25px;\n"
"font-weight:bold;\n"
"}\n"
"#label_5{\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"color:#aaaaaa;\n"
"font-weight:bold;\n"
"}\n"
"\n"
"#label_6{\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"color:#aaaaaa;\n"
"font-weight:bold;\n"
"}\n"
"#label_7{\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"color:#aaaaaa;\n"
"font-weight:bold;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        exam = new QLabel(frame);
        exam->setObjectName("exam");
        exam->setGeometry(QRect(150, 0, 71, 31));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 30, 51, 21));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 80, 141, 21));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 110, 301, 21));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(140, 130, 81, 21));
        emailLineEdit = new QLineEdit(frame);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(30, 240, 311, 31));
        emailLineEdit->setStyleSheet(QString::fromUtf8("text-align: center;"));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 200, 311, 31));
        verifyButton = new QPushButton(frame);
        verifyButton->setObjectName("verifyButton");
        verifyButton->setGeometry(QRect(100, 280, 171, 24));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(20, 360, 51, 51));
        lineEdit_2->setStyleSheet(QString::fromUtf8("font-size:30px;\n"
"font-weight:bold;\n"
"text-align: center;"));
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(80, 360, 51, 51));
        lineEdit_3->setStyleSheet(QString::fromUtf8("font-size:30px;\n"
"font-weight:bold;\n"
"text-align: center;"));
        lineEdit_4 = new QLineEdit(frame);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(140, 360, 51, 51));
        lineEdit_4->setStyleSheet(QString::fromUtf8("font-size:30px;\n"
"font-weight:bold;\n"
"text-align: center;"));
        lineEdit_5 = new QLineEdit(frame);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(200, 360, 51, 51));
        lineEdit_5->setStyleSheet(QString::fromUtf8("font-size:30px;\n"
"font-weight:bold;\n"
"text-align: center;"));
        lineEdit_6 = new QLineEdit(frame);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(260, 360, 51, 51));
        lineEdit_6->setStyleSheet(QString::fromUtf8("font-size:30px;\n"
"font-weight:bold;\n"
"text-align: center;"));
        lineEdit_7 = new QLineEdit(frame);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(320, 360, 51, 51));
        lineEdit_7->setStyleSheet(QString::fromUtf8("font-size:30px;\n"
"font-weight:bold;\n"
"text-align: center;"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(100, 430, 171, 24));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(130, 500, 121, 24));
        label_timer = new QLabel(frame);
        label_timer->setObjectName("label_timer");
        label_timer->setGeometry(QRect(90, 320, 31, 21));
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(120, 320, 191, 21));
        label_6->setStyleSheet(QString::fromUtf8("\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"font-weight:bold;"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 10, 20, 20));
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(80, 470, 221, 21));
        label_7->setStyleSheet(QString::fromUtf8("\n"
"color: #aaaaaa;\n"
"font-family: 'Special Gothic Condensed One', sans-serif;\n"
"font-weight:bold;"));
        label_4->raise();
        exam->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        emailLineEdit->raise();
        label_5->raise();
        verifyButton->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        lineEdit_4->raise();
        lineEdit_5->raise();
        lineEdit_6->raise();
        lineEdit_7->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        label_timer->raise();
        label_6->raise();
        pushButton->raise();
        label_7->raise();

        retranslateUi(forgetpassword);

        QMetaObject::connectSlotsByName(forgetpassword);
    } // setupUi

    void retranslateUi(QDialog *forgetpassword)
    {
        forgetpassword->setWindowTitle(QCoreApplication::translate("forgetpassword", "Dialog", nullptr));
        exam->setText(QCoreApplication::translate("forgetpassword", "Exam", nullptr));
        label_4->setText(QCoreApplication::translate("forgetpassword", "Hub", nullptr));
        label->setText(QCoreApplication::translate("forgetpassword", "Recovering Password", nullptr));
        label_2->setText(QCoreApplication::translate("forgetpassword", "By Typing Your Email you will receive a message from", nullptr));
        label_3->setText(QCoreApplication::translate("forgetpassword", "support team.", nullptr));
        label_5->setText(QCoreApplication::translate("forgetpassword", "Email", nullptr));
        verifyButton->setText(QCoreApplication::translate("forgetpassword", "Send Verification", nullptr));
        pushButton_2->setText(QCoreApplication::translate("forgetpassword", "Verify", nullptr));
        pushButton_3->setText(QCoreApplication::translate("forgetpassword", "Login Page", nullptr));
        label_timer->setText(QString());
        label_6->setText(QCoreApplication::translate("forgetpassword", "To get new verification code...", nullptr));
        pushButton->setText(QCoreApplication::translate("forgetpassword", "X", nullptr));
        label_7->setText(QCoreApplication::translate("forgetpassword", "Do Not share you code with no one", nullptr));
    } // retranslateUi

};

namespace Ui {
    class forgetpassword: public Ui_forgetpassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGETPASSWORD_H
