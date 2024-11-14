#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
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



