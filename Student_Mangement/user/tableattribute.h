#ifndef TABLEATTRIBUTE_H
#define TABLEATTRIBUTE_H

#include <QString>
#include <QList>

class TableAttribute {
public:
    TableAttribute(QString studentId, QString studentName, QString className, QString selectedCourse, QList<double> unitGrade, double finalGrade);

    QString getStudentId() const;
    QString getStudentName() const;
    QString getClassName() const;
    QString getSelectedCourse() const;
    QList<double> getUnitGrade() const;
    double getFinalGrade() const;

private:
    QString studentId;
    QString studentName;
    QString className;
    QString selectedCourse;
    QList<double> unitGrade;
    double finalGrade;
};

#endif // TABLEATTRIBUTE_H
