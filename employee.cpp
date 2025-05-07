#include "employee.h"
#include "connection.h"
#include <QSqlQuery>
#include <QSqlError>
Employee::Employee(){};
Employee::Employee(const QString &nom, const QString &prenom, const QByteArray &photo,
                   const QString &tel, const QString &gender, const QString &email,
                   const QString &password, const QDate &dob, const QString &poste, int id_etab)
    : nom(nom), prenom(prenom), photo(photo), tel(tel), gender(gender),
    email(email), password(password), dob(dob), poste(poste), id_etab(id_etab) {}

bool Employee::save(QString &errorMessage)
{
    QSqlQuery query;
    query.prepare("INSERT INTO employees (nom, prenom, photo, tel, gender, email, password, dob, poste, id_etab) "
                  "VALUES (:nom, :prenom, :photo, :tel, :gender, :email, :password, :dob, :poste, :id_etab)");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":photo", photo);
    query.bindValue(":tel", tel);
    query.bindValue(":gender", gender);
    query.bindValue(":email", email);
    query.bindValue(":password", password);
    query.bindValue(":dob", dob);
    query.bindValue(":poste", poste);
    query.bindValue(":id_etab", id_etab);

    if (!query.exec()) {
        errorMessage = query.lastError().text();
        return false;
    }

    return true;
}

/*EEEEEEEEETTTTTTTTTTAAAAAAAAABBBBBBBLLLLLLLLLIIIIIIIIIIISSSSSSSSEEEEEEMMMMMMMMMEEEEEEENNNNNNNNTTTTTTT*/
QMap<int, QString> Employee::fetchEtablissements(QString &errorMessage)
{
    QMap<int, QString> etablissements;

    // Call the connection method to ensure the database is connected
   connection conn;  // Make sure you instantiate the connection object
    if (!conn.createconnect()) {
        errorMessage = "Failed to establish a connection to the database.";
        return etablissements;
    }

    // Create a query to fetch the list of établissements
    QSqlQuery etabQuery;
    etabQuery.prepare("SELECT id, adresse FROM ETABLISSEMENT");

    if (!etabQuery.exec()) {
        errorMessage = "Failed to retrieve établissements: " + etabQuery.lastError().text();
        return etablissements;
    }

    // Process and store the results
    while (etabQuery.next()) {
        int id = etabQuery.value("id").toInt();
        QString adresse = etabQuery.value("adresse").toString();
        etablissements[id] = adresse;  // Store ID as key and name as value
    }

    return etablissements;
}

QSqlQueryModel* Employee::displayEmployees(QObject* parent = nullptr)
{
    /*connection c;
    if (!c.createconnect()) {
        qDebug() << "Database connection failed.";
        return nullptr;
    }*/

    QSqlQueryModel *model = new QSqlQueryModel(parent);
    QSqlQuery query;

    if (!query.exec("SELECT ID, NOM, PRENOM, TEL, GENDER, EMAIL, PASSWORD, DOB, POSTE, ID_ETAB FROM EMPLOYEES")) {
        qDebug() << "Error displaying employees: " << query.lastError().text();
        return nullptr;
    }

    model->setQuery(query);
    return model;
}




QSqlQueryModel* Employee::search(const QString& searchText, const QString& searchCriteria)
{
    QSqlQueryModel *model = new QSqlQueryModel;

    QString column;
    if (searchCriteria == "ID") {
        column = "ID";
    } else if (searchCriteria == "Nom") {
        column = "NOM";
    } else if (searchCriteria == "Prenom") {
        column = "PRENOM";
    } else if (searchCriteria == "Email") {
        column = "EMAIL";
    } else if (searchCriteria == "Telephone") {
        column = "TEL";
    }

    QString queryStr = QString("SELECT ID, NOM, PRENOM, TEL, GENDER, EMAIL, PASSWORD, DOB, POSTE, ID_ETAB FROM EMPLOYEES WHERE %1 LIKE :searchText").arg(column);
    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":searchText", "%" + searchText + "%");

    if (!query.exec()) {
        qDebug() << "Error searching employees: " << query.lastError().text();
        return nullptr;
    }

    model->setQuery(query);
    return model;
}

bool Employee::deleteEmployee(int id, QString &errorMessage)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYEES WHERE ID = :id");

    // Bind the ID to the query
    query.bindValue(":id", id);

    // Execute the query to delete the employee
    if (query.exec()) {
        return true;
    } else {
        errorMessage = "Failed to delete employee: " + query.lastError().text();
        return false;
    }
}

QSqlQuery Employee::fetchEmployeeByIdOrEmail(const QString& searchBy, const QString& searchText)
{
    connection c;
    if (!c.createconnect()) {
        qDebug() << "Connection failed.";
        return QSqlQuery();  // Empty query
    }

    QSqlQuery query;
    if (searchBy == "ID") {
        query.prepare("SELECT * FROM employees WHERE ID = :searchText");
        query.bindValue(":searchText", searchText.toInt());
    } else if (searchBy == "Email") {
        query.prepare("SELECT * FROM employees WHERE EMAIL = :searchText");
        query.bindValue(":searchText", searchText);
    }

    if (!query.exec()) {
        qDebug() << "Query execution failed: " << query.lastError().text();
    }

    return query;
}


bool Employee::modifyEmployee(int id, const QString& nom, const QString& prenom, const QString& tel,
                              const QString& email, const QString& password, const QString& gender,
                              const QDate& dob, const QString& poste, const QByteArray& photoData,
                              bool updatePhoto, QString& errorMessage)
{
    QString queryString = "UPDATE employees SET NOM = :nom, PRENOM = :prenom, TEL = :tel, EMAIL = :email, "
                          "PASSWORD = :password, GENDER = :gender, DOB = :dob, POSTE = :poste";

    if (updatePhoto) {
        queryString += ", PHOTO = :photo";
    }

    queryString += " WHERE ID = :id";

    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", tel);
    query.bindValue(":email", email);
    query.bindValue(":password", password);
    query.bindValue(":gender", gender);
    query.bindValue(":dob", dob);
    query.bindValue(":poste", poste);
    query.bindValue(":id", id);

    if (updatePhoto) {
        query.bindValue(":photo", photoData.isEmpty() ? QVariant(QVariant::ByteArray) : photoData);
    }

    if (!query.exec()) {
        errorMessage = query.lastError().text();
        return false;
    }

    return true;
}


QSqlQueryModel* Employee::sortEmployees(const QString& sortBy, bool ascending)
{
    QString queryStr = "SELECT ID, NOM, PRENOM, TEL, EMAIL, PASSWORD, GENDER, DOB, POSTE FROM EMPLOYEES";

    // Validate and append ORDER BY
    QStringList validColumns = {"ID", "NOM", "PRENOM", "TEL", "EMAIL"};
    if (validColumns.contains(sortBy.toUpper())) {
        queryStr += " ORDER BY " + sortBy + (ascending ? " ASC" : " DESC");
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(queryStr);

    if (model->lastError().isValid()) {
        qDebug() << "Error sorting employees:" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}


int Employee::getCountFromQuery(const QString &queryStr)
{
    QSqlQuery query;
    if (query.exec(queryStr) && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}
int Employee::countTotalEmployees() {
    return getCountFromQuery("SELECT COUNT(*) FROM employees");
}

int Employee::countByGender(const QString &gender) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employees WHERE gender = :gender");
    query.bindValue(":gender", gender);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

int Employee::countByPoste(const QString &poste) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employees WHERE poste = :poste");
    query.bindValue(":poste", poste);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

int Employee::countNoPhoto() {
    return getCountFromQuery("SELECT COUNT(*) FROM employees WHERE photo IS NULL OR photo = ''");
}
int Employee::countPhonePrefix(const QString &prefix) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employees WHERE tel LIKE :prefix");
    query.bindValue(":prefix", prefix + "%");
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

int Employee::countPhoneOtherPrefixes() {
    QSqlQuery query;
    QString sql = R"(
        SELECT COUNT(*) FROM employees
        WHERE tel NOT LIKE '2%' AND tel NOT LIKE '5%' AND tel NOT LIKE '9%'
    )";
    if (query.exec(sql) && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

bool Employee::validateCredentials(const QString &email, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM employees WHERE EMAIL = :email AND PASSWORD = :password");
    query.bindValue(":email", email);
    query.bindValue(":password", password); // You can hash it here if needed

    if (query.exec()) {
        return query.next(); // true if found
    } else {
        qDebug() << "Login query failed:" << query.lastError().text();
        return false;
    }
}
bool Employee::emailExists(const QString& email) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employees WHERE email = :email");
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}
