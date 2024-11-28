#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QString>
#include <QVector>
#include "user/student.h"
#include "user/score.h"
#include "user/course.h"

/*
 * 用来读取和修改file文件夹中的一个类
 * 包括学生，教师，成绩，课程，用户等表
 * 学生，教师使用列表列表(vector)存储
 * 用户使用字典
 * TODO:: 课程和成绩待定
 * */

class FileHandler
{
public:
    static bool loadUsers(const QString &fileName, QMap<QString, QString>&users);
    static bool loadStudent(const QString &fileName, QVector<Student> &students);
    static bool loadScores(const QString &fileName, QVector<Score> &scores);
    static bool loadCourses(const QString &fileName, QVector<Course> &courses);
    //TODO:: 将修改后的scores写入文件中
    static bool modifyScoresFile(QVector<Score> &scores, const QString &fileName);


    //可能无用的函数
    static bool addStudent(const QString &fileName, const QVector<Student> &students);
    static bool deleteStudent(const QString &fileName, const QVector<Student> &students);

private:
    FileHandler();
    ~FileHandler();
    static bool  readFile(const QString &fileName,  QString &contents);
    static bool  writeFile(const QString &fileName, const QString &contents);
};

#endif // FILEHANDLER_H
