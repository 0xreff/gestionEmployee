#ifndef EMPLOYEEQUERYMODEL_H
#define EMPLOYEEQUERYMODEL_H

#include <QSqlQueryModel>
#include <QPixmap>
#include <QImage>
#include <QMap>

class EmployeeQueryModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    explicit EmployeeQueryModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role) const override;

private:
    mutable QMap<int, QPixmap> imageCache;  // Cache for the scaled images (index to QPixmap)
};

#endif // EMPLOYEEQUERYMODEL_H
