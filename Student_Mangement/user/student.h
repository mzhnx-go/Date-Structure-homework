#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QSet>
#include <user/course.h>
#include <user/score.h>
class Student
{
private:
    QString studentID;
    QString name;
    QString gender;
    QString grade;
    QString college;
    QString classInfo;
    QSet<QString> courses;

public:
    Student();
    Student(const QString &studentID,
            const QString &name,
            const QString &gender,
            const QString &grade,
            const QString &college,
            const QString &classInfo,
            const QSet<QString> &courses
            )
        : studentID(studentID), name(name), gender(gender), grade(grade), college(college), classInfo(classInfo), courses(courses) {}

    void setStudentID(const QString &id) { studentID = id; }
    void setName(const QString &name) { this->name = name; }
    void setGender(const QString &gender) { this->gender = gender; }
    void setGrade(const QString &grade) { this->grade = grade; }
    void setCollege(const QString &college) { this->college = college; }
    void setClassInfo(const QString &classInfo) { this->classInfo = classInfo; }
    void addCourse(const QString &course) { courses.insert(course); }

    QString getStudentID() const { return studentID; }
    QString getName() const { return name; }
    QString getGender() const { return gender; }
    QString getGrade() const { return grade; }
    QString getCollege() const { return college; }
    QString getClassInfo() const { return classInfo; }
    QSet<QString> getCourses() const { return courses; }
};

#endif // STUDENT_H
