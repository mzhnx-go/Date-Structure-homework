#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include "global.h"
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


//TODO::修改score文件让它存储课程Id
/*
*功能: 用于显示学生数据基本数据和成绩
*/
void TeacherWindow::on_display_clicked()
{
    if (!FileHandler::loadStudent(stuFilePath, students)) {
        qWarning() << "无法打开学生数据";
    }
    if (!FileHandler::loadCourses(coursesFilePath, courses)) {
        qWarning() << "无法打开课程数据";
    }
    if ( !FileHandler::loadScores(stuFilePath, scores)) {
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
        scoreMap[{score.getStudentId(), score.getCourseId()}] = score;
    }
    for (const auto &course: courses) {
        courseIdMap[course.getCourseId()] = course;
    }

    QStringList header;
    header << "学号" << "姓名" << "班级" << "所选课程" << "第一次成绩" << "二" << "三" << "四" << "五" << "六" << "期末成绩";
    ui->tb_tea->setColumnCount(header.size());
    ui->tb_tea->setHorizontalHeaderLabels(header);
}

