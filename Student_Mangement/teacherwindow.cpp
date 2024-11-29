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

