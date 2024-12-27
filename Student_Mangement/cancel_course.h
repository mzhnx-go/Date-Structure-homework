#ifndef CANCEL_COURSE_H
#define CANCEL_COURSE_H

#include <QDialog>
#include "user/student.h"
#include "filehandler.h"
#include "global.h"
#include <QItemSelection>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class cancel_course;
}

class cancel_course : public QDialog
{
    Q_OBJECT

public:
    explicit cancel_course(QWidget *parent, Student &student);
    ~cancel_course();
    void refreshData();

private slots:
    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

    void on_cancel_choice_clicked();

    void on_sure_choice_clicked();

private:
    Ui::cancel_course *ui;
    Student &currentStudent;
    QStandardItemModel *model;
    QVector<Course> courses;
     void loadSelectedCourses();
    void initData();
     QVector<Score> scores;
    QVector<OptionCourse> optionCourses;
     QVector<Student> students;
};

#endif // CANCEL_COURSE_H
