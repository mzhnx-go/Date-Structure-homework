#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <QSet>
#include "user/course.h"
#include "user/score.h"
#include "user/student.h"
#include "user/users.h"
#include "user/tableattribute.h"
#include "global.h"
class Utils
{
public:
    Utils();
    //构建列表展示属性
    static bool constructTableAttribue(
        const QVector<Student> &students, const QVector<Score> &scores, const QVector<Course> &courses, QHash<QString, Student> studentIdMap,
        QHash<QPair<QString, QString>, Score> scoreMap,
        QHash<QString, Course> courseIdMap, QVector<TableAttribute> &tables);

};


#endif // UTILS_H
