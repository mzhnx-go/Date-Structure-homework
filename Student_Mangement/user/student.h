#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QSet>
#include <user/course.h> // 假设 Course 类已经定义在这个头文件中
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
    QSet<Course> courses;
    QSet<Score> scores; // 使用 QSet<Score> 存储分数

public:
    Student();
    Student(const QString &studentID,
            const QString &name,
            const QString &gender,
            const QString &grade,
            const QString &college,
            const QString &classInfo,
            const QSet<Course> &courses,
            const QSet<Score> &scores)
        : studentID(studentID), name(name), gender(gender), grade(grade), college(college), classInfo(classInfo), courses(courses), scores(scores) {}

    void setStudentID(const QString &id) { studentID = id; }
    void setName(const QString &name) { this->name = name; }
    void setGender(const QString &gender) { this->gender = gender; }
    void setGrade(const QString &grade) { this->grade = grade; }
    void setCollege(const QString &college) { this->college = college; }
    void setClassInfo(const QString &classInfo) { this->classInfo = classInfo; }
    void addCourse(const Course &course) { courses.insert(course); }
    void addScore(const Score &score) { scores.insert(score); }

    QString getStudentID() const { return studentID; }
    QString getName() const { return name; }
    QString getGender() const { return gender; }
    QString getGrade() const { return grade; }
    QString getCollege() const { return college; }
    QString getClassInfo() const { return classInfo; }
    QSet<Course> getCourses() const { return courses; }
    QSet<Score> getScores() const { return scores; }
};

#endif // STUDENT_H
