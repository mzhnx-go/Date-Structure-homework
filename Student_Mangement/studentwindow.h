#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QWidget>
#include "show_optional_course.h"
#include <QSet>
#include <QVector>
#include "user/student.h"
#include "cancel_course.h"



//TODO::完成加载currentStudent

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = nullptr, QString studentId = "");
    ~StudentWindow();
    void setStudentId(QString studentId);
     Student& getCurrentStudent();
    void initCurrentStudent();


private slots:
    void on_exit_clicked();

    void on_show_course_clicked();

    void on_searchStu_clicked();

    void on_check_score_clicked();


    void on_cancel_course_clicked();

private:
    Ui::StudentWindow *ui;
    QString studentId; // 学号
    show_optional_course *_optionCourse = nullptr;
    QSet<QString> selected_courseId; // 该学生选择的课程号
    Student currentStudent;
    QVector<Course> courses;
    std::unique_ptr<cancel_course> _cancelCourse; // 使用智能指针管理 cancel_course 对象

    void loadData(); // 新增的数据加载方法
};

#endif // STUDENTWINDOW_H
