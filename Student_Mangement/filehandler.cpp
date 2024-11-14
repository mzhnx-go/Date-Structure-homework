#include "filehandler.h"
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>
#include <QMessageBox>
#include <QString>
FileHandler::FileHandler() {}


 bool FileHandler::loadStudent(const QString &fileName, QVector<Student> &students) {
    //TODO::把文件加载在学生类中
    QString contents;
    if (!readFile(fileName, contents)) {
        qWarning() <<"Error in loadStudent";
    }

    QTextStream stream(&contents);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        if (line.isEmpty()) {
            continue;
        }
    QStringList parts = line.split(" ");
        if (parts.size() < 6) {
        qWarning() << "'Error in loadStudent' 学生数据缺少基本信息";
        }
        QString studentId = parts[0];
        QString name = parts[1];
        QString gender = parts[2];
        QString grade = parts[3];
        QString college = parts[4];
        QString classInfo = parts[5];
        QSet<QString> courses;
        for (int i = 6; i < parts.size(); i ++) {
            QString courseId = parts[i];
            courses.insert(courseId);
        }
        Student student(studentId, name, gender, grade, college, classInfo, courses);
        students.append(student);
    }
    return true;
}
bool FileHandler::addStudent(const QString &fileName, const QVector<Student> &students) {
    //TODO::在文件中新加入学生数据

}
bool FileHandler::deleteStudent(const QString &fileName, const QVector<Student> &students) {
    //TODO::删除文件中的学生数据
}


  bool FileHandler::readFile(const QString &fileName,  QString &contents) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning()<< "'Error in readFile' 无法读取文件:" << fileName;
        QWidget *parent = nullptr; // 如果有父窗口，可以传递父窗口指针
        QMessageBox::critical(parent, "错误", "无法打开文件：" + fileName);
        return false;
    }
    QTextStream in(&file);
    contents = in.readAll();
}


bool FileHandler::writeFile(const QString &fileName, const QString &contents) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "'Error in writeFile' 无法打开文件:" << fileName;
        QWidget *parent = nullptr; // 如果有父窗口，可以传递父窗口指针
        QMessageBox::critical(parent, "错误", "无法打开文件：" + fileName);
        return false;
    }
    QTextStream out(&file);
    out << contents;
    file.close();
    return true;
}

