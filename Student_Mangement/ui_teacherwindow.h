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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherWindow
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QLabel *title;
    QWidget *widget_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *username;
    QPushButton *exit;
    QTableWidget *tb_tea;
    QWidget *widget_6;
    QPushButton *modify;
    QPushButton *display;
    QPushButton *delete_2;
    QLineEdit *inputText;
    QPushButton *searchStu;
    QPushButton *searchCor;
    QLineEdit *lineEdit;

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
        widget = new QWidget(TeacherWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(11, 11, 1144, 644));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(11, 11, 1122, 80));
        widget_2->setMinimumSize(QSize(1081, 80));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 191, 255);"));
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(350, 10, 381, 61));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName("horizontalLayout");
        title = new QLabel(widget_4);
        title->setObjectName("title");
        QFont font;
        font.setPointSize(16);
        title->setFont(font);
        title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(title);

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

        tb_tea = new QTableWidget(widget);
        tb_tea->setObjectName("tableWidget");
        tb_tea->setGeometry(QRect(11, 152, 1051, 501));
        widget_6 = new QWidget(widget);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(0, 100, 1041, 47));
        modify = new QPushButton(widget_6);
        modify->setObjectName("modify");
        modify->setGeometry(QRect(50, 11, 90, 25));
        modify->setMinimumSize(QSize(50, 20));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/\344\277\256\346\224\271.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        modify->setIcon(icon1);
        display = new QPushButton(widget_6);
        display->setObjectName("display");
        display->setGeometry(QRect(160, 13, 90, 21));
        display->setStyleSheet(QString::fromUtf8("padding-left: -0px\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/\345\210\267\346\226\260.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        display->setIcon(icon2);
        delete_2 = new QPushButton(widget_6);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(270, 11, 70, 25));
        delete_2->setMinimumSize(QSize(60, 25));
        delete_2->setStyleSheet(QString::fromUtf8("padding-left: -20px;\n"
"        icon-align: left;   \n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/\345\210\240\351\231\244.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        delete_2->setIcon(icon3);
        delete_2->setIconSize(QSize(70, 20));
        inputText = new QLineEdit(widget_6);
        inputText->setObjectName("inputText");
        inputText->setGeometry(QRect(360, 11, 200, 25));
        searchStu = new QPushButton(widget_6);
        searchStu->setObjectName("searchStu");
        searchStu->setGeometry(QRect(580, 13, 70, 21));
        searchStu->setMinimumSize(QSize(40, 20));
        searchStu->setStyleSheet(QString::fromUtf8("padding-left: -10px"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("res/\346\237\245\346\211\276.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchStu->setIcon(icon4);
        searchStu->setIconSize(QSize(40, 30));
        searchCor = new QPushButton(widget_6);
        searchCor->setObjectName("searchCor");
        searchCor->setGeometry(QRect(933, 13, 120, 21));
        searchCor->setMaximumSize(QSize(16777, 16777215));
        searchCor->setStyleSheet(QString::fromUtf8("padding-left: -10px"));
        searchCor->setIcon(icon4);
        searchCor->setIconSize(QSize(40, 30));
        lineEdit = new QLineEdit(widget_6);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(680, 11, 230, 25));

        retranslateUi(TeacherWindow);

        QMetaObject::connectSlotsByName(TeacherWindow);
    } // setupUi

    void retranslateUi(QWidget *TeacherWindow)
    {
        TeacherWindow->setWindowTitle(QCoreApplication::translate("TeacherWindow", "\350\200\201\345\270\210\346\237\245\350\257\242\347\252\227\345\217\243", nullptr));
        title->setText(QCoreApplication::translate("TeacherWindow", "\345\255\246\347\224\237\346\210\220\347\273\251\347\256\241\347\220\206\347\263\273\347\273\237(\346\225\231\345\270\210\347\225\214\351\235\242\357\274\211", nullptr));
        username->setText(QCoreApplication::translate("TeacherWindow", "admin", nullptr));
        exit->setText(QCoreApplication::translate("TeacherWindow", "\351\200\200\345\207\272", nullptr));
        modify->setText(QCoreApplication::translate("TeacherWindow", "\344\277\256\346\224\271\346\210\220\347\273\251", nullptr));
        display->setText(QCoreApplication::translate("TeacherWindow", "\346\230\276\347\244\272\346\210\220\347\273\251", nullptr));
        delete_2->setText(QCoreApplication::translate("TeacherWindow", "\345\210\240\351\231\244", nullptr));
        inputText->setPlaceholderText(QCoreApplication::translate("TeacherWindow", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267\346\210\226\345\247\223\345\220\215", nullptr));
        searchStu->setText(QCoreApplication::translate("TeacherWindow", "\346\237\245\346\211\276", nullptr));
        searchCor->setText(QCoreApplication::translate("TeacherWindow", "\346\237\245\347\234\213\351\200\211\344\277\256\350\257\276\346\210\220\347\273\251", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("TeacherWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\344\277\256\350\257\276\345\220\215\345\255\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherWindow: public Ui_TeacherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWINDOW_H
