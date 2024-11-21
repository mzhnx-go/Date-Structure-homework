#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>
#include <QCoreApplication>
#include <Qdir>
extern const QString stuRelativeFilePath;
extern const QString coursesReFilePath;
extern const QString gradesReFilePath;
extern QString projectRoot;

//初始化项目文件根目录
void initProjectRoot();

// 获取文件绝对路径的函数
QString getAbsolutePath(const QString &relativeFilePath);


#endif // GLOBAL_H
