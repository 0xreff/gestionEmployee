#include "employee.h"

// Default constructor
Employee::Employee() : m_id(0), m_nom(""), m_prenom(""), m_photoPortrait(QByteArray()), m_tel(""),
    m_gender(""), m_email(""), m_password(""), m_dob(QDate()), m_poste("") {}

// Parameterized constructor
Employee::Employee(int id, const QString &nom, const QString &prenom, const QByteArray &photoPortrait,
                   const QString &tel, const QString &gender, const QString &email, const QString &password,
                   const QDate &dob, const QString &poste)
    : m_id(id), m_nom(nom), m_prenom(prenom), m_photoPortrait(photoPortrait), m_tel(tel), m_gender(gender),
    m_email(email), m_password(password), m_dob(dob), m_poste(poste) {}

// Getter and Setter Methods

// ID
int Employee::getId() const {
    return m_id;
}

void Employee::setId(int id) {
    m_id = id;
}

// Nom
QString Employee::getNom() const {
    return m_nom;
}

void Employee::setNom(const QString &nom) {
    m_nom = nom;
}

// Prénom
QString Employee::getPrenom() const {
    return m_prenom;
}

void Employee::setPrenom(const QString &prenom) {
    m_prenom = prenom;
}

// Photo Portrait
QByteArray Employee::getPhotoPortrait() const {
    return m_photoPortrait;
}

void Employee::setPhotoPortrait(const QByteArray &photoPortrait) {
    m_photoPortrait = photoPortrait;
}

// Telephone
QString Employee::getTel() const {
    return m_tel;
}

void Employee::setTel(const QString &tel) {
    m_tel = tel;
}

// Gender
QString Employee::getGender() const {
    return m_gender;
}

void Employee::setGender(const QString &gender) {
    m_gender = gender;
}

// Email
QString Employee::getEmail() const {
    return m_email;
}

void Employee::setEmail(const QString &email) {
    m_email = email;
}

// Password
QString Employee::getPassword() const {
    return m_password;
}

void Employee::setPassword(const QString &password) {
    m_password = password;
}

// Date of Birth (Dob)
QDate Employee::getDob() const {
    return m_dob;
}

void Employee::setDob(const QDate &dob) {
    m_dob = dob;
}

// Poste
QString Employee::getPoste() const {
    return m_poste;
}

void Employee::setPoste(const QString &poste) {
    m_poste = poste;
}
