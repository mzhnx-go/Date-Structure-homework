#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H
#include "filehandler.h"
#include "page_modify.h"
#include <QWidget>

namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherWindow(QWidget *parent = nullptr);
    ~TeacherWindow();

private slots:

    void on_display_clicked();

    void on_searchStu_clicked();

    void on_exit_clicked();

    void on_searchCor_clicked();

    void on_modify_clicked();

private:
    Ui::TeacherWindow *ui;
    page_modify *modifyDialog;


};

#endif // TEACHERWINDOW_H
