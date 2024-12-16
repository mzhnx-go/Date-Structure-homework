#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Page_login.h"
#include "TeacherWindow.h"
#include "StudentWindow.h"
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleLoginSuccess(Page_login::UserType userType, QString usersId);

private:
    Ui::MainWindow *ui;
    Page_login m_dlgLogin; //将登录界面设置为成员变量，以便于控制生命周期
    TeacherWindow *teacherWindow;//教师界面窗口函数指针
    StudentWindow *studentWindow;//学生界面窗口函数指针
};

#endif // MAINWINDOW_H
