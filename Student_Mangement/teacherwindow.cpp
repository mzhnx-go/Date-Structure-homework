#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include "global.h"
#include "user/tableattribute.h"
#include "utils.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QHash>
#include <QPair>
#include <QMessageBox>
TeacherWindow::TeacherWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherWindow)

{
    ui->setupUi(this);
}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}


/*
*功能: 用于显示学生数据基本数据和成绩
*/
void TeacherWindow::on_display_clicked()
{
    QVector<Student> students;
    QVector<Score> scores;
    QVector<Course> courses;
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
        return;
    }
    // 清除表格内容
    ui->tb_tea->clearContents();
    ui->tb_tea->setRowCount(0); // 清除所有行
    // 动态确定表格的最大列数
    int maxUnitGrades = 0;
    for (const auto &table: tables) {
        maxUnitGrades = qMax(maxUnitGrades, table.getUnitGrade().size());
    }

    QStringList header;
    header << "学号" << "姓名" << "班级" << "所选课程";
    for (int i = 1; i <= maxUnitGrades; ++i) {
        header << QString("第%1次成绩").arg(i);
    }
    header << "期末成绩";

    ui->tb_tea->setColumnCount(header.size());
    ui->tb_tea->setHorizontalHeaderLabels(header);

    // 填充表格数据
    for (int row = 0; row < tables.size(); ++row) {
        const TableAttribute &table = tables[row];
        ui->tb_tea->insertRow(row);
        ui->tb_tea->setItem(row, 0, new QTableWidgetItem(table.getStudentId()));
        ui->tb_tea->setItem(row, 1, new QTableWidgetItem(table.getStudentName()));
        ui->tb_tea->setItem(row, 2, new QTableWidgetItem(table.getClassName()));
        ui->tb_tea->setItem(row, 3, new QTableWidgetItem(table.getSelectedCourse()));

        for (int col = 0; col < maxUnitGrades; ++col) {
            QString grade = col < table.getUnitGrade().size() ? QString::number(table.getUnitGrade()[col]) : "无";
            ui->tb_tea->setItem(row, 4 + col, new QTableWidgetItem(grade));
        }

        ui->tb_tea->setItem(row, 4 + maxUnitGrades, new QTableWidgetItem(QString::number(table.getFinalGrade())));
    }

}

//通过学号或姓名查找学生数据
void TeacherWindow::on_searchStu_clicked()
{
    QString input = ui->Id_or_name->text();  // 获取用户输入的学号或姓名

    // 清除表格内容
    ui->tb_tea->clearContents();
    ui->tb_tea->setRowCount(0); // 清除所有行

    // 加载学生数据
    QVector<Student> students;
    QVector<Score> scores;
    QVector<Course> courses;
    if (!FileHandler::loadStudent(stuFilePath, students)) {
        qWarning() << "无法打开学生数据";
        QMessageBox::warning(this, "警告", "无法打开学生数据文件");
        return;
    }
    if (!FileHandler::loadCourses(coursesFilePath, courses)) {
        qWarning() << "无法打开课程数据";
        QMessageBox::warning(this, "警告", "无法打开课程数据文件");
        return;
    }
    if (!FileHandler::loadScores(scoresFilePath, scores)) {
        qWarning() << "无法打开成绩数据";
        QMessageBox::warning(this, "警告", "无法打开成绩数据文件");
        return;
    }

    // 使用哈希表存储数据
    QHash<QString, Student> studentIdMap; // 以学生Id作为键值
    QHash<QPair<QString, QString>, Score> scoreMap; // 以学生Id和课程Id组成复合键,学生Id在前,课程Id在后
    QHash<QString, Course> courseIdMap; // 以课程Id作为键值
    for (const auto &student : students) {
        studentIdMap[student.getId()] = student;
    }
    for (const auto &score : scores) {
        scoreMap[qMakePair(score.getStudentId(), score.getCourseId())] = score;
    }
    for (const auto &course : courses) {
        courseIdMap[course.getCourseId()] = course;
    }

    // 查找匹配的学生
    QVector<TableAttribute> matchedTables;
    for (const auto &student : students) {
        if (student.getId() == input || student.getName() == input) {
            for (const auto &score : scores) {
                if (score.getStudentId() == student.getId()) {
                    const Course &course = courseIdMap[score.getCourseId()];
                    TableAttribute table(student.getId(), student.getName(), student.getClassInfo(), course.getCourseName(), score.getUnitTestList(), score.getFinalExamScore());
                    matchedTables.append(table);
                }
            }
        }
    }

    // 如果没有找到匹配的学生
    if (matchedTables.isEmpty()) {
        QMessageBox::information(this, "提示", "未找到匹配的学生");
        return;
    }

    // 动态确定表格的最大列数
    int maxUnitGrades = 0;
    for (const auto &table : matchedTables) {
        maxUnitGrades = qMax(maxUnitGrades, table.getUnitGrade().size());
    }

    QStringList header;
    header << "学号" << "姓名" << "班级" << "所选课程";
    for (int i = 1; i <= maxUnitGrades; ++i) {
        header << QString("第%1次成绩").arg(i);
    }
    header << "期末成绩";

    ui->tb_tea->setColumnCount(header.size());
    ui->tb_tea->setHorizontalHeaderLabels(header);

    // 填充表格数据
    for (int row = 0; row < matchedTables.size(); ++row) {
        const TableAttribute &table = matchedTables[row];
        ui->tb_tea->insertRow(row);
        ui->tb_tea->setItem(row, 0, new QTableWidgetItem(table.getStudentId()));
        ui->tb_tea->setItem(row, 1, new QTableWidgetItem(table.getStudentName()));
        ui->tb_tea->setItem(row, 2, new QTableWidgetItem(table.getClassName()));
        ui->tb_tea->setItem(row, 3, new QTableWidgetItem(table.getSelectedCourse()));

        for (int col = 0; col < maxUnitGrades; ++col) {
            QString grade = col < table.getUnitGrade().size() ? QString::number(table.getUnitGrade()[col]) : "无";
            ui->tb_tea->setItem(row, 4 + col, new QTableWidgetItem(grade));
        }

        ui->tb_tea->setItem(row, 4 + maxUnitGrades, new QTableWidgetItem(QString::number(table.getFinalGrade())));
    }

}

void TeacherWindow::on_exit_clicked()
{
    QApplication::quit();
}


//查找选修课成绩
void TeacherWindow::on_searchCor_clicked()
{
    QString input = ui->courseText->text();  // 获取用户输入的课程号或课程名
    // 清除表格内容
    ui->tb_tea->clearContents();
    ui->tb_tea->setRowCount(0); // 清除所有行

    // 加载学生数据
    QVector<Student> students;
    QVector<Score> scores;
    QVector<Course> courses;
    if (!FileHandler::loadStudent(stuFilePath, students)) {
        qWarning() << "无法打开学生数据";
        QMessageBox::warning(this, "警告", "无法打开学生数据文件");
        return;
    }
    if (!FileHandler::loadCourses(coursesFilePath, courses)) {
        qWarning() << "无法打开课程数据";
        QMessageBox::warning(this, "警告", "无法打开课程数据文件");
        return;
    }
    if (!FileHandler::loadScores(scoresFilePath, scores)) {
        qWarning() << "无法打开成绩数据";
        QMessageBox::warning(this, "警告", "无法打开成绩数据文件");
        return;
    }

    // 使用哈希表存储数据
    QHash<QString, Student> studentIdMap; // 以学生Id作为键值
    QHash<QPair<QString, QString>, Score> scoreMap; // 以学生Id和课程Id组成复合键,学生Id在前,课程Id在后
    QHash<QString, Course> courseIdMap; // 以课程Id作为键值
    for (const auto &student : students) {
        studentIdMap[student.getId()] = student;
    }
    for (const auto &score : scores) {
        scoreMap[qMakePair(score.getStudentId(), score.getCourseId())] = score;
    }
    for (const auto &course : courses) {
        courseIdMap[course.getCourseId()] = course;
    }
    //TODO::
    //先匹配课程
    //然后在通过课程和成绩匹配，成绩再与成绩匹配
    QVector<TableAttribute> matchedTables;
    for (const auto &course : courses) {
        if (course.getCourseId() == input || course.getCourseName() == input) {
            for (const auto &score : scores) {
                if (score.getCourseId() == course.getCourseId()) {
                    //课程和成绩匹配
                    const Student &student = studentIdMap[score.getStudentId()];
                    //课程名、学号、姓名、班级名称、小测成绩、期末考试成绩
                    TableAttribute table(student.getId(), student.getName(), student.getClassInfo(), course.getCourseName(), score.getUnitTestList(), score.getFinalExamScore());
                    matchedTables.append(table);
                }
            }
        }
    }
    if (matchedTables.isEmpty()) {
        QMessageBox::information(this, "提示","没有该课程或不存在该课程信息");
        return;
    }

    //创建表格最大列数
    int maxUnitGrades = 0;
    for (const auto &table : matchedTables) {
        maxUnitGrades = qMax(maxUnitGrades, table.getUnitGrade().size());
    }
    QStringList header;
    header << "课程名" << "姓名" << "班级"  ;
    for (int i = 1; i < maxUnitGrades; i++) {
        header << QString("第%1次成绩").arg(i);
    }
    header << "期末成绩";

    ui->tb_tea->setColumnCount(header.size());
    ui->tb_tea->setHorizontalHeaderLabels(header);

    //显示数据到表格中
    for (int row = 0; row < matchedTables.size(); row++) {
        const TableAttribute &table = matchedTables[row];
        ui->tb_tea->insertRow(row);
        ui->tb_tea->setItem(row,0, new QTableWidgetItem (table.getSelectedCourse()));
        ui->tb_tea->setItem(row,1, new QTableWidgetItem (table.getStudentId()));
        ui->tb_tea->setItem(row,2, new QTableWidgetItem (table.getStudentName()));
        ui->tb_tea->setItem(row,3, new QTableWidgetItem (table.getClassName()));
        for (int i = 0 ; i < maxUnitGrades; i++) {
            QString grade = i < table.getUnitGrade().size() ? QString::number(table.getUnitGrade()[i]) : "无";
            ui->tb_tea->setItem(row, i + 4, new QTableWidgetItem (grade));
        }
        ui->tb_tea->setItem(row, 4 + maxUnitGrades, new QTableWidgetItem (QString::number(table.getFinalGrade())));
    }

}

