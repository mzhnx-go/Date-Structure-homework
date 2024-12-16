#include "global.h"

const QString stuRelativeFilePath = "file/students.txt";
const QString coursesReFilePath = "file/courses.txt";
const QString scoresReFilePath = "file/scores.txt";
const QString stuUserReFilePath = "file/stuusers.txt";
const QString teacherUserReFilePath = "file/teacherusers.txt";
const QString optionCourseReFilePath = "file/OptionalCourses.txt";

QString projectRoot;
QString stuFilePath;
QString coursesFilePath;
QString stuUserFilePath;
QString scoresFilePath;
QString teacherUserFilePath;
QString optionCourseFilePath;

void initProjectRoot() {
    // 获取根目录
    QString currentPath = QDir::currentPath();
    projectRoot = currentPath.left(currentPath.lastIndexOf("/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug"));
}

QString getAbsolutePath(const QString &relativeFilePath) {
    return QDir(projectRoot).absoluteFilePath(relativeFilePath);
}

void initFilePath()
{
    stuFilePath = getAbsolutePath(stuRelativeFilePath);
    stuUserFilePath = getAbsolutePath(stuUserReFilePath);
    scoresFilePath = getAbsolutePath(scoresReFilePath);
    teacherUserFilePath = getAbsolutePath(teacherUserReFilePath);
    coursesFilePath = getAbsolutePath(coursesReFilePath);
    optionCourseFilePath = getAbsolutePath(optionCourseReFilePath);
}
