#include "studentwindow.h"
#include "ui_studentwindow.h"
#include <QTreeWidget>
StudentWindow::StudentWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
}

StudentWindow::~StudentWindow()
{
    delete ui;
}
