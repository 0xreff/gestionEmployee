/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *update;
    QTabWidget *Gestion;
    QWidget *Ajouter_1;
    QLineEdit *Nom;
    QLineEdit *Prenom;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *Tel;
    QLabel *label_4;
    QFrame *line;
    QLineEdit *Email;
    QLabel *label_5;
    QComboBox *Gender;
    QLabel *label_6;
    QDateEdit *Dob;
    QLabel *label_7;
    QLineEdit *Pass;
    QLabel *label_8;
    QLineEdit *Photo;
    QLabel *label_9;
    QPushButton *upload_btn;
    QLabel *label_10;
    QComboBox *Poste;
    QPushButton *Ajouter;
    QPushButton *Reset;
    QLabel *label_22;
    QComboBox *etab;
    QWidget *Read;
    QTableView *tableView;
    QPushButton *Actualiser;
    QLineEdit *search_line;
    QComboBox *comboBox;
    QPushButton *search_btn;
    QPushButton *trier;
    QPushButton *delete_btn;
    QWidget *Modifier;
    QComboBox *Posteu;
    QDateEdit *Dobu;
    QLineEdit *Prenomu;
    QComboBox *Genderu;
    QLineEdit *Emailu;
    QLineEdit *Telu;
    QLineEdit *Passu;
    QLineEdit *Nomu;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *Photou;
    QComboBox *searchComboBox;
    QPushButton *update_btn;
    QLineEdit *searchLineEdit;
    QPushButton *updated_btn;
    QLabel *label_19;
    QPushButton *select;
    QWidget *tab;
    QLabel *label_20;
    QLabel *label_total;
    QLabel *label_21;
    QLabel *label_men;
    QLabel *label_men_percent;
    QLabel *label_women_percent;
    QLabel *label_42;
    QLabel *label_women;
    QLabel *label_43;
    QLabel *label_admin;
    QLabel *label_44;
    QLabel *label_transporteurs;
    QLabel *label_45;
    QLabel *label_employees;
    QLabel *label_46;
    QLabel *label_etudiants;
    QFrame *line_3;
    QFrame *frame;
    QLabel *label_no_photo;
    QLabel *label_47;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *Oo;
    QLabel *Or;
    QLabel *Tt;
    QLabel *Au;
    QLabel *Poo;
    QLabel *Por;
    QLabel *Ptt;
    QLineEdit *idLineEdit;
    QPushButton *speakButton;
    QLabel *speechLabel;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1085, 482);
        MainWindow->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"QPushButton {\n"
"    background-color: #4CAF50; /* Vert pour les boutons */\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 10px 20px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    display: inline-block;\n"
"    font-size: 16px;\n"
"    margin: 4px 2px;\n"
"    cursor: pointer;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:#f1f1f1;\n"
"border: 1px solid gray;\n"
"border-radius: 15px;\n"
"}\n"
"QLineEdit{\n"
"background:#f1f1f1;\n"
"border-bottom: 2px solid gray;\n"
"}"));
        update = new QGraphicsView(centralwidget);
        update->setObjectName("update");
        update->setGeometry(QRect(0, 0, 1081, 571));
        update->setStyleSheet(QString::fromUtf8("/* Style pour la barre de navigation (QNavBar) */\n"
"QGraphicsView {\n"
"    background-color: #003366; /* Bleu roi */\n"
"    padding: 10px;\n"
"    border-bottom: 2px solid #001f3f; /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"/* Style pour les boutons dans la barre de navigation */\n"
"QGraphicsView QPushButton {\n"
"    background-color: #00509e; /* Bleu plus clair */\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 10px 20px;\n"
"    font-size: 16px;\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    transition: background-color 0.3s ease, transform 0.2s ease; /* Animation */\n"
"}\n"
"\n"
"/* Effet au survol des boutons */\n"
"QGraphicsView QPushButton:hover {\n"
"    background-color: #0077cc; /* Bleu plus vif au survol */\n"
"    transform: scale(1.05); /* L\303\251g\303\250re augmentation de taille */\n"
"}\n"
"\n"
"/* Effet au clic des boutons */\n"
"QGraphicsView QPushButton:pressed {\n"
"    background-color: #001f3f; /* Bleu plus fonc\303\251 au clic */\n"
"    transform: sca"
                        "le(0.95); /* L\303\251g\303\250re r\303\251duction de taille */\n"
"}\n"
"\n"
"/* Style pour les boutons actifs (optionnel) */\n"
"QGraphicsView QPushButton:checked {\n"
"    background-color: #001f3f; /* Bleu fonc\303\251 pour le bouton actif */\n"
"    border: 2px solid #00509e; /* Bordure pour le bouton actif */\n"
"}"));
        Gestion = new QTabWidget(centralwidget);
        Gestion->setObjectName("Gestion");
        Gestion->setGeometry(QRect(20, 110, 1041, 361));
        Gestion->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:none;\n"
"}\n"
"QLineEdit{\n"
"border:none;\n"
"border-bottom: 2px solid gray;\n"
"}\n"
"QLineEdit:hover{\n"
"background-color: #c4c4c4;\n"
"border-bottom: 3px solid #eb38d6;\n"
"}"));
        Ajouter_1 = new QWidget();
        Ajouter_1->setObjectName("Ajouter_1");
        Ajouter_1->setStyleSheet(QString::fromUtf8(""));
        Nom = new QLineEdit(Ajouter_1);
        Nom->setObjectName("Nom");
        Nom->setGeometry(QRect(150, 20, 341, 31));
        Nom->setStyleSheet(QString::fromUtf8(""));
        Prenom = new QLineEdit(Ajouter_1);
        Prenom->setObjectName("Prenom");
        Prenom->setGeometry(QRect(150, 70, 341, 31));
        label_2 = new QLabel(Ajouter_1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 20, 41, 31));
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(Ajouter_1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 70, 61, 31));
        label_3->setStyleSheet(QString::fromUtf8(""));
        Tel = new QLineEdit(Ajouter_1);
        Tel->setObjectName("Tel");
        Tel->setGeometry(QRect(150, 130, 341, 31));
        label_4 = new QLabel(Ajouter_1);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 130, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(Ajouter_1);
        line->setObjectName("line");
        line->setGeometry(QRect(510, 20, 21, 261));
        line->setStyleSheet(QString::fromUtf8("border-top:none;\n"
"border-bottom:none;\n"
"size:2px;\n"
"color:black;"));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        Email = new QLineEdit(Ajouter_1);
        Email->setObjectName("Email");
        Email->setGeometry(QRect(150, 190, 341, 31));
        label_5 = new QLabel(Ajouter_1);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(90, 190, 51, 31));
        label_5->setStyleSheet(QString::fromUtf8(""));
        Gender = new QComboBox(Ajouter_1);
        Gender->addItem(QString());
        Gender->addItem(QString());
        Gender->setObjectName("Gender");
        Gender->setGeometry(QRect(150, 250, 331, 22));
        Gender->setStyleSheet(QString::fromUtf8(""));
        label_6 = new QLabel(Ajouter_1);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(80, 240, 61, 31));
        label_6->setStyleSheet(QString::fromUtf8(""));
        Dob = new QDateEdit(Ajouter_1);
        Dob->setObjectName("Dob");
        Dob->setGeometry(QRect(710, 20, 311, 31));
        label_7 = new QLabel(Ajouter_1);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(550, 20, 151, 31));
        label_7->setStyleSheet(QString::fromUtf8(""));
        Pass = new QLineEdit(Ajouter_1);
        Pass->setObjectName("Pass");
        Pass->setGeometry(QRect(710, 120, 311, 31));
        Pass->setStyleSheet(QString::fromUtf8(""));
        label_8 = new QLabel(Ajouter_1);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(550, 120, 111, 31));
        label_8->setStyleSheet(QString::fromUtf8(""));
        Photo = new QLineEdit(Ajouter_1);
        Photo->setObjectName("Photo");
        Photo->setGeometry(QRect(710, 220, 311, 31));
        Photo->setStyleSheet(QString::fromUtf8(""));
        label_9 = new QLabel(Ajouter_1);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(550, 220, 111, 31));
        label_9->setStyleSheet(QString::fromUtf8(""));
        upload_btn = new QPushButton(Ajouter_1);
        upload_btn->setObjectName("upload_btn");
        upload_btn->setGeometry(QRect(890, 250, 131, 31));
        upload_btn->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid gray;"));
        label_10 = new QLabel(Ajouter_1);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(550, 70, 151, 31));
        label_10->setStyleSheet(QString::fromUtf8(""));
        Poste = new QComboBox(Ajouter_1);
        Poste->addItem(QString());
        Poste->addItem(QString());
        Poste->addItem(QString());
        Poste->addItem(QString());
        Poste->setObjectName("Poste");
        Poste->setGeometry(QRect(710, 80, 311, 22));
        Poste->setStyleSheet(QString::fromUtf8(""));
        Ajouter = new QPushButton(Ajouter_1);
        Ajouter->setObjectName("Ajouter");
        Ajouter->setGeometry(QRect(620, 290, 261, 31));
        Ajouter->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid gray;\n"
"color:#01ff11;"));
        Reset = new QPushButton(Ajouter_1);
        Reset->setObjectName("Reset");
        Reset->setGeometry(QRect(890, 290, 131, 31));
        Reset->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid gray;\n"
"background:#ff0101;"));
        label_22 = new QLabel(Ajouter_1);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(550, 170, 111, 31));
        etab = new QComboBox(Ajouter_1);
        etab->setObjectName("etab");
        etab->setGeometry(QRect(710, 171, 311, 31));
        Gestion->addTab(Ajouter_1, QString());
        Read = new QWidget();
        Read->setObjectName("Read");
        tableView = new QTableView(Read);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(-5, 50, 811, 281));
        Actualiser = new QPushButton(Read);
        Actualiser->setObjectName("Actualiser");
        Actualiser->setGeometry(QRect(0, 0, 281, 41));
        Actualiser->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid gray;\n"
"color:#01ff11;"));
        search_line = new QLineEdit(Read);
        search_line->setObjectName("search_line");
        search_line->setGeometry(QRect(810, 0, 221, 41));
        comboBox = new QComboBox(Read);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(810, 50, 131, 31));
        search_btn = new QPushButton(Read);
        search_btn->setObjectName("search_btn");
        search_btn->setGeometry(QRect(950, 50, 75, 31));
        search_btn->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid gray;\n"
"background:#f1f1f1;"));
        trier = new QPushButton(Read);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(810, 90, 211, 31));
        trier->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid gray;\n"
"background:#f1f1f1;"));
        delete_btn = new QPushButton(Read);
        delete_btn->setObjectName("delete_btn");
        delete_btn->setGeometry(QRect(810, 130, 211, 31));
        delete_btn->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid gray;\n"
"background:#f1f1f1;\n"
"color:red;\n"
""));
        Gestion->addTab(Read, QString());
        Modifier = new QWidget();
        Modifier->setObjectName("Modifier");
        Posteu = new QComboBox(Modifier);
        Posteu->addItem(QString());
        Posteu->addItem(QString());
        Posteu->addItem(QString());
        Posteu->addItem(QString());
        Posteu->setObjectName("Posteu");
        Posteu->setGeometry(QRect(670, 80, 311, 22));
        Posteu->setStyleSheet(QString::fromUtf8(""));
        Dobu = new QDateEdit(Modifier);
        Dobu->setObjectName("Dobu");
        Dobu->setGeometry(QRect(670, 20, 311, 31));
        Prenomu = new QLineEdit(Modifier);
        Prenomu->setObjectName("Prenomu");
        Prenomu->setGeometry(QRect(110, 70, 341, 31));
        Genderu = new QComboBox(Modifier);
        Genderu->addItem(QString());
        Genderu->addItem(QString());
        Genderu->setObjectName("Genderu");
        Genderu->setGeometry(QRect(110, 250, 331, 22));
        Genderu->setStyleSheet(QString::fromUtf8(""));
        Emailu = new QLineEdit(Modifier);
        Emailu->setObjectName("Emailu");
        Emailu->setGeometry(QRect(110, 190, 341, 31));
        Telu = new QLineEdit(Modifier);
        Telu->setObjectName("Telu");
        Telu->setGeometry(QRect(110, 130, 341, 31));
        Passu = new QLineEdit(Modifier);
        Passu->setObjectName("Passu");
        Passu->setGeometry(QRect(670, 120, 311, 31));
        Passu->setStyleSheet(QString::fromUtf8(""));
        Nomu = new QLineEdit(Modifier);
        Nomu->setObjectName("Nomu");
        Nomu->setGeometry(QRect(110, 20, 341, 31));
        Nomu->setStyleSheet(QString::fromUtf8(""));
        label_11 = new QLabel(Modifier);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(510, 20, 151, 31));
        label_11->setStyleSheet(QString::fromUtf8(""));
        label_12 = new QLabel(Modifier);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 130, 81, 31));
        label_12->setStyleSheet(QString::fromUtf8(""));
        label_13 = new QLabel(Modifier);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 70, 61, 31));
        label_13->setStyleSheet(QString::fromUtf8(""));
        label_14 = new QLabel(Modifier);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(40, 20, 41, 31));
        label_14->setStyleSheet(QString::fromUtf8(""));
        label_15 = new QLabel(Modifier);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(520, 70, 151, 31));
        label_15->setStyleSheet(QString::fromUtf8(""));
        label_16 = new QLabel(Modifier);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(40, 240, 61, 31));
        label_16->setStyleSheet(QString::fromUtf8(""));
        label_17 = new QLabel(Modifier);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(520, 120, 111, 31));
        label_17->setStyleSheet(QString::fromUtf8(""));
        label_18 = new QLabel(Modifier);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(50, 190, 51, 31));
        label_18->setStyleSheet(QString::fromUtf8(""));
        Photou = new QLineEdit(Modifier);
        Photou->setObjectName("Photou");
        Photou->setGeometry(QRect(670, 170, 311, 31));
        Photou->setStyleSheet(QString::fromUtf8(""));
        searchComboBox = new QComboBox(Modifier);
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->setObjectName("searchComboBox");
        searchComboBox->setGeometry(QRect(470, 290, 131, 31));
        update_btn = new QPushButton(Modifier);
        update_btn->setObjectName("update_btn");
        update_btn->setGeometry(QRect(610, 290, 75, 31));
        update_btn->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid gray;\n"
"background:#f1f1f1;"));
        searchLineEdit = new QLineEdit(Modifier);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(470, 240, 221, 41));
        updated_btn = new QPushButton(Modifier);
        updated_btn->setObjectName("updated_btn");
        updated_btn->setGeometry(QRect(710, 240, 311, 81));
        updated_btn->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid gray;\n"
"background:#f1f1f1;"));
        label_19 = new QLabel(Modifier);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(530, 170, 111, 31));
        label_19->setStyleSheet(QString::fromUtf8(""));
        select = new QPushButton(Modifier);
        select->setObjectName("select");
        select->setGeometry(QRect(880, 200, 101, 31));
        select->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid gray;\n"
"background:#f1f1f1;"));
        Gestion->addTab(Modifier, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        label_20 = new QLabel(tab);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(320, 20, 111, 16));
        label_total = new QLabel(tab);
        label_total->setObjectName("label_total");
        label_total->setGeometry(QRect(450, 20, 49, 16));
        label_21 = new QLabel(tab);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(30, 250, 91, 16));
        label_men = new QLabel(tab);
        label_men->setObjectName("label_men");
        label_men->setGeometry(QRect(150, 250, 21, 16));
        label_men_percent = new QLabel(tab);
        label_men_percent->setObjectName("label_men_percent");
        label_men_percent->setGeometry(QRect(200, 250, 49, 16));
        label_women_percent = new QLabel(tab);
        label_women_percent->setObjectName("label_women_percent");
        label_women_percent->setGeometry(QRect(200, 290, 49, 16));
        label_42 = new QLabel(tab);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(30, 290, 91, 16));
        label_women = new QLabel(tab);
        label_women->setObjectName("label_women");
        label_women->setGeometry(QRect(150, 290, 21, 16));
        label_43 = new QLabel(tab);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(30, 80, 91, 16));
        label_admin = new QLabel(tab);
        label_admin->setObjectName("label_admin");
        label_admin->setGeometry(QRect(140, 80, 21, 16));
        label_44 = new QLabel(tab);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(30, 130, 131, 16));
        label_transporteurs = new QLabel(tab);
        label_transporteurs->setObjectName("label_transporteurs");
        label_transporteurs->setGeometry(QRect(170, 130, 21, 16));
        label_45 = new QLabel(tab);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(30, 170, 111, 21));
        label_employees = new QLabel(tab);
        label_employees->setObjectName("label_employees");
        label_employees->setGeometry(QRect(150, 170, 21, 16));
        label_46 = new QLabel(tab);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(30, 210, 111, 16));
        label_etudiants = new QLabel(tab);
        label_etudiants->setObjectName("label_etudiants");
        label_etudiants->setGeometry(QRect(150, 210, 21, 16));
        line_3 = new QFrame(tab);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(400, -10, 16, 341));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        frame = new QFrame(tab);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(260, 10, 281, 41));
        frame->setStyleSheet(QString::fromUtf8("border-left:none;\n"
"border-right:none;\n"
"border-radius:1px;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_no_photo = new QLabel(tab);
        label_no_photo->setObjectName("label_no_photo");
        label_no_photo->setGeometry(QRect(600, 75, 21, 21));
        label_47 = new QLabel(tab);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(440, 70, 161, 31));
        label_23 = new QLabel(tab);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(510, 270, 71, 21));
        label_24 = new QLabel(tab);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(610, 270, 61, 21));
        label_25 = new QLabel(tab);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(700, 270, 121, 21));
        label_26 = new QLabel(tab);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(930, 270, 49, 21));
        Oo = new QLabel(tab);
        Oo->setObjectName("Oo");
        Oo->setGeometry(QRect(530, 300, 31, 21));
        Or = new QLabel(tab);
        Or->setObjectName("Or");
        Or->setGeometry(QRect(630, 300, 31, 21));
        Tt = new QLabel(tab);
        Tt->setObjectName("Tt");
        Tt->setGeometry(QRect(740, 300, 31, 21));
        Au = new QLabel(tab);
        Au->setObjectName("Au");
        Au->setGeometry(QRect(930, 300, 31, 21));
        Poo = new QLabel(tab);
        Poo->setObjectName("Poo");
        Poo->setGeometry(QRect(510, 209, 71, 51));
        Por = new QLabel(tab);
        Por->setObjectName("Por");
        Por->setGeometry(QRect(600, 220, 71, 41));
        Ptt = new QLabel(tab);
        Ptt->setObjectName("Ptt");
        Ptt->setGeometry(QRect(720, 220, 71, 41));
        idLineEdit = new QLineEdit(tab);
        idLineEdit->setObjectName("idLineEdit");
        idLineEdit->setGeometry(QRect(470, 161, 161, 31));
        speakButton = new QPushButton(tab);
        speakButton->setObjectName("speakButton");
        speakButton->setGeometry(QRect(660, 160, 75, 31));
        speechLabel = new QLabel(tab);
        speechLabel->setObjectName("speechLabel");
        speechLabel->setGeometry(QRect(680, 50, 351, 91));
        Gestion->addTab(tab, QString());
        line_3->raise();
        frame->raise();
        label_20->raise();
        label_total->raise();
        label_21->raise();
        label_men->raise();
        label_men_percent->raise();
        label_women_percent->raise();
        label_42->raise();
        label_women->raise();
        label_43->raise();
        label_admin->raise();
        label_44->raise();
        label_transporteurs->raise();
        label_45->raise();
        label_employees->raise();
        label_46->raise();
        label_etudiants->raise();
        label_no_photo->raise();
        label_47->raise();
        label_23->raise();
        label_24->raise();
        label_25->raise();
        label_26->raise();
        Oo->raise();
        Or->raise();
        Tt->raise();
        Au->raise();
        Poo->raise();
        Por->raise();
        Ptt->raise();
        idLineEdit->raise();
        speakButton->raise();
        speechLabel->raise();
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 311, 51));
        label->setStyleSheet(QString::fromUtf8("font-size:30px;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(980, 30, 75, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid gray;\n"
"background:#f1f1f1;"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        Gestion->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        Gender->setItemText(0, QCoreApplication::translate("MainWindow", "Homme", nullptr));
        Gender->setItemText(1, QCoreApplication::translate("MainWindow", "Femme", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "Gender", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Date de Naissance", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Mot De Passe", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Photo ", nullptr));
        upload_btn->setText(QCoreApplication::translate("MainWindow", "Upload", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        Poste->setItemText(0, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        Poste->setItemText(1, QCoreApplication::translate("MainWindow", "Employee", nullptr));
        Poste->setItemText(2, QCoreApplication::translate("MainWindow", "Transporteur", nullptr));
        Poste->setItemText(3, QCoreApplication::translate("MainWindow", "Etudiant", nullptr));

        Ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        Reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Etablissement", nullptr));
        Gestion->setTabText(Gestion->indexOf(Ajouter_1), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        Actualiser->setText(QCoreApplication::translate("MainWindow", "Actualiser", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Select ...", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "ID", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Email", nullptr));

        search_btn->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        trier->setText(QCoreApplication::translate("MainWindow", "Trier ", nullptr));
        delete_btn->setText(QCoreApplication::translate("MainWindow", "SELECT AND DELETE", nullptr));
        Gestion->setTabText(Gestion->indexOf(Read), QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        Posteu->setItemText(0, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        Posteu->setItemText(1, QCoreApplication::translate("MainWindow", "Employee", nullptr));
        Posteu->setItemText(2, QCoreApplication::translate("MainWindow", "Transporteur", nullptr));
        Posteu->setItemText(3, QCoreApplication::translate("MainWindow", "Etudiant", nullptr));

        Genderu->setItemText(0, QCoreApplication::translate("MainWindow", "Homme", nullptr));
        Genderu->setItemText(1, QCoreApplication::translate("MainWindow", "Femme", nullptr));

        label_11->setText(QCoreApplication::translate("MainWindow", "Date de Naissance", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Gender", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Mot De Passe", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Select ...", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "ID", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Email", nullptr));

        update_btn->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        updated_btn->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Photo", nullptr));
        select->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        Gestion->setTabText(Gestion->indexOf(Modifier), QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "TOTAL USERS:", nullptr));
        label_total->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "N\302\260 Homme:", nullptr));
        label_men->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_men_percent->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_women_percent->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "N\302\260 Femme:", nullptr));
        label_women->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "N\302\260 Admins:", nullptr));
        label_admin->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "N\302\260 Transporteur:", nullptr));
        label_transporteurs->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "N\302\260 Employee:", nullptr));
        label_employees->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "N\302\260 Etudiant:", nullptr));
        label_etudiants->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_no_photo->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "Utilisateur no photo:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Ooredoo", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Orange", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Tunisie Telecom", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Autre", nullptr));
        Oo->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        Or->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        Tt->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        Au->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        Poo->setText(QString());
        Por->setText(QString());
        Ptt->setText(QString());
        speakButton->setText(QCoreApplication::translate("MainWindow", "speak", nullptr));
        speechLabel->setText(QCoreApplication::translate("MainWindow", "---", nullptr));
        Gestion->setTabText(Gestion->indexOf(tab), QCoreApplication::translate("MainWindow", "Stat", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Gestion Employee", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
