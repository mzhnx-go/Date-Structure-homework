#ifndef UTILS_H
#define UTILS_H
#include <QString>
class Utils
{
public:
    Utils();
    static bool constructTableAttribue(3QHash<QString, Student> studentIdMap, // 以学生Id作为键值
                                       QHash<QString, Student> studentCourseIdMap; //以学生所选课程Id作为键值
                                       QHash<QPair<QString, QString>, Score> scoreMap; //以学生Id和课程Id组成复合键,学生Id在前,课程Id在后
                                       QHash<QString, Course> courseIdMap;);
};

#endif // UTILS_H
