#ifndef CONNECTION_H
#define CONNECTION_H
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connection
{
public:
    connection();
    bool createconnect();
};

#endif // CONNECTION_H
