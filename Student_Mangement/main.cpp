#include "mainwindow.h"
#include "page_login.h"
#include "global.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    initProjectRoot(); //初始化文件路径
    initFilePath();
    QApplication a(argc, argv);
     MainWindow w;

    return a.exec();
}
