#include "mainwindow.h"
#include "page_login.h"
#include "global.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    initProjectRoot();
    QApplication a(argc, argv);
     MainWindow w;

    return a.exec();
}
