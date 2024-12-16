#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QVector>
#include <QHash>
#include <QPair>
#include "user/course.h"
#include "user/score.h"
#include "user/student.h"
#include "user/tableattribute.h"
#include "user/optioncourse.h"

class Utils {
public:
    // 构建列表展示属性
    static bool constructTableAttribue(
        const QVector<Student> &students, const QVector<Score> &scores, const QVector<Course> &courses,
        QHash<QString, Student> studentIdMap,
        QHash<QPair<QString, QString>, Score> scoreMap,
        QHash<QString, Course> courseIdMap, QVector<TableAttribute> &tables);

    // 构建匹配课程和可选课程的map
    static void matchCourseAndOptionCourse(
        const QVector<Course> &courses, const QVector<OptionCourse> &optionCourses,
        QMap<QString, QPair<Course, OptionCourse>> &mapCourses);
};

#endif // UTILS_H
