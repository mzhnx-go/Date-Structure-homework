#include "course.h"

Course::Course() {}

Course::Course(const QString &id, const QString &name, const QString &totalCredit, const QString &teacher)
    : courseId(id), courseName(name), totalCredit(totalCredit), teacher(teacher) {}

// 实现 operator== 函数
bool Course::operator==(const Course &other) const
{
    return courseId == other.courseId;
}

// 实现 qHash 函数
uint qHash(const Course &course, uint seed)
{
    return ::qHash(course.getCourseId(), seed);
}
