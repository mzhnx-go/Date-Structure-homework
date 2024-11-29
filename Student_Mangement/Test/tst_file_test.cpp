#include <QtTest>
#include <QVector>
#include <QString>
#include <QTemporaryFile>
#include <QDebug>
#include "../user/student.h"
#include "../filehandler.h"
#include "../global.h"
#include "../user/score.h"
#include "../user/tableattribute.h"
#include "utils.h"
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
    void test_loadUsers1();
    void test_loadScores1();
    void test_loadStudent1();
    void test_loadStudent2(); //测试能否正确读取学生数据
    void test_loadCourses1(); //测试读取课程数据
    void test_constructTableAttribue1(); //检测能否将数据加载在表中
};

file_test::file_test() {}
file_test::file_test(int argc, char **argv) : argc(argc), argv(argv) {}
file_test::~file_test() {}

void file_test::initTestCase()
{
    QString currentPath = QDir::currentPath();
    projectRoot = currentPath.left(currentPath.lastIndexOf("/test/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug"));
    initFilePath();
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
    QString scoresPath = getAbsolutePath(scoresReFilePath);
    //打印路径
    qDebug() << "根目录" << projectRoot;
    qDebug() << "学生文件决定路径" << studentsPath;
    qDebug() << "课程路径" << coursesPath;
    qDebug() << "成绩路径" << scoresPath;
    // 检查文件是否存在
    QVERIFY(QFile::exists(studentsPath));
    QVERIFY(QFile::exists(coursesPath));
    QVERIFY(QFile::exists(scoresPath));

    // 读取文件内容（示例）
    QFile studentsFile(studentsPath);
    QFile coursesFile(coursesPath);
    QFile gradesFile(scoresPath);
    QVERIFY(studentsFile.open(QIODevice::ReadOnly | QIODevice::Text));
    QVERIFY(coursesFile.open(QIODevice::ReadOnly | QIODevice::Text));
    QVERIFY(gradesFile.open(QIODevice::ReadOnly | QIODevice::Text));
    QTextStream in1(&studentsFile);
    QString content1 = in1.readAll();
    qDebug() << "student文件内容:" << content1;
    QVERIFY(!content1.isEmpty());
    studentsFile.close();
    QTextStream in2(&coursesFile);
    QString content2 = in2.readAll();
    qDebug() << "courses文件内容:" << content2;
    QVERIFY(!content2.isEmpty());
    coursesFile.close();
    QTextStream in3(&gradesFile);
    QString content3 = in3.readAll();
    qDebug() << "grades文件内容:" << content3;
    QVERIFY(!content3.isEmpty());
    gradesFile.close();
}

void file_test::test_loadUsers1() {
    QString stuUsersPath = getAbsolutePath(stuUserReFilePath);
    QString teaUsersPath = getAbsolutePath(teacherUserReFilePath);
    QMap <QString, QString> stuUsers;
    QMap <QString, QString> teaUsers;
    FileHandler::loadUsers(stuUsersPath, stuUsers);
    FileHandler::loadUsers(teaUsersPath, teaUsers);
    qDebug() << "stuUsers";
    for (QMap<QString, QString>::const_iterator it = stuUsers.constBegin(); it != stuUsers.constEnd(); it++) {
        qDebug() << "Key:" << it.key() << "Value:" << it.value();
    }
    qDebug() << "teaUsers";
    for (QMap<QString, QString>::const_iterator it = teaUsers.constBegin(); it != teaUsers.constEnd(); it++) {
        qDebug() << "Key:" << it.key() << "Value:" << it.value();
    }
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
    QVector<Student> loadedStudents;
    QVERIFY(FileHandler::loadStudent(tempFile.fileName(), loadedStudents));
    for (int i = 0; i < loadedStudents.size(); i ++) {
        Student student = loadedStudents[i];
    }
    QCOMPARE(loadedStudents, expected);
}

void file_test::test_loadStudent2() {
    //测试用fileHndler中loadStudents函数读取文件数据
    QVector<Student> tempLoadStudent1;
    QString stuPath = getAbsolutePath(stuRelativeFilePath);
    qDebug() << "学生路径" << stuPath;
    FileHandler::loadStudent(getAbsolutePath(stuRelativeFilePath), tempLoadStudent1);
    for (int i = 0; i < tempLoadStudent1.size(); i++) {
        Student student = tempLoadStudent1[i];
        qDebug() << i << "位Id" << student.getId();
        qDebug() << i << "位Name" << student.getName();
        qDebug() << i << "位Gender" << student.getGender();
        qDebug() << i << "位Grade" << student.getGrade();
        qDebug() << i << "位学院" << student.getCollege();
        qDebug() << i << "位Class" << student.getClassInfo();
        qDebug() << i << "位Course" << student.getCourses();
    }
}

//测试能否读取成绩数据
void file_test::test_loadScores1() {
    QVector<Score> scores1;
    QString scorePath = getAbsolutePath(scoresReFilePath);
    FileHandler::loadScores(scorePath, scores1);
    for (int i = 0; i < scores1.size(); i++) {
        Score score = scores1[i];
        qDebug() << i << "学号:" << score.getStudentId();
        qDebug() << i << "课程号" << score.getCourseId();
        qDebug() << i << "单元测试成绩列表" << score.getUnitTestList();
        qDebug() << i << "期末考试成绩" << score.getFinalExamScore();
    }

}

void file_test::test_loadCourses1() {
    QVector<Course> courses1;
    QString coursePath = getAbsolutePath(coursesReFilePath);
    if(!FileHandler::loadCourses(coursePath, courses1)) {
        qWarning() << "加载课程数据失败";
    }
    for (int i = 0; i < courses1.size(); i++) {
        Course course = courses1[i];
        qDebug() << i << "课程号" << course.getCourseId();
        qDebug() << i << "课程名称" << course.getCourseName();
        qDebug() << i << "课程学分" << course.getTotalCredit();
        qDebug() << i << "任课教师" << course.getTeacher();
    }

}

void file_test::test_constructTableAttribue1() {
    QVector<Student> students;
    QVector<Score> scores;
    QVector<Course> courses;
    //没有filename
    if (!FileHandler::loadStudent(stuFilePath, students)) {
        qWarning() << "无法打开学生数据";
    }
    if (!FileHandler::loadCourses(coursesFilePath, courses)) {
        qWarning() << "无法打开课程数据";
    }
    if ( !FileHandler::loadScores(scoresFilePath, scores)) {
        qWarning() << "无法打开成绩数据";
    }
    //使用哈希表存储数据
    QHash<QString, Student> studentIdMap; // 以学生Id作为键值
    QHash<QString, Student> studentCourseIdMap; //以学生所选课程Id作为键值
    QHash<QPair<QString, QString>, Score> scoreMap; //以学生Id和课程Id组成复合键,学生Id在前,课程Id在后
    QHash<QString, Course> courseIdMap; //以课程Id作为键值
    for (const auto &student: students) {
        studentIdMap[student.getId()] = student;
    }
    for (const auto &score: scores) {
        scoreMap[qMakePair(score.getStudentId(), score.getCourseId())] = score;
    }
    for (const auto &course: courses) {
        courseIdMap[course.getCourseId()] = course;
    }
    QVector<TableAttribute> tables;

    if (!Utils::constructTableAttribue(students, scores, courses, studentIdMap, scoreMap, courseIdMap, tables)) {
        qWarning() << "ERROR IN TeacherWindow::on_display_clicked(): 无法加载table数据";
    }
    for (int i = 0; i < tables.size(); i++) {
        TableAttribute table = tables[i];
        qDebug() << "学号" << table.getStudentId();
        qDebug() << "姓名" << table.getStudentName();
        qDebug() << "班级" << table.getClassName();
        qDebug() << "课程名" << table.getSelectedCourse();
        qDebug() << "小测分数" << table.getUnitGrade();
        qDebug() << "期末成绩" << table.getFinalGrade();
    }

}

QTEST_APPLESS_MAIN(file_test)

#include "tst_file_test.moc"


















