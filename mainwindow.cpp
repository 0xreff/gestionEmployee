#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include "Speech.h"
#include "QAudioOutput"
#include <QSerialPortInfo>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayEtablissements();
    updateStatistics();
    connect(ui->Actualiser, &QPushButton::clicked, this, &MainWindow::on_Actualiser_clicked);
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_tableView_doubleClicked(QModelIndex)));
    connect(ui->update_btn, &QPushButton::clicked, this, &MainWindow::on_update_btn_clicked);
    connect(ui->updated_btn, &QPushButton::clicked, this, &MainWindow::on_updated_btn_clicked);
    connect(ui->upload_btn, &QPushButton::clicked, this, &MainWindow::on_upload_btn_clicked);
    connect(ui->delete_btn, &QPushButton::clicked, this, &MainWindow::on_delete_btn_clicked);
    isAscending = true;
    serial = new QSerialPort(this);
    serial->setPortName("COM4");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (!serial->open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open serial port:" << serial->errorString();
    } else {
        qDebug() << "Serial port opened successfully.";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayEtablissements()
{
    QString errorMessage;
    Employee emp;
    QMap<int, QString> etablissements = emp.fetchEtablissements(errorMessage);  // Fetch établissements

    if (!etablissements.isEmpty()) {
        ui->etab->clear();
        QMapIterator<int, QString> i(etablissements);
        while (i.hasNext()) {
            i.next();
            ui->etab->addItem(i.value(), i.key());
        }
    } else {
        QMessageBox::critical(this, "Error", errorMessage);
    }
}






void MainWindow::on_Ajouter_clicked()
{
    QString nom = ui->Nom->text();
    QString prenom = ui->Prenom->text();
    QString tel = ui->Tel->text();
    QString email = ui->Email->text();
    QString password = ui->Pass->text();
    QString gender = ui->Gender->currentText();
    QString poste = ui->Poste->currentText();
    QDate dob = ui->Dob->date();
    int id_etab = ui->etab->currentData().toInt();

    // Basic input validations as before...
    if (nom.isEmpty() || prenom.isEmpty() || tel.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all required fields.");
        return;
    }

    QRegularExpression telRegex("^\\d{8}$");
    if (!telRegex.match(tel).hasMatch()) {
        QMessageBox::critical(this, "Invalid Input", "Phone must contain exactly 8 digits.");
        return;
    }

    QRegularExpression emailRegex("^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@[a-zA-Z0-9-]+(?:\\.[a-zA-Z0-9-]+)*$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::critical(this, "Invalid Input", "Invalid email address.");
        return;
    }

    QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z]).{6,}$");
    if (!passwordRegex.match(password).hasMatch()) {
        QMessageBox::critical(this, "Invalid Input", "Password must have uppercase and lowercase letters and be at least 6 characters.");
        return;
    }

    if (ui->etab->currentIndex() == -1) {
        QMessageBox::warning(this, "Input Error", "Please select an établissement.");
        return;
    }

    QDate currentDate = QDate::currentDate();
    int age = currentDate.year() - dob.year();
    if (currentDate.month() < dob.month() || (currentDate.month() == dob.month() && currentDate.day() < dob.day()))
        age--;
    if (age < 16 || age > 100) {
        QMessageBox::critical(this, "Invalid Age", "Age must be between 16 and 100.");
        return;
    }

    // Photo
    QString imagePath = ui->Photo->text();
    QFile imageFile(imagePath);
    QByteArray photoData;
    if (imageFile.open(QIODevice::ReadOnly)) {
        photoData = imageFile.readAll();
    }

    Employee emp(nom, prenom, photoData, tel, gender, email, password, dob, poste, id_etab);
    QString error;
    if (emp.save(error)) {
        QMessageBox::information(this, "Success", "Employee created successfully.");
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to create employee: " + error);
    }
}

void MainWindow::on_Actualiser_clicked()
{
    updateStatistics();
    if (employeeModel) {
        delete employeeModel;
        employeeModel = nullptr;
    }

    employeeModel = Employee::displayEmployees(this);
    if (employeeModel != nullptr) {
        ui->tableView->setModel(employeeModel);
        ui->tableView->resizeColumnsToContents();
    } else {
        QMessageBox::critical(this, "Error", "Failed to retrieve employee data.");
    }
}


void MainWindow::on_Reset_clicked()
{
    ui->Nom->clear();
    ui->Prenom->clear();
    ui->Tel->clear();
    ui->Email->clear();
    ui->Pass->clear();
    ui->Photo->clear();
    ui->Gender->setCurrentIndex(0);
    ui->Poste->setCurrentIndex(0);
    ui->etab->setCurrentIndex(0);
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    // Retrieve the employee ID from the clicked row (assumed to be in the first column)
    int employeeId = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toInt();

    // Debug: Check the employee ID
    qDebug() << "Employee ID:" << employeeId;

    // Query to fetch the photo and the employee's name based on employee ID
    QSqlQuery query;
    query.prepare("SELECT NOM, PRENOM, PHOTO FROM EMPLOYEES WHERE ID = :id");
    query.bindValue(":id", employeeId);

    if (query.exec() && query.next()) {
        QByteArray photoData = query.value(2).toByteArray();
        QString nom = query.value(0).toString();
        QString prenom = query.value(1).toString();

        qDebug() << "Photo data size:" << photoData.size();

        // Combine first and last names to create a full name
        QString fullName = nom + " " + prenom;

        QImage img;
        img.loadFromData(photoData);  // Convert the BLOB data to QImage

        if (!img.isNull()) {
            // Check if the dialog is already open
            static QDialog *imageDialog = nullptr;  // Declare a static pointer to track the open dialog

            if (imageDialog) {
                imageDialog->close();  // Close the previous dialog if it's still open
                delete imageDialog;    // Delete it to free memory
            }

            // Create and show the new dialog
            imageDialog = new QDialog(this);
            QLabel *imageLabel = new QLabel(imageDialog);
            imageLabel->setPixmap(QPixmap::fromImage(img).scaled(200, 200, Qt::KeepAspectRatio));
            imageLabel->setAlignment(Qt::AlignCenter);

            // Set the dialog's layout and size
            QVBoxLayout *layout = new QVBoxLayout;
            layout->addWidget(imageLabel);
            imageDialog->setLayout(layout);

            // Set the title of the dialog dynamically to include the employee's full name
            imageDialog->setWindowTitle("Photo of " + fullName);

            // Show the dialog
            imageDialog->exec();
        } else {
            QMessageBox::warning(this, "Error", "No photo available for this employee.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Failed to fetch photo data.");
    }
}

void MainWindow::on_search_btn_clicked()
{
    QString searchText = ui->search_line->text();

    // Get the selected search criteria from the QComboBox
    QString searchCriteria = ui->comboBox->currentText();

    // If search text is empty, just show all employees
    if (searchText.isEmpty()) {
        on_Actualiser_clicked();  // Refresh to show all employees
        return;
    }

    // Call the search method from Employee class
    QSqlQueryModel *model = Employee::search(searchText, searchCriteria);

    if (model != nullptr) {
        ui->tableView->setModel(model);  // Set the model to the QTableView
    } else {
        QMessageBox::critical(this, "Error", "Failed to execute search query.");
    }
}


void MainWindow::on_update_btn_clicked()
{
    QString searchText = ui->searchLineEdit->text();
    QString searchBy = ui->searchComboBox->currentText();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a search term.");
        return;
    }
    Employee emp;
    QSqlQuery query = emp.fetchEmployeeByIdOrEmail(searchBy, searchText);

    if (query.next()) {
        ui->Nomu->setText(query.value("NOM").toString());
        ui->Prenomu->setText(query.value("PRENOM").toString());
        ui->Telu->setText(query.value("TEL").toString());
        ui->Emailu->setText(query.value("EMAIL").toString());
        ui->Passu->setText(query.value("PASSWORD").toString());
        ui->Genderu->setCurrentText(query.value("GENDER").toString());
        ui->Dobu->setDate(query.value("DOB").toDate());
        ui->Posteu->setCurrentText(query.value("POSTE").toString());

        employeeId = query.value("ID").toInt();
        ui->Modifier->show();
    } else {
        QMessageBox::warning(this, "Not Found", "No employee found with the provided ID or Email.");
    }
}

void MainWindow::on_updated_btn_clicked()
{
    QString nom = ui->Nomu->text();
    QString prenom = ui->Prenomu->text();
    QString tel = ui->Telu->text();
    QString email = ui->Emailu->text();
    QString password = ui->Passu->text();
    QString gender = ui->Genderu->currentText();
    QDate dob = ui->Dobu->date();
    QString poste = ui->Posteu->currentText();
    QString photo = ui->Photou->text();

    // Validate input fields
    if (nom.isEmpty() || prenom.isEmpty() || tel.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all required fields.");
        return;
    }

    QRegularExpression telRegex("^\\d{8}$");
    QRegularExpressionMatch telMatch = telRegex.match(tel);
    if (!telMatch.hasMatch()) {
        QMessageBox::critical(this, "Invalid Input", "Telephone must contain exactly 8 digits.");
        return;
    }

    QRegularExpression emailRegex("^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@[a-zA-Z0-9-]+(?:\\.[a-zA-Z0-9-]+)*$");
    QRegularExpressionMatch emailMatch = emailRegex.match(email);
    if (!emailMatch.hasMatch()) {
        QMessageBox::critical(this, "Invalid Input", "The email address is not valid.");
        return;
    }

    QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z]).{6,}$");
    QRegularExpressionMatch passwordMatch = passwordRegex.match(password);
    if (!passwordMatch.hasMatch()) {
        QMessageBox::critical(this, "Invalid Input", "Password must contain at least 6 characters with both uppercase and lowercase letters.");
        return;
    }

    QDate currentDate = QDate::currentDate();
    int age = currentDate.year() - dob.year();
    if (currentDate.month() < dob.month() || (currentDate.month() == dob.month() && currentDate.day() < dob.day())) {
        age--;
    }

    if (age < 18) {
        QMessageBox::critical(this, "Invalid Input", "The person must be at least 18 years old.");
        return;
    }

    if (age > 100) {
        QMessageBox::critical(this, "Invalid Input", "The person must be no older than 100 years.");
        return;
    }

    if (employeeId == -1) {
        QMessageBox::critical(this, "Error", "No employee selected for update.");
        return;
    }

    QByteArray photoData;
    bool updatePhoto = false;

    if (!photo.isEmpty()) {
        QFile photoFile(photo);
        if (photoFile.open(QIODevice::ReadOnly)) {
            photoData = photoFile.readAll();
            updatePhoto = true;
        } else {
            QMessageBox::warning(this, "Error", "Failed to load photo. Check the file path.");
            return;
        }
    } else {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Remove Photo?",
                                                                  "Do you want to remove the existing photo?",
                                                                  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            updatePhoto = true;
        }
    }

    QString errorMessage;
    Employee emp;
    qDebug() << "Updating employee with ID:" << employeeId;
    bool success = emp.modifyEmployee(employeeId, nom, prenom, tel, email, password,
                                      gender, dob, poste, photoData, updatePhoto, errorMessage);

    if (success) {
        QMessageBox::information(this, "Success", "Employee data updated successfully.");

        // Clear UI fields
        ui->Nomu->clear();
        ui->Prenomu->clear();
        ui->Telu->clear();
        ui->Emailu->clear();
        ui->Passu->clear();
        ui->Photou->clear();
        ui->Genderu->setCurrentIndex(0);
        ui->Dobu->setDate(QDate::currentDate());
        ui->Posteu->setCurrentIndex(0);

        employeeId = -1; // Reset after update

        // Refresh table
        QSqlQueryModel *newModel = Employee::displayEmployees(this);
        if (newModel) {
            ui->tableView->setModel(newModel);
            ui->tableView->resizeColumnsToContents();
        } else {
            QMessageBox::warning(this, "Warning", "Could not refresh the employee table.");
        }

    } else {
        QMessageBox::critical(this, "Error", "Failed to update employee: " + errorMessage);
    }
}



void MainWindow::on_trier_clicked()
{
    QString sortBy = ui->comboBox->currentText();
    QString dbColumn;

    if (sortBy == "ID") dbColumn = "ID";
    else if (sortBy == "Nom") dbColumn = "NOM";
    else if (sortBy == "Prenom") dbColumn = "PRENOM";
    else if (sortBy == "Telephone") dbColumn = "TEL";
    else if (sortBy == "Email") dbColumn = "EMAIL";
    else return;

    Employee emp;
    QSqlQueryModel* model = emp.sortEmployees(dbColumn, isAscending);
    if (model) {
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        isAscending = !isAscending;
    } else {
        QMessageBox::critical(this, "Error", "Failed to sort employees.");
    }
}


void MainWindow::on_upload_btn_clicked()
{
    // Open a file dialog to allow the user to choose a photo
    QString filePath = QFileDialog::getOpenFileName(this, tr("Select Photo"), "", tr("Images (*.jpg *.jpeg)"));

    // Check if the user selected a file (filePath is not empty)
    if (!filePath.isEmpty()) {
        // Check if the file has a .jpg or .jpeg extension
        QFileInfo fileInfo(filePath);
        QString extension = fileInfo.suffix().toLower(); // Get the file extension in lowercase

        // If the file is not .jpg or .jpeg, show an error message
        if (extension != "jpg" && extension != "jpeg") {
            QMessageBox::warning(this, "Invalid File Type", "Please select a .jpg or .jpeg image.");
            return; // Return early without updating the QLineEdit
        }

        // Set the file path to the QLineEdit (Photo) if valid
        ui->Photo->setText(filePath);
    }
}



void MainWindow::on_select_clicked()
{

        // Open a file dialog to allow the user to choose a photo
        QString filePath = QFileDialog::getOpenFileName(this, tr("Select Photo"), "", tr("Images (*.jpg *.jpeg)"));

        // Check if the user selected a file (filePath is not empty)
        if (!filePath.isEmpty()) {
            // Check if the file has a .jpg or .jpeg extension
            QFileInfo fileInfo(filePath);
            QString extension = fileInfo.suffix().toLower(); // Get the file extension in lowercase

            // If the file is not .jpg or .jpeg, show an error message
            if (extension != "jpg" && extension != "jpeg") {
                QMessageBox::warning(this, "Invalid File Type", "Please select a .jpg or .jpeg image.");
                return; // Return early without updating the QLineEdit
            }

            // Set the file path to the QLineEdit (Photo) if valid
            ui->Photou->setText(filePath);
        }

}

void MainWindow::on_delete_btn_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "No selection", "Please select a row to delete.");
        return;
    }

    int row = selectedIndexes.first().row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());

    // Store ID before deletion
    int id = model->data(model->index(row, 0)).toInt();

    // Confirm deletion
    QString nom = model->data(model->index(row, 1)).toString();
    QString prenom = model->data(model->index(row, 2)).toString();

    QString message = QString("Delete employee?\n\nNom: %1\nPrenom: %2").arg(nom, prenom);
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Deletion", message);

    if (reply == QMessageBox::Yes) {
        QString errorMessage;
        Employee e;

        if (e.deleteEmployee(id, errorMessage)) {
            QMessageBox::information(this, "Success", "Employee deleted.");

            QSqlQueryModel *newModel = Employee::displayEmployees(this);
            if (newModel) {
                ui->tableView->setModel(newModel);
                ui->tableView->resizeColumnsToContents();
            }
        } else {
            QMessageBox::critical(this, "Error", errorMessage);
        }
    }
}



/*int MainWindow::getCountFromQuery(const QString &queryStr)
{
    QSqlQuery query;
    if (query.exec(queryStr)) {
        if (query.next()) {
            return query.value(0).toInt();
        }
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
    }
    return 0;
}*/

void MainWindow::updateStatistics()
{
    QSize targetSize(50, 50); // Adjust to your preferred size

    QPixmap pix1("C:/Users/Asser/Desktop/examHub/resource/ooredoo.png");
    QPixmap pix2("C:/Users/Asser/Desktop/examHub/resource/orange.png");
    QPixmap pix3("C:/Users/Asser/Desktop/examHub/resource/tt.png");
    ui->Poo->setPixmap(pix1.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->Por->setPixmap(pix2.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->Ptt->setPixmap(pix3.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->label_total->setText(QString::number(Employee::countTotalEmployees()));
    ui->label_men->setText(QString::number(Employee::countByGender("Homme")));
    ui->label_women->setText(QString::number(Employee::countByGender("Femme")));
    ui->label_admin->setText(QString::number(Employee::countByPoste("Admin")));
    ui->label_transporteurs->setText(QString::number(Employee::countByPoste("Transporteur")));
    ui->label_employees->setText(QString::number(Employee::countByPoste("Employee")));
    ui->label_etudiants->setText(QString::number(Employee::countByPoste("Etudiant")));
    ui->label_no_photo->setText(QString::number(Employee::countNoPhoto()));
    ui->Oo->setText(QString::number(Employee::countPhonePrefix("2")));
    ui->Or->setText(QString::number(Employee::countPhonePrefix("5")));
    ui->Tt->setText(QString::number(Employee::countPhonePrefix("9")));
    ui->Au->setText(QString::number(Employee::countPhoneOtherPrefixes()));
    int total = Employee::countTotalEmployees();
    int men = Employee::countByGender("Homme");
    int women = Employee::countByGender("Femme");

    double menPercent = 0.0, womenPercent = 0.0;
    if (total > 0) {
        menPercent = (men * 100.0) / total;
        womenPercent = (women * 100.0) / total;
    }

    ui->label_men_percent->setText(QString::number(menPercent, 'f', 1) + "%");
    ui->label_women_percent->setText(QString::number(womenPercent, 'f', 1) + "%");
}



void MainWindow::exportToPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as PDF", "", "PDF Files (*.pdf)");

    if (fileName.isEmpty())
        return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString html;

    html += "<table width='110%' cellspacing='0' cellpadding='2'>";
    html += "<thead><tr>";
    for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
        html += "<th border-style='dotted'>" + ui->tableView->model()->headerData(col, Qt::Horizontal).toString() + "</th>";
    }
    html += "</tr></thead><tbody>";

    for (int row = 0; row < ui->tableView->model()->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
            html += "<td border-style='dotted'>" + ui->tableView->model()->index(row, col).data().toString() + "</td>";
        }
        html += "</tr>";
    }

    html += "</tbody></table>";

    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Export Successful", "Data successfully exported to PDF.");
}


void MainWindow::exportToExcel()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as Excel", "", "Excel Files (*.csv)");

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open file for writing.");
        return;
    }

    QTextStream out(&file);

    // Write headers
    for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
        out << ui->tableView->model()->headerData(col, Qt::Horizontal).toString();
        if (col < ui->tableView->model()->columnCount() - 1)
            out << ",";
    }
    out << "\n";

    // Write data
    for (int row = 0; row < ui->tableView->model()->rowCount(); ++row) {
        for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
            out << ui->tableView->model()->index(row, col).data().toString();
            if (col < ui->tableView->model()->columnCount() - 1)
                out << ",";
        }
        out << "\n";
    }

    file.close();
    QMessageBox::information(this, "Export Successful", "Data successfully exported to Excel (CSV).");
}

void MainWindow::on_pushButton_clicked()
{
    QStringList options = { "PDF (*.pdf)", "Excel (*.csv)" };
    bool ok;

    // Show the dialog to choose the format
    QString choice = QInputDialog::getItem(this, "Export Format", "Choose export format:", options, 0, false, &ok);

    if (ok && !choice.isEmpty()) {
        // Based on the choice, call the corresponding export function
        if (choice == "PDF (*.pdf)") {
            exportToPDF();
        } else if (choice == "Excel (*.csv)") {
            exportToExcel();
        }
    }
}


void MainWindow::on_speakButton_clicked()
{
    QString message = ui->idLineEdit->text(); // or however you get input

}






