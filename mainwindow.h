#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QDate>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QPixmap>
#include <QImage>
#include <QByteArray>
#include <QPainter>
#include <QDialog>
#include <QLabel>
#include<QFileDialog>
#include<QSqlRecord>
#include <QSqlTableModel>
#include "connection.h"
#include "EmployeeQueryModel.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajouter_clicked();

    void on_Reset_clicked();

    void on_Actualiser_clicked();

    void displayEmployees();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_search_btn_clicked();

    void on_update_btn_clicked();

    void on_updated_btn_clicked();

    void on_trier_clicked();

    void on_upload_btn_clicked();

    void on_select_clicked();

    void on_delete_btn_clicked();

private:
    Ui::MainWindow *ui;
    int employeeId;
    bool isAscending;
};
#endif // MAINWINDOW_H
