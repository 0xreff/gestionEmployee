#include "Speech.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
Speech::Speech(QSqlDatabase db) : db(db) {}

QString Speech::generateSpeech(const QString &rfidValue) {

    QSqlQuery query(db);
    query.prepare("SELECT nom, prenom, gender, id_etab , rfid_emp FROM employees WHERE rfid_emp = :rfidValue");
    query.bindValue(":rfid_emp", rfidValue);

    if (!query.exec() || !query.next()) {
        return "Error: Employee not found.";
    }

    QString nom = query.value("nom").toString();
    QString prenom = query.value("prenom").toString();
    QString gender = query.value("gender").toString();
    int idEtab = query.value("id_etab").toInt();
    QString etabNom;
    QSqlQuery etabQuery(db);
    etabQuery.prepare("SELECT nom FROM etablissement WHERE id = :id_etab");
    etabQuery.bindValue(":id_etab", idEtab);

    if (etabQuery.exec() && etabQuery.next()) {
        etabNom = etabQuery.value("nom").toString();
    } else {
        etabNom = "an unknown establishment";
    }
    QString message;
    if (gender == "Femme") {
        message = "Madame, " + prenom + " " + nom + ". Affected to " + etabNom;
    } else if (gender == "Homme") {
        message = "Monsieur, " + prenom + " " + nom + ". Affected to " + etabNom;
    } else {
        message = prenom + " " + nom + ". Affected to " + etabNom;
    }

    return message;
}
