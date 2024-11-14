/********************************************************************************
** Form generated from reading UI file 'teacherwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERWINDOW_H
#define UI_TEACHERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherWindow
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QWidget *widget_2;
    QWidget *widget_4;
    QLabel *tital;
    QWidget *widget_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *username;
    QPushButton *exit;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *TeacherWindow)
    {
        if (TeacherWindow->objectName().isEmpty())
            TeacherWindow->setObjectName("TeacherWindow");
        TeacherWindow->resize(1166, 666);
        TeacherWindow->setMinimumSize(QSize(400, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bana.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        TeacherWindow->setWindowIcon(icon);
        TeacherWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(199, 255, 251);"));
        gridLayout_2 = new QGridLayout(TeacherWindow);
        gridLayout_2->setObjectName("gridLayout_2");
        widget = new QWidget(TeacherWindow);
        widget->setObjectName("widget");
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(197, 90, 981, 551));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(214, 255, 234);"));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(11, 11, 1196, 80));
        widget_2->setMinimumSize(QSize(1081, 80));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 191, 255);"));
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(350, 0, 311, 80));
        tital = new QLabel(widget_4);
        tital->setObjectName("tital");
        tital->setGeometry(QRect(50, 10, 261, 51));
        QFont font;
        font.setPointSize(16);
        tital->setFont(font);
        tital->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(910, 10, 181, 61));
        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(30, 0, 131, 50));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(82, 147, 255);"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        username = new QLabel(widget_3);
        username->setObjectName("username");

        horizontalLayout_4->addWidget(username);

        exit = new QPushButton(widget_3);
        exit->setObjectName("exit");
        exit->setMaximumSize(QSize(60, 60));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        exit->setFont(font1);
        exit->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 57, 255);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(exit);

        treeWidget = new QTreeWidget(widget);
        treeWidget->headerItem()->setText(0, QString());
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(11, 98, 181, 541));
        treeWidget->setMinimumSize(QSize(181, 541));
        treeWidget->setMaximumSize(QSize(181, 541));
        treeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(176, 255, 214);\n"
"border-top-color: rgb(170, 255, 0);"));

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(TeacherWindow);

        QMetaObject::connectSlotsByName(TeacherWindow);
    } // setupUi

    void retranslateUi(QWidget *TeacherWindow)
    {
        TeacherWindow->setWindowTitle(QCoreApplication::translate("TeacherWindow", "\350\200\201\345\270\210\346\237\245\350\257\242\347\252\227\345\217\243", nullptr));
        tital->setText(QCoreApplication::translate("TeacherWindow", "\345\255\246\347\224\237\346\210\220\347\273\251\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        username->setText(QCoreApplication::translate("TeacherWindow", "admin", nullptr));
        exit->setText(QCoreApplication::translate("TeacherWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherWindow: public Ui_TeacherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWINDOW_H
