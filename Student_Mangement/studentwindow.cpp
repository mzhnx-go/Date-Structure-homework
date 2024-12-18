 #include "studentwindow.h"
#include "ui_studentwindow.h"
#include <QTreeWidget>
#include <QApplication>
StudentWindow::StudentWindow(QWidget *parent,QString studentId)
    : QWidget(parent)
    , ui(new Ui::StudentWindow)
    ,_optionCourse(nullptr)
    ,studentId(studentId)
{
    ui->setupUi(this);
    initCurrentStudent();
}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow::setStudentId(QString studentId)
{
    this->studentId = studentId;
}

Student& StudentWindow::getCurrentStudent() {
    return currentStudent;
}

void StudentWindow::initCurrentStudent()
{
    QVector<Student> students;
    if(!FileHandler::loadStudent(stuFilePath, students)) {
        qWarning() << "ERROR IN void StudentWindow::initCurrentStudent(): 加载学生数据失败";
        return ;
    }
    for (const auto &student: students ) {
        if (studentId == student.getId()) {
            currentStudent = student;
            qDebug() << "currentStudent初始化成功";
            return;
        }
    }
    qDebug() << "currentStudent初始化失败";
}

void StudentWindow::on_exit_clicked()
{
     QApplication::quit();
}


void StudentWindow::on_show_course_clicked()
{
    if (!_optionCourse) {
        _optionCourse = new show_optional_course(this,getCurrentStudent());
    }
    _optionCourse->exec(); // 模态对话框
}


void StudentWindow::on_searchStu_clicked()
{
    qDebug() << studentId;
    qDebug() << currentStudent.getCourses();
}

