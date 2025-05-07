
#include <QMessageBox>
#include "connection.h"
#include "login.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection c;
    bool test = c.createconnect();
    Login * w = new Login;
    if (test) {
        w->show();
        QMessageBox::information(nullptr, "Connection", "Database connected successfully.");


    } else {
        QMessageBox::critical(nullptr, "Connection", "Database connection failed.");
    }

    return a.exec();
}
