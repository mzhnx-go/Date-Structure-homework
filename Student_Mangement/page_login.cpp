#include "page_login.h"
#include "ui_page_login.h"
Page_login::Page_login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page_login)
{
    ui->setupUi(this);
}

Page_login::~Page_login()
{
    delete ui;
}

void Page_login::on_btn_login_clicked()
{   //文件查找用户名和密码
    QString username = ui->le_username->text(); //读取输入框用户名信息
    QString password = ui->le_password->text(); //读取输入框密码信息

    //TODO:: 完成查找匹配
    // bool loginSuccess = validateLogin(username, password);
    bool loginSuccess = false;
    //测试部分,检测能否进入两个不用界面
    if (username == "Teacher"){
        userType = Teacher;
        loginSuccess = true;
    } else if (username == "Student") {
        userType = Student;
        loginSuccess = true;
    }
    //失败就提示
    if (!loginSuccess) {
    QMessageBox::warning(this, "登录失败", "无效的账号或密码");
    ui->le_username->clear();
    ui->le_password->clear();
    ui->le_username->setFocus(); //设置焦点到输入框，当用户输入错误时，自动定位到输入框，不用鼠标点击
    return;
    }
    //成功就进入主界面

    // 登录成功，执行相应操作
    QMessageBox::information(this, "登录成功", "欢迎您！");
    emit sendLoginSuccess(userType);
    this->close();

}


void Page_login::on_btn_exit_clicked()
{

    //退出
    qApp->quit();
}

