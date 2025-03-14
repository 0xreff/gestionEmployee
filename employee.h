#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QByteArray>
#include <QDate>

class Employee {
public:
    // Constructor
    Employee();
    Employee(int id, const QString &nom, const QString &prenom, const QByteArray &photoPortrait,
             const QString &tel, const QString &gender, const QString &email, const QString &password,
             const QDate &dob, const QString &poste);

    // Getters
    int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    QByteArray getPhotoPortrait() const;
    QString getTel() const;
    QString getGender() const;
    QString getEmail() const;
    QString getPassword() const;
    QDate getDob() const;
    QString getPoste() const;

    // Setters
    void setId(int id);
    void setNom(const QString &nom);
    void setPrenom(const QString &prenom);
    void setPhotoPortrait(const QByteArray &photoPortrait);
    void setTel(const QString &tel);
    void setGender(const QString &gender);
    void setEmail(const QString &email);
    void setPassword(const QString &password);
    void setDob(const QDate &dob);
    void setPoste(const QString &poste);

private:
    int m_id;
    QString m_nom;
    QString m_prenom;
    QByteArray m_photoPortrait; // Image data in binary
    QString m_tel;
    QString m_gender;
    QString m_email;
    QString m_password;
    QDate m_dob;
    QString m_poste;
};

#endif // EMPLOYEE_H
