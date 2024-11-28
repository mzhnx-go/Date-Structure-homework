#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>
#include <QCoreApplication>
#include <Qdir>
#include "user/student.h"
#include "user/score.h"
#include "user/course.h"
extern const QString stuRelativeFilePath;
extern const QString coursesReFilePath;
extern const QString scoresReFilePath;
extern const QString stuUserReFilePath;
extern const QString teacherUserReFilePath;
extern QString projectRoot;

extern  QString stuFilePath;
extern  QString coursesFilePath;
extern  QString stuUserFilePath;
extern  QString scoresFilePath;
extern  QString teacherUserFilePath;

extern QVector<Student> students;
extern QVector<Score> scores;
extern QVector<Course> courses;
extern QMap<QString, QString> stuUsers;
extern QMap<QString, QString> teacherUsers;
//初始化项目文件根目录
void initProjectRoot();
// 获取文件绝对路径的函数
QString getAbsolutePath(const QString &relativeFilePath);

void initFilePath();
#endif // GLOBAL_H
