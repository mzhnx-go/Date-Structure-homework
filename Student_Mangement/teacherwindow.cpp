#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
TeacherWindow::TeacherWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
    //没必要使用QTree
    // QTreeWidget *treeWidget = ui->treeWidget;
    // QStringList l;
    // l<<"选择您的身份";
    // //创建根节点分支
    // QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget, l); //父对象为treeWidget
    // treeWidget->addTopLevelItem(root);
    // l.clear();
    // l<<"学生使用界面";
    // QTreeWidgetItem *forStudent = new QTreeWidgetItem(root, l);

    // l.clear();
    // l<<"教师使用界面";
    // QTreeWidgetItem *forTeacher = new QTreeWidgetItem(root, l);

    // treeWidget->expandAll(); //设置默认展开
}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}

void TeacherWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{

}

