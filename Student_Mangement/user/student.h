#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QSet>
#include "course.h"
class  Student
{
private:
    QString studentId;
    QString name;
    QString gender;
    QString grade;
    QString college;
    QString classInfo;
    QSet<QString> courses; //存放courseId

public:
    Student();
    Student(const QString &studentId,
            const QString &name,
            const QString &gender,
            const QString &grade,
            const QString &college,
            const QString &classInfo,
            const QSet<QString> &courses);

    void setStudentID(const QString &id) { studentId = id; }
    void setName(const QString &name) { this->name = name; }
    void setGender(const QString &gender) { this->gender = gender; }
    void setGrade(const QString &grade) { this->grade = grade; }
    void setCollege(const QString &college) { this->college = college; }
    void setClassInfo(const QString &classInfo) { this->classInfo = classInfo; }
    void addCourse(const QString &course) { courses.insert(course); }
    void setCourse(QSet<QString> courses);
    QString getId() const { return studentId; }
    QString getName() const { return name; }
    QString getGender() const { return gender; }
    QString getGrade() const { return grade; }
    QString getCollege() const { return college; }
    QString getClassInfo() const { return classInfo; }
    QSet<QString> getCourses() const { return courses; }
    bool operator==(const Student &other) const;
    bool hasSelectedCourse(const Course &course); //判断有无选择这门课程
    int getSelectedCoursesCount() const {return courses.count();}
    void removeCourse(QString CourseId);
};

#endif // STUDENT_H
