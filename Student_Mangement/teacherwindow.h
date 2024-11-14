#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

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
    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

private:
    Ui::TeacherWindow *ui;
};

#endif // TEACHERWINDOW_H
