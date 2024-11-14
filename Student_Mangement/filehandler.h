#include <QString>
#include <QVector>
#include "user/student.h"
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

class FileHandler
{
public:
    FileHandler();
    ~FileHandler();
    bool loadStudent(const QString &fileName, QVector<Student> &students);
    bool addStudent(const QString &fileName, const QVector<Student> &students);
    bool deleteStudent(const QString &fileName, const QVector<Student> &students);

private:
    bool readFile(const QString &fileName,  QString &contents);
    bool writeFile(const QString &fileName, const QString &contents);
};

#endif // FILEHANDLER_H
