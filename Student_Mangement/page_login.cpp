#include "page_login.h"
#include "ui_page_login.h"
#include <filehandler.h>
#include <global.h>
#include <QMap>
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
    bool loginSuccess = false;
    if (isStudent(username, password)) {
        userType = Student;
        loginSuccess = true;
    } else if (isTeacher(username, password)) {
        userType = Teacher;
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
    // 登录成功，执行相应操作
    QMessageBox::information(this, "登录成功", "欢迎您！");
    emit sendLoginSuccess(userType, username);
    this->close();

}


void Page_login::on_btn_exit_clicked()
{

    //退出
    qApp->quit();
}

//查找是否为学生
bool Page_login::isStudent(const QString &username, const QString &password)
{
    QMap<QString ,QString> stuUsers; // account, password
    if (!FileHandler::loadUsers(stuUserFilePath, stuUsers)) {
        qWarning() << "ERROR IN page_login:无法打开学生用户数据";
    }

    for (auto it = stuUsers.cbegin(); it != stuUsers.end(); it++) {
        if (it.key() == username && it.value() == password) {
            return true;
        }
    }
    return false;
}

bool Page_login::isTeacher(const QString &username, const QString &password)
{
    QMap<QString, QString> teacherUsers;
    if (!FileHandler::loadUsers(teacherUserFilePath, teacherUsers)) {
        qWarning() << "ERROR IN page_login:无法打开教师用户数据";
    }

    for (auto it = teacherUsers.cbegin(); it != teacherUsers.cend(); it++) {
        if (it.key() == username && it.value() == password) {
            return true;
        }
    }
    return false;
}



