#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QString>
#include <QVector>
#include "user/student.h"
#include "user/score.h"
#include "user/course.h"
#include "user/optioncourse.h"
/*
 * 用来读取和修改file文件夹中的一个类
 * 包括学生，教师，成绩，课程，用户等表
 * 学生，教师使用列表列表(vector)存储
 * 用户使用字典
 *
 * */

class FileHandler
{
public:
    static bool loadUsers(const QString &fileName, QMap<QString, QString>&users);
    static bool loadStudent(const QString &fileName, QVector<Student> &students);
    static bool loadScores(const QString &fileName, QVector<Score> &scores);
    static bool loadCourses(const QString &fileName, QVector<Course> &courses);
    static bool loadOptionalCourse(const QString &fileName, QVector<OptionCourse> &courses);
    static bool saveScoreFiles(const QVector<Score> &scores, const QString &fileName);
    static bool modifyCourses(const QVector<OptionCourse> &courses, const QString &fileName); //将修改后的数组保存到文件中

private:
    FileHandler();
    ~FileHandler();
    static bool  readFile(const QString &fileName,  QString &contents);
    static bool  writeFile(const QString &fileName, const QString &contents);
};

#endif // FILEHANDLER_H
