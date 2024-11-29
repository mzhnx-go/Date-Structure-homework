#include "tableattribute.h"

TableAttribute::TableAttribute(QString studentId, QString studentName, QString className, QString selectedCourse, QList<double> unitGrade, double finalGrade)
    : studentId(studentId), studentName(studentName), className(className), selectedCourse(selectedCourse), unitGrade(unitGrade), finalGrade(finalGrade)
{
}

QString TableAttribute::getStudentId() const {
    return studentId;
}

QString TableAttribute::getStudentName() const {
    return studentName;
}

QString TableAttribute::getClassName() const {
    return className;
}

QString TableAttribute::getSelectedCourse() const {
    return selectedCourse;
}

QList<double> TableAttribute::getUnitGrade() const {
    return unitGrade;
}

double TableAttribute::getFinalGrade() const {
    return finalGrade;
}
