#include "EmployeeQueryModel.h"

EmployeeQueryModel::EmployeeQueryModel(QObject *parent) : QSqlQueryModel(parent)
{
    // You can place initialization code here, if necessary
}

QVariant EmployeeQueryModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DecorationRole) {
        // If it's the photo column (assuming the photo is in the 3rd column)
        if (index.column() == 3) {  // Adjust if needed
            QByteArray photoData = QSqlQueryModel::data(index, Qt::DisplayRole).toByteArray();
            QImage img;
            img.loadFromData(photoData);  // Load the BLOB data as an image
            QPixmap pixmap = QPixmap::fromImage(img);  // Convert image to QPixmap

            // Scale the pixmap to 10x10 px (or whatever size you desire)
            pixmap = pixmap.scaled(10, 10, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            return pixmap;  // Return the scaled QPixmap for display
        }
    }

    return QSqlQueryModel::data(index, role);  // Default behavior for other columns
}

