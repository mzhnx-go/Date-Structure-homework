#include <QtTest>
#include <QVector>
#include <QString>
#include <QTemporaryFile>
#include <QDebug>
#include "../user/student.h"
#include "../filehandler.h"
#include "../global.h"
class file_test : public QObject
{
    Q_OBJECT

private:
    int argc;
    char **argv;
public:
    file_test();
    file_test(int argc, char **argv);
    ~file_test();


private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_findFile1(); //测试是否能查找到文件位置
    void test_loadStudent1();
};

file_test::file_test() {}

file_test::file_test(int argc, char **argv):argc(argc), argv(argv) {}

file_test::~file_test() {}

void file_test::initTestCase()
{
    QString currentPath = QDir::currentPath();
    projectRoot = currentPath.left(currentPath.lastIndexOf("/test/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug"));
}

void file_test::cleanupTestCase()
{
    // 清理测试用例，释放全局资源
}

void file_test::test_findFile1() {
    qDebug() << "findFile1开始了";
    // 获取文件的绝对路径
    QString studentsPath = getAbsolutePath(stuRelativeFilePath);
    QString coursesPath = getAbsolutePath(coursesReFilePath);
    QString gradesPath = getAbsolutePath(gradesReFilePath);

    //打印路径
    qDebug() << "根目录" << projectRoot;
    qDebug() << "学生文件决定路径" << studentsPath;
    qDebug() << "课程路径" << coursesPath;
    qDebug() << "成绩路径" << gradesPath;


    // 检查文件是否存在
    QVERIFY(QFile::exists(studentsPath));
    QVERIFY(QFile::exists(coursesPath));
    QVERIFY(QFile::exists(gradesPath));

    // 读取文件内容（示例）
    QFile studentsFile(studentsPath);
    QVERIFY(studentsFile.open(QIODevice::ReadOnly | QIODevice::Text));
    QTextStream in(&studentsFile);
    QString content = in.readAll();
    QVERIFY(!content.isEmpty());
    studentsFile.close();

}

void file_test::test_loadStudent1()
{
    // 测试用例 1: 正常情况
    QString input = "1001 Zhang Male 1 College1 Class1 001 002\n"
                    "1002 Li Female 1 College2 Class2 003 004";

    QVector<Student> expected = {
        Student("1001", "Zhang", "Male", "1", "College1", "Class1", {"001", "002"}),
        Student("1002", "Li", "Female", "1", "College2", "Class2", {"003", "004"})
    };
    QTemporaryFile tempFile;
    if (!tempFile.open()) {
        QFAIL("Failed to create temporary file");
    }

    tempFile.write(input.toUtf8());
    tempFile.close();
    FileHandler fileHandler;
    QVector<Student> loadedStudents;
    QVERIFY(fileHandler.loadStudent(tempFile.fileName(), loadedStudents));
    for (int i = 0; i < loadedStudents.size(); i ++) {
        Student student = loadedStudents[i];
    }
    QCOMPARE(loadedStudents, expected);
}


QTEST_APPLESS_MAIN(file_test)

#include "tst_file_test.moc"
