#include "students.h"
#include "ui_students.h"

Students::Students(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Students)
{
    ui->setupUi(this);
}

Students::~Students()
{
    delete ui;
}
