#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Actualiser, &QPushButton::clicked, this, &MainWindow::on_Actualiser_clicked);
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_tableView_doubleClicked(QModelIndex)));
    connect(ui->update_btn, &QPushButton::clicked, this, &MainWindow::on_update_btn_clicked);
    connect(ui->updated_btn, &QPushButton::clicked, this, &MainWindow::on_updated_btn_clicked);
    connect(ui->upload_btn, &QPushButton::clicked, this, &MainWindow::on_upload_btn_clicked);
    connect(ui->delete_btn, &QPushButton::clicked, this, &MainWindow::on_delete_btn_clicked);

    isAscending = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Ajouter_clicked()
{
        // Get data from the UI elements
        QString nom = ui->Nom->text();
        QString prenom = ui->Prenom->text();
        QString tel = ui->Tel->text();
        QString email = ui->Email->text();
        QString password = ui->Pass->text();
        QString gender = ui->Gender->currentText();
        QString poste = ui->Poste->currentText();
        QDate dob = ui->Dob->date();
        if (nom.isEmpty() || prenom.isEmpty() || tel.isEmpty() || email.isEmpty()) {
            QMessageBox::warning(this, "Input Error", "Please fill in all required fields.");
            return;
        }
        QRegularExpression telRegex("^\\d{8}$");
        QRegularExpressionMatch telMatch = telRegex.match(tel);
        if (!telMatch.hasMatch()) {
            QMessageBox::critical(this, "Invalid Input", "7atitlak +216 and must contain exactly 8 digits.");
            return;
        }

        // 2. Validate email - must contain @ and a valid domain
        QRegularExpression emailRegex("^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@[a-zA-Z0-9-]+(?:\\.[a-zA-Z0-9-]+)*$");
        QRegularExpressionMatch emailMatch = emailRegex.match(email);
        if (!emailMatch.hasMatch()) {
            QMessageBox::critical(this, "Invalid Input", "The email address is not valid.");
            return;
        }

        // 3. Validate password - must have at least 6 characters, with both uppercase and lowercase letters
        QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z]).{6,}$");
        QRegularExpressionMatch passwordMatch = passwordRegex.match(password);
        if (!passwordMatch.hasMatch()) {
            QMessageBox::critical(this, "Invalid Input", "verifiy Password Majuscile w Miniscule");
            return;
        }
        QDate currentDate = QDate::currentDate();

        int age = currentDate.year() - dob.year();

        if (currentDate.month() < dob.month() || (currentDate.month() == dob.month() && currentDate.day() < dob.day())) {
            age--;  // The person hasn't had their birthday yet this year, so subtract one year
        }

        if (age < 18) {
            QMessageBox::critical(this, "Invalid Input", "The person must be at least 18 years old.");
            return;
        }
        if (age > 100) {
            QMessageBox::critical(this, "Invalid Input", "Ohh ! \nis This person Died 🤨!\nPlease enter a valid Age.");
            return;
        }

        QString imagePath = ui->Photo->text();
        QFile imageFile(imagePath);
        QByteArray photoData;
        if (imageFile.open(QIODevice::ReadOnly)) {
            photoData = imageFile.readAll();
        }
//***********************************************************************************************************
        QSqlQuery query;
        query.prepare("INSERT INTO employees (nom, prenom, photo, tel, gender, email, password, dob, poste) "
                      "VALUES (:nom, :prenom, :photo, :tel, :gender, :email, :password, :dob, :poste)");

        // Bind values to the query
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":photo", photoData);  // Store the image as binary (BLOB)
        query.bindValue(":tel", tel);
        query.bindValue(":gender", gender);
        query.bindValue(":email", email);
        query.bindValue(":password", password);
        query.bindValue(":dob", dob);
        query.bindValue(":poste", poste);

        // Execute the query
        if (query.exec()) {
            QMessageBox::information(this, "Success", "Employee created successfully.");
        } else {
            QMessageBox::critical(this, "Error", "Failed to create employee: " + query.lastError().text());
        }


}

void MainWindow::displayEmployees()
{
    QSqlQuery query;
    query.prepare("SELECT ID, NOM, PRENOM, TEL, GENDER, EMAIL, PASSWORD, DOB, POSTE FROM EMPLOYEES");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to retrieve data: " + query.lastError().text());
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Prenom");
    model->setHeaderData(3, Qt::Horizontal, "Tel");
    model->setHeaderData(4, Qt::Horizontal, "Gender");
    model->setHeaderData(5, Qt::Horizontal, "Email");
    model->setHeaderData(6, Qt::Horizontal, "Password");
    model->setHeaderData(7, Qt::Horizontal, "Date of Birth");
    model->setHeaderData(8, Qt::Horizontal, "Poste");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}



void MainWindow::on_Reset_clicked()
{
    ui->Nom->clear();
    ui->Prenom->clear();
    ui->Tel->clear();
    ui->Email->clear();
    ui->Pass->clear();
    ui->Photo->clear();  // Reset photo QLineEdit
    ui->Gender->setCurrentIndex(0);  // Reset to the first item (if applicable)
    ui->Dob->setDate(QDate::currentDate());  // Reset to current date
    ui->Poste->setCurrentIndex(0);
}


void MainWindow::on_Actualiser_clicked()
{
displayEmployees();
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
        QByteArray photoData = query.value(2).toByteArray();  // Retrieve the photo data
        QString nom = query.value(0).toString();  // Retrieve the employee's last name
        QString prenom = query.value(1).toString();  // Retrieve the employee's first name

        // Debug: Check the size of the photo data
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
    // Get the search text from the line edit
    QString searchText = ui->search_line->text();

    // Get the selected search criteria from the combo box
    QString searchCriteria = ui->comboBox->currentText();

    // Determine the corresponding column for the search
    QString columnName;
    QString searchColumn;
    QString matchCondition;

    // Handle the case of each column:
    if (searchCriteria == "Nom") {
        columnName = "NOM";
        searchColumn = "LOWER(NOM)";
        matchCondition = "LIKE";
    } else if (searchCriteria == "Prenom") {
        columnName = "PRENOM";
        searchColumn = "LOWER(PRENOM)";
        matchCondition = "LIKE";
    } else if (searchCriteria == "Telephone") {
        columnName = "TEL";
        searchColumn = "TEL";
        matchCondition = "LIKE";  // Allow partial matches
    } else if (searchCriteria == "Email") {
        columnName = "EMAIL";
        searchColumn = "LOWER(EMAIL)";
        matchCondition = "LIKE";
    } else if (searchCriteria == "ID") {
        columnName = "ID";
        searchColumn = "ID";
        matchCondition = "=";  // Exact match for ID
    }

    // If the search text is empty, return all employees
    if (searchText.isEmpty()) {
        displayEmployees(); // Refresh to display all employees
        return;
    }

    // Convert the search text to lowercase for case-insensitive search (if it's not ID)
    if (searchCriteria != "ID") {
        searchText = searchText.toLower();  // Convert the search text to lowercase
    }

    // Prepare the query based on the search criteria and text
    QSqlQuery query;

    // If searching by ID, we use an exact match (`=`) instead of LIKE
    if (searchCriteria == "ID") {
        QString queryStr = "SELECT * FROM EMPLOYEES WHERE " + searchColumn + " = :searchText";
        query.prepare(queryStr);
        query.bindValue(":searchText", searchText.toInt());  // Bind as integer for exact match
        qDebug() << "Executing query for ID: " << queryStr;
    } else {
        QString queryStr = "SELECT * FROM EMPLOYEES WHERE " + searchColumn + " " + matchCondition + " :searchText";
        query.prepare(queryStr);
        query.bindValue(":searchText", "%" + searchText + "%");  // Use % for partial matches
        qDebug() << "Executing query: " << queryStr;
    }

    // Execute the query
    if (query.exec()) {
        // Create a model to display the results in the table view
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(query);

        // Set the model for the QTableView
        ui->tableView->setModel(model);
    } else {
        // If the query fails, show an error message
        QMessageBox::critical(this, "Error", "Failed to execute search query: " + query.lastError().text());
    }
}

void MainWindow::on_update_btn_clicked()
{
    // Handle the search as described earlier
    QString searchText = ui->searchLineEdit->text();
    QString searchBy = ui->searchComboBox->currentText();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a search term.");
        return;
    }

    QSqlQuery query;
    if (searchBy == "ID") {
        query.prepare("SELECT * FROM employees WHERE ID = :searchText");
        query.bindValue(":searchText", searchText.toInt());  // ID is assumed to be an integer
    } else if (searchBy == "Email") {
        query.prepare("SELECT * FROM employees WHERE EMAIL = :searchText");
        query.bindValue(":searchText", searchText);
    }

    if (query.exec()) {
        if (query.next()) {
            // Retrieve data and populate the fields
            ui->Nomu->setText(query.value("NOM").toString());
            ui->Prenomu->setText(query.value("PRENOM").toString());
            ui->Telu->setText(query.value("TEL").toString());
            ui->Emailu->setText(query.value("EMAIL").toString());
            ui->Passu->setText(query.value("PASSWORD").toString());
            ui->Genderu->setCurrentText(query.value("GENDER").toString());
            ui->Dobu->setDate(query.value("DOB").toDate());
            ui->Posteu->setCurrentText(query.value("POSTE").toString());

            // Store the employee ID to use in the update
            employeeId = query.value("ID").toInt(); // Store the ID for later use in update
            ui->Modifier->show();
        } else {
            QMessageBox::warning(this, "Not Found", "No employee found with the provided ID or Email.");
        }
    } else {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}



void MainWindow::on_updated_btn_clicked()
{
    // Retrieve updated data from the fields
    QString nom = ui->Nomu->text();
    QString prenom = ui->Prenomu->text();
    QString tel = ui->Telu->text();
    QString email = ui->Emailu->text();
    QString password = ui->Passu->text();
    QString gender = ui->Genderu->currentText();
    QDate dob = ui->Dobu->date();
    QString poste = ui->Posteu->currentText();
    QString photo = ui->Photou->text();  // Get the photo path from the QLineEdit

    // Validate input fields
    if (nom.isEmpty() || prenom.isEmpty() || tel.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all required fields.");
        return;
    }

    // Validate telephone number: must start with +216 and contain exactly 8 digits
    QRegularExpression telRegex("^\\+216\\d{8}$");
    QRegularExpressionMatch telMatch = telRegex.match(tel);
    if (!telMatch.hasMatch()) {
        QMessageBox::critical(this, "Invalid Input", "Telephone must start with +216 and contain exactly 8 digits.");
        return;
    }

    // Validate email: must be in a valid email format
    QRegularExpression emailRegex("^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@[a-zA-Z0-9-]+(?:\\.[a-zA-Z0-9-]+)*$");
    QRegularExpressionMatch emailMatch = emailRegex.match(email);
    if (!emailMatch.hasMatch()) {
        QMessageBox::critical(this, "Invalid Input", "The email address is not valid.");
        return;
    }

    // Validate password: must have at least 6 characters, with both uppercase and lowercase letters
    QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z]).{6,}$");
    QRegularExpressionMatch passwordMatch = passwordRegex.match(password);
    if (!passwordMatch.hasMatch()) {
        QMessageBox::critical(this, "Invalid Input", "Password must contain at least 6 characters with both uppercase and lowercase letters.");
        return;
    }

    // Validate age: the person must be between 18 and 100 years old
    QDate currentDate = QDate::currentDate();
    int age = currentDate.year() - dob.year();
    if (currentDate.month() < dob.month() || (currentDate.month() == dob.month() && currentDate.day() < dob.day())) {
        age--;  // The person hasn't had their birthday yet this year, so subtract one year
    }

    if (age < 18) {
        QMessageBox::critical(this, "Invalid Input", "The person must be at least 18 years old.");
        return;
    }

    if (age > 100) {
        QMessageBox::critical(this, "Invalid Input", "The person must be no older than 100 years.");
        return;
    }

    // If everything is validated, proceed with the update
    QByteArray photoData;
    if (!photo.isEmpty()) {
        QFile photoFile(photo);
        if (photoFile.open(QIODevice::ReadOnly)) {
            photoData = photoFile.readAll();
        } else {
            QMessageBox::warning(this, "Error", "Failed to load photo. Check the file path.");
            return;
        }
    }

    // Now update the database with the validated fields
    QSqlQuery query;
    query.prepare("UPDATE employees SET NOM = :nom, PRENOM = :prenom, TEL = :tel, EMAIL = :email, "
                  "PASSWORD = :password, GENDER = :gender, DOB = :dob, POSTE = :poste, PHOTO = :photo WHERE ID = :id");

    // Bind the values to the query
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", tel);
    query.bindValue(":email", email);
    query.bindValue(":password", password);
    query.bindValue(":gender", gender);
    query.bindValue(":dob", dob);
    query.bindValue(":poste", poste);
    query.bindValue(":id", employeeId);  // Use the stored employee ID
    query.bindValue(":photo", photoData);  // Bind the photo (if available)

    // Execute the query
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Employee data updated successfully.");
        ui->Nomu->clear();
        ui->Prenomu->clear();
        ui->Telu->clear();
        ui->Emailu->clear();
        ui->Passu->clear();
        ui->Photou->clear();  // Reset photo QLineEdit
        ui->Genderu->setCurrentIndex(0);  // Reset to the first item (if applicable)
        ui->Dobu->setDate(QDate::currentDate());  // Reset to current date
        ui->Posteu->setCurrentIndex(0);  // Reset to the first item (if applicable)

    } else {
        QMessageBox::critical(this, "Error", "Failed to update employee: " + query.lastError().text());
    }
}

void MainWindow::on_trier_clicked()
{
    // Get the selected column from the comboBox
    QString sortBy = ui->comboBox->currentText();
    int columnIndex = -1;

    // Map the selection to the corresponding column index
    if (sortBy == "ID") {
        columnIndex = 0;  // ID column
    } else if (sortBy == "Nom") {
        columnIndex = 1;  // Nom column
    } else if (sortBy == "Prenom") {
        columnIndex = 2;  // Prenom column
    } else if (sortBy == "Telephone") {
        columnIndex = 3;  // Telephone column
    } else if (sortBy == "Email") {
        columnIndex = 4;  // Email column
    }

    // Ensure the column index is valid
    if (columnIndex == -1) {
        return;  // Invalid column, return early
    }

    // Check if we have a model set to the QTableView
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel *>(ui->tableView->model());
    if (!model) {
        return; // No model found, return
    }

    // Toggle sorting order (ascending/descending)
    if (isAscending) {
        model->sort(columnIndex, Qt::AscendingOrder);  // Ascending order
    } else {
        model->sort(columnIndex, Qt::DescendingOrder); // Descending order
    }

    // Toggle the sorting order for the next click
    isAscending = !isAscending;
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

#include <QSqlRecord>  // Add this line at the top of the file

void MainWindow::on_delete_btn_clicked()
{
    // Get the selected index in the table view
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();

    // Check if any row is selected
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "No selection", "Please select a row to delete.");
        return;
    }

    // Get the row index of the selected item (we assume it's the first selected row)
    int row = selectedIndexes.first().row();

    // Retrieve data from the selected row
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    QString nom = model->data(model->index(row, 1)).toString();  // Get the 'Nom' from column 1
    QString prenom = model->data(model->index(row, 2)).toString();  // Get the 'Prenom' from column 2
    QString tel = model->data(model->index(row, 3)).toString();  // Get the 'Tel' from column 3
    QString email = model->data(model->index(row, 5)).toString();  // Get the 'Email' from column 5
    QString gender = model->data(model->index(row, 4)).toString();  // Get the 'Gender' from column 4
    QString poste = model->data(model->index(row, 8)).toString();  // Get the 'Poste' from column 8

    // Create a message showing all the data (excluding photo)
    QString message = QString("Are you sure you want to delete:\n\n"
                              "Nom: %1\n-----\nPrenom: %2\n-----\nTel: %3\n-----\nEmail: %4\n-----\nGender: %5\n-----\nPoste: %6")
                          .arg(nom)
                          .arg(prenom)
                          .arg(tel)
                          .arg(email)
                          .arg(gender)
                          .arg(poste);

    // Show a confirmation dialog
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Deletion", message, QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Create a query to delete the selected employee
        QSqlQuery query;
        query.prepare("DELETE FROM EMPLOYEES WHERE ID = :id");

        // Get the ID of the selected employee
        int id = model->data(model->index(row, 0)).toInt();  // Get the 'ID' from column 0

        // Bind the ID to the query
        query.bindValue(":id", id);

        // Execute the query to delete the employee
        if (query.exec()) {
            QMessageBox::information(this, "Success", "Employee deleted successfully.");
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete employee: " + query.lastError().text());
        }

        // Refresh the table after deletion
        displayEmployees();
    }
}

