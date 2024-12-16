 #include "studentwindow.h"
#include "ui_studentwindow.h"
#include <QTreeWidget>
#include <QApplication>
StudentWindow::StudentWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentWindow)
    ,_optionCourse(nullptr)
{
    ui->setupUi(this);
}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow::setStudentId(QString studentId)
{
    this->studentId = studentId;
}

void StudentWindow::on_exit_clicked()
{
     QApplication::quit();
}


void StudentWindow::on_show_course_clicked()
{
    if (!_optionCourse) {
        _optionCourse = new show_optional_course(this);
    }
    _optionCourse->exec(); // 模态对话框
}

