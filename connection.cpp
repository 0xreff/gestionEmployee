#include "connection.h"

connection::connection() {}

bool connection::createconnect()
{
    qDebug() << "Attempting database connection...";
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("examHub");
    db.setUserName("sensei");
    db.setPassword("sensei");

    bool success = db.open();
    qDebug() << "Connection result:" << success << ", Error:" << db.lastError().text();
    return success;
}

QSqlDatabase connection::getConnection()
{
    if (!QSqlDatabase::contains()) {
        connection().createconnect(); // ensure connection is created
    }
    return QSqlDatabase::database();
}
