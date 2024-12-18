#include "filehandler.h"
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QList>
#include <QRegularExpression>
FileHandler::FileHandler() {}
FileHandler::~FileHandler() {}

/*
 * 传入学生字典和教师字典
 * */
bool FileHandler::loadUsers(const QString &fileName, QMap<QString, QString>&users) {
    QString contents;
    if (!readFile(fileName, contents)) {
        qWarning() <<"Error in loadUsers";
    }
    QTextStream stream(&contents);
    QString line;
    while (stream.readLineInto(&line)) {
        if (line.isEmpty()) {
            continue; // 跳过空行
        }
        QStringList parts = line.split(" ", Qt::SkipEmptyParts);
        if (parts.size() < 2) {
            qWarning() << "Error in file format:" << fileName << "- Line:" << line
                       << "Missing user data (expected at least two fields: account and password)";
        } else {
            QString account = parts[0];
            QString password = parts[1];
            users[account] = password;
        }
    }

    return true;
}


bool FileHandler::loadStudent(const QString &fileName, QVector<Student> &students) {
    QString contents;
    if (!readFile(fileName, contents)) {
        qDebug() << "ERROR IN loadStudent : 无法读取学生文件";
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


bool FileHandler::loadScores(const QString &fileName, QVector<Score> &scores) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "ERROR IN loadScores: 无法打开scores文件" << fileName;
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty() || line.contains("#")) {
            continue;
        }

        QStringList parts = line.split(' ', Qt::SkipEmptyParts);
        if (parts.size() < 2) {
            qWarning() << "Invalid line format:" << line;
            continue;
        }

        QString studentId = parts[0];
        QString courseId = parts[1];
        QList<double> unitTestList;
         bool finalScoreOk = false, unitTestScoreOk = false ,finalScoreConvert = false;
        int finalIndex = 0;
        // Parse unit test scores until "final"
        for (int i = 2; i < parts.size() - 1; i++) {
            if (parts[i] == "final") {
                finalScoreOk = true;
                finalIndex = i+1;
                break;
            }
            double unitTestScore = parts[i].toDouble(&unitTestScoreOk);
            if (unitTestScoreOk) {
                unitTestList.append(unitTestScore);
            } else {
                qWarning() << "ERROR IN loadScore :Invalid unit test score in line:" << line;
                break; // Stop parsing if an invalid score is found
            }
        }

        double finalScore = -1;
        if (!finalScoreOk) {
            //没有期末成绩
        } else {
            finalScore = parts[finalIndex].toDouble(&finalScoreConvert);
        }
        scores.append(Score(studentId, courseId,  finalScore, unitTestList));
    }

    file.close();
    return true;
}
bool FileHandler:: loadCourses(const QString &fileName, QVector<Course> &courses) {
    QString contents;
    if (!readFile(fileName, contents)) {
        qWarning() << "ERROR IN loadCourses: 无法打开Courses文件";
        return false;
    }
    QTextStream stream(&contents);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        if (line.isEmpty()) {
            continue;
        }
        QStringList parts = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        if (parts.size() < 4) {
            qWarning() << "ERROR IN loadCourses: 缺少基本数据";
        }
        Course course(parts[0], parts[1], parts[2], parts[3]);
        courses.append(course);
}
    return true;
}

bool FileHandler::loadOptionalCourse(const QString &fileName, QVector<OptionCourse> &courses)
{
    QString contents;
    if (!readFile(fileName, contents)) {
        qWarning() << "ERROR IN FileHandler::loadOptionalCourse:: 无法打开OptionalCourses文件";
        return false;
    }
    QTextStream stream(&contents);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        if (line.isEmpty()) {
            continue;
        }
        QStringList parts =  line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        if (parts.size() < 2) {
            qWarning() << "ERROR IN FileHandler::loadOptionalCourse: 缺少基本数据";
        }
        OptionCourse optionCourse(parts[0], parts[1].toInt());
        courses.append(optionCourse);
    }
    return true;
}


bool FileHandler::saveScoreFiles(const QVector<Score> &scores, const QString &fileName)
{
    QString contents;
    for (const auto &score : scores) {
        contents += QString("%1 %2").arg(score.getStudentId()).arg(score.getCourseId());

        const QList<double> &unitTests = score.getUnitTestList();
        for (double grade : unitTests) {
            contents += QString(" %1").arg(grade);
        }

        contents += QString(" final %1\n").arg(score.getFinalExamScore());
    }
    return writeFile(fileName, contents.trimmed());
}

bool FileHandler::modifyCourses(const QVector<OptionCourse> &courses, const QString &fileName)
{
    QString contents;
    for (const auto &course : courses) {
        contents += course.getCourseId().trimmed() + " " + QString::number(course.getlastCourseNumber()) + "\n";
    }

    return writeFile(fileName, contents.trimmed());
}


bool FileHandler::saveOptionalCourse(const QString &fileName, QVector<OptionCourse> optionCourses)
{
    QString contents;
    for (const auto &course : optionCourses) {
        contents += QString("%1 %2\n").arg(course.getCourseId()).arg(course.getlastCourseNumber());
    }

    return writeFile(fileName, contents.trimmed());
}
bool FileHandler::saveStudentFile(const QVector<Student> &students, const QString &fileName)
{
    QString contents;
    for (const auto &student : students) {
        // 构造每行的内容，使用空格分隔各个字段
        contents += student.getId() + " "
                    + student.getName() + " "
                    + student.getGender() + " "
                    + student.getGrade() + " "
                    + student.getCollege() + " "
                    + student.getClassInfo();

        // 添加选修课程编号
        QSet<QString> courses = student.getCourses();
        if (!courses.isEmpty()) {
            for (const QString &courseId : qAsConst(courses)) {
                contents += " " + courseId;
            }
        }

        // 每个学生信息后换行
        contents += "\n";
    }

    // 写入文件并返回操作结果
    return writeFile(fileName, contents.trimmed());
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
    return true;
}


bool FileHandler::writeFile(const QString &fileName, const QString &contents) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) { // 添加 Truncate 标志
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

