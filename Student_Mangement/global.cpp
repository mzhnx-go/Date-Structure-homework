#include "global.h"

const QString stuRelativeFilePath = "file/students.txt";
const QString coursesReFilePath = "file/courses.txt";
const QString gradesReFilePath = "file/grades.txt";
QString projectRoot;
void initProjectRoot() {
    // 获取根目录
    QString currentPath = QDir::currentPath();
    projectRoot = currentPath.left(currentPath.lastIndexOf("/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug"));
}

QString getAbsolutePath(const QString &relativeFilePath) {
    return QDir(projectRoot).absoluteFilePath(relativeFilePath);
}
