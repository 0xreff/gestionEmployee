#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QDate>
#include <QByteArray>
#include <QSqlQueryModel>
#include <QMessageBox>
class Employee
{
public:
    Employee(const QString &nom, const QString &prenom, const QByteArray &photo,
             const QString &tel, const QString &gender, const QString &email,
             const QString &password, const QDate &dob, const QString &poste, int id_etab);
    Employee();
    bool save(QString &errorMessage);
    static QMap<int, QString> fetchEtablissements(QString &errorMessage);
    static QSqlQueryModel* displayEmployees(QObject* parent);
    static QSqlQueryModel* search(const QString& searchText, const QString& searchCriteria);
    static bool deleteEmployee(int id, QString &errorMessage);
    static QSqlQuery fetchEmployeeByIdOrEmail(const QString& searchBy, const QString& searchText);
    static bool modifyEmployee(int id, const QString& nom, const QString& prenom, const QString& tel,
                               const QString& email, const QString& password, const QString& gender,
                               const QDate& dob, const QString& poste, const QByteArray& photoData,
                               bool updatePhoto, QString& errorMessage);
    static QSqlQueryModel* sortEmployees(const QString& sortBy, bool ascending);
    static int getCountFromQuery(const QString &queryStr);
    static int countTotalEmployees();
    static int countByGender(const QString &gender);
    static int countByPoste(const QString &poste);
    static int countNoPhoto();
    static int countPhonePrefix(const QString &prefix);
    static int countPhoneOtherPrefixes();
    static bool validateCredentials(const QString &email, const QString &password);
    bool emailExists(const QString& email);

private:
    QString nom;
    QString prenom;
    QByteArray photo;
    QString tel;
    QString gender;
    QString email;
    QString password;
    QDate dob;
    QString poste;
    int id_etab;
};

#endif // EMPLOYEE_H
