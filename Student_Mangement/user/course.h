#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QHash>

class Course
{
public:
    Course();
    Course(const QString &id, const QString &name, const QString &totalCredit, const QString &teacher);

    QString getCourseId() const { return courseId; }
    QString getCourseName() const { return courseName; }
    QString getTotalCredit() const { return totalCredit; }
    QString getTeacher() const { return teacher; }

    // 提供 operator== 函数
    bool operator==(const Course &other) const;

private:
    QString courseId;
    QString courseName;
    QString totalCredit;
    QString teacher;
};

// 声明 qHash 函数
uint qHash(const Course &course, uint seed = 0);

#endif // COURSE_H
