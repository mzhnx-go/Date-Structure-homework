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

void MainWindow::handleLoginSuccess(Page_login::UserType userType) {
    //处理登录成功的情况
    if (teacherWindow) {
        //如果老师窗口已存在，删除，然后创建新的
        delete teacherWindow;
    }
    if (studentWindow) {
        //同理
        delete studentWindow;
    }
    if (userType == Page_login::Teacher) {
        teacherWindow = new TeacherWindow(); //不要加this，不然无法弹出界面
        teacherWindow->show();
    } else if (userType == Page_login::Student) {
        studentWindow = new StudentWindow();
        studentWindow->show();
    }else {
       QMessageBox::warning(this, "登录失败", "无效的账号或密码");
    }
}
