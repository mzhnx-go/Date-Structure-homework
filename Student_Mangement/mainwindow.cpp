#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_dlgLogin.show();
    auto f = [&]() {
        this->show();
    };
    connect(&m_dlgLogin, &Page_login::sendLoginSuccess, this, f);
}

MainWindow::~MainWindow()
{
    delete ui;
}
