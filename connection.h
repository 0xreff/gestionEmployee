#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class connection
{
public:
    connection();
    bool createconnect();
    static QSqlDatabase getConnection();
};

#endif // CONNECTION_H
