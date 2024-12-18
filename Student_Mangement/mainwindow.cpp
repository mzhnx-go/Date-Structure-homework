#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , teacherWindow(nullptr)
    , studentWindow(nullptr)
{
    ui->setupUi(this);

    connect(&m_dlgLogin, &Page_login::sendLoginSuccess, this, &MainWindow::handleLoginSuccess); //连接信号和槽
    m_dlgLogin.show();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete teacherWindow; //清理教师窗口
    delete studentWindow; //清理学生窗口
}

void MainWindow::handleLoginSuccess(Page_login::UserType userType, QString usersId) {
    // 处理登录成功的情况
    if (userType == Page_login::Teacher) {
        if (teacherWindow && !teacherWindow->isVisible()) {
            teacherWindow->show();
        } else {
            teacherWindow = new TeacherWindow();
            teacherWindow->show();
        }
        studentWindow = nullptr; // 关闭并释放学生窗口对象
    } else if (userType == Page_login::Student) {
        if (studentWindow && !studentWindow->isVisible()) {
            studentWindow->setStudentId(usersId);
            studentWindow->show();
        } else {
            studentWindow = new StudentWindow(nullptr, usersId);
            studentWindow->show();
        }
        teacherWindow = nullptr; // 关闭并释放教师窗口对象
    } else {
        QMessageBox::warning(this, "登录失败", "无效的账号或密码");
    }
}
