#include "utils.h"
#include <QDebug>

// 构建表格展示属性
bool Utils::constructTableAttribue(
    const QVector<Student> &students, const QVector<Score> &scores, const QVector<Course> &courses,
    QHash<QString, Student> studentIdMap,
    QHash<QPair<QString, QString>, Score> scoreMap,
    QHash<QString, Course> courseIdMap, QVector<TableAttribute> &tables)
{
    QList<double> unitGrade;
    double finalGrade;

    // 用成绩遍历，因为一个学生可能选不同的课有不同的成绩
    for (const Score &score : scores) {
        if (!studentIdMap.contains(score.getStudentId())) {
            qWarning() << "无法从成绩数据中匹配到该学生数据";
            return false;
        }
        if (!courseIdMap.contains(score.getCourseId())) {
            qWarning() << "无法从成绩数据中匹配到该课程数据";
            return false;
        }

        unitGrade = score.getUnitTestList();
        finalGrade = score.getFinalExamScore();
        QString studentId = score.getStudentId();
        Student student = studentIdMap[studentId];
        QString studentName = student.getName();
        QString className = student.getClassInfo();
        Course course = courseIdMap[score.getCourseId()];
        QString selectedCourse = course.getCourseName();

        tables.append(TableAttribute(studentId, studentName, className, selectedCourse, unitGrade, finalGrade));
    }
    return true;
}

// 构建匹配课程和可选课程的map
void Utils::matchCourseAndOptionCourse(
    const QVector<Course> &courses, const QVector<OptionCourse> &optionCourses,
    QMap<QString, QPair<Course, OptionCourse>> &mapCourses)
{
    // 使用哈希表来快速查找 OptionCourse
    QMap<QString, OptionCourse> optionCourseMap;

    // 先将所有 OptionCourse 加入到哈希表中
    for (const auto &optionCourse : optionCourses) {
        optionCourseMap[optionCourse.getCourseId()] = optionCourse;
    }

    // 再遍历 courses 并尝试匹配 OptionCourse
    for (const auto &course : courses) {
        if (optionCourseMap.contains(course.getCourseId())) {
            mapCourses[course.getCourseId()] = qMakePair(course, optionCourseMap[course.getCourseId()]);
        }
    }
}
