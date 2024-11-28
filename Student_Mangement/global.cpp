#include "global.h"

const QString stuRelativeFilePath = "file/students.txt";
const QString coursesReFilePath = "file/courses.txt";
const QString scoresReFilePath = "file/scores.txt";
const QString stuUserReFilePath = "file/stuusers.txt";
const QString teacherUserReFilePath = "file/teacherusers.txt";
QString projectRoot;
void initProjectRoot() {
    // 获取根目录
    QString currentPath = QDir::currentPath();
    projectRoot = currentPath.left(currentPath.lastIndexOf("/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug"));
}

QString getAbsolutePath(const QString &relativeFilePath) {
    return QDir(projectRoot).absoluteFilePath(relativeFilePath);
}

void initUsersPath() {
    QString stuFilePath = getAbsolutePath(stuRelativeFilePath);
    QString stuUserFilePath = getAbsolutePath(stuUserReFilePath);
    QString scoresFilePath = getAbsolutePath(scoresReFilePath);
    QString teacherUserFilePath = getAbsolutePath(teacherUserReFilePath);
    QString coursesFilePath = getAbsolutePath(coursesReFilePath);
}
