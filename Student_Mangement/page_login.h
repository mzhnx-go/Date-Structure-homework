#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <iostream>
namespace Ui {
class Page_login;
}

class Page_login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_login(QWidget *parent = nullptr);
      ~Page_login();
    enum UserType {Teacher, Student, Invaild};
private slots:
    void on_btn_login_clicked();

    void on_btn_exit_clicked();


private:
    Ui::Page_login *ui;
    UserType userType;
    bool isStudent(const QString &username, const QString &password);
    bool isTeacher(const QString &username, const QString &password);
signals:
    void sendLoginSuccess(UserType userType, QString usersId); //添加用户类型参数，比如学生和老师
};



#endif // PAGE_LOGIN_H
