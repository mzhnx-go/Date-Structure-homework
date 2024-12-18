#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QWidget>
#include "show_optional_course.h"
#include <QSet>
#include <QVector>
#include "user/student.h"


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

private:
    Ui::StudentWindow *ui;
    QString studentId; //学号
    show_optional_course *_optionCourse;
    QSet<QString> selected_courseId; //该学生选择的课程号
    Student currentStudent;
};

#endif // STUDENTWINDOW_H
