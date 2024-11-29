#include "utils.h"
Utils::Utils() {}
//把数据存在tables中
/*
header << "学号" << "姓名" << "班级" << "所选课程" << "第一次成绩"
 "二" << "三" << "四" << "五" << "六" << "期末成绩";*/
bool Utils::constructTableAttribue(const QVector<Student> &students, const QVector<Score> &scores, const QVector<Course> &courses, QHash<QString, Student> studentIdMap,
                                   QHash<QPair<QString, QString>, Score> scoreMap,
                                   QHash<QString, Course> courseIdMap, QVector<TableAttribute> &tables)
{
    QList<double> unitGrade;
    double finalGrade;
    //用成绩遍历，因为一个学生可能选不同的课有不同的成绩
    for (const Score &score: scores ) {
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

