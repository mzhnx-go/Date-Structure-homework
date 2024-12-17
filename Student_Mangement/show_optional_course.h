#ifndef SHOW_OPTIONAL_COURSE_H
#define SHOW_OPTIONAL_COURSE_H

#include <QDialog>
#include <show_optional_course.h>
#include "user/optioncourse.h"
#include "user/course.h"
#include "filehandler.h"
#include "global.h"
#include "utils.h"
#include <QDebug>
#include <QMap>
#include <QPair>
#include <QStandardItemModel>
#include <QVector>
#include <QItemSelection>
#include <QMessageBox>
#include "user/student.h"
namespace Ui {
class show_optional_course;
}

class show_optional_course : public QDialog
{
    Q_OBJECT

public:
    explicit show_optional_course(QWidget *parent,Student &student);
    ~show_optional_course();

private slots:
    void on_pushButton_2_clicked();
    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void on_sure_choice_clicked();

private:
    Ui::show_optional_course *ui;
    QVector<Course> courses;
    QVector<OptionCourse> optionCourses; //可选课程的对象数组
    QMap<QString, QPair<Course, OptionCourse>> mapCourses; //课程号匹配课程
    QStandardItemModel *model;
    QVector<int> selectedIndexes;
    Student &currentStudent;
    void loadCourses();
    bool initDatas();
};

#endif // SHOW_OPTIONAL_COURSE_H

