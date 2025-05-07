#ifndef SPEECH_H
#define SPEECH_H

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class Speech {
public:
    Speech(QSqlDatabase db);
    QString generateSpeech(const QString &idInput);

private:
    QSqlDatabase db;
};


#endif // SPEECH_H
