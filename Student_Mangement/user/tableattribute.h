#ifndef TABLEATTRIBUTE_H
#define TABLEATTRIBUTE_H
#include <QString>
#include <QStringList>
class TableAttribute
{
    /*
header << "学号" << "姓名" << "班级" << "所选课程" << "第一次成绩"
 "二" << "三" << "四" << "五" << "六" << "期末成绩";*/
private:
    QString studentId;
    QString studentName;
    QString className;
    QString selectedCourse;
    QStringList unitGrade;
    QString finalGrade;
 public:
    TableAttribute( QString studentId, QString studentName, QString className,
                   QString selectedCourse,QStringList unitGrade,QString finalGrade
                    );
};

inline TableAttribute::TableAttribute(QString studentId, QString studentName, QString className, QString selectedCourse, QStringList unitGrade, QString finalGrade)
{

}

#endif // TABLEATTRIBUTE_H
