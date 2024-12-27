
#include "student.h"
Student::Student(){}

Student::Student(const QString &id, const QString &name, const QString &gender, const QString &grade, const QString &college, const QString &classInfo, const QSet<QString> &courses)
    : studentId(id), name(name), gender(gender), grade(grade), college(college), classInfo(classInfo), courses(courses)
{
}

void Student::setCourse(QSet<QString> courses)
{
    this->courses = courses;
}

// 实现 operator==
bool Student::operator==(const Student &other) const
{
    return (studentId == other.studentId &&
            name == other.name &&
            gender == other.gender &&
            grade == other.grade &&
            college == other.college &&
            classInfo == other.classInfo &&
            courses == other.courses);
}

bool Student::hasSelectedCourse(const Course &course)
{
    if(courses.contains(course.getCourseId())) {
        return true;
    }
    return false;
}

void Student::removeCourse(QString CourseId)
{
    if (courses.contains(CourseId)) {
        courses.remove(CourseId);
    }
}
