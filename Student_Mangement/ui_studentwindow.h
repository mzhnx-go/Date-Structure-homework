/********************************************************************************
** Form generated from reading UI file 'studentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTWINDOW_H
#define UI_STUDENTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentWindow
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_5;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *username;
    QPushButton *exit;
    QLabel *title;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *show_course;
    QSpacerItem *horizontalSpacer;
    QPushButton *display;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *searchStu;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *inputCor;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *searchCor;
    QTableWidget *tableWidget;

    void setupUi(QWidget *StudentWindow)
    {
        if (StudentWindow->objectName().isEmpty())
            StudentWindow->setObjectName("StudentWindow");
        StudentWindow->resize(826, 498);
        StudentWindow->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(StudentWindow);
        gridLayout_3->setObjectName("gridLayout_3");
        widget = new QWidget(StudentWindow);
        widget->setObjectName("widget");
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 0, 801, 491));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(11, 11, 1196, 81));
        widget_3->setMinimumSize(QSize(1081, 80));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 191, 255);"));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(350, 10, 141, 61));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(910, 10, 181, 61));
        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(630, 10, 141, 50));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(82, 147, 255);"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        username = new QLabel(widget_6);
        username->setObjectName("username");

        horizontalLayout_4->addWidget(username);

        exit = new QPushButton(widget_6);
        exit->setObjectName("exit");
        exit->setMaximumSize(QSize(60, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        exit->setFont(font);
        exit->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 57, 255);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(exit);

        title = new QLabel(widget_3);
        title->setObjectName("title");
        title->setGeometry(QRect(150, 20, 363, 43));
        QFont font1;
        font1.setPointSize(16);
        title->setFont(font1);
        title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(20, 99, 751, 51));
        horizontalLayout_3 = new QHBoxLayout(widget_7);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        show_course = new QPushButton(widget_7);
        show_course->setObjectName("show_course");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/\344\277\256\346\224\271.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        show_course->setIcon(icon);

        horizontalLayout_3->addWidget(show_course);

        horizontalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        display = new QPushButton(widget_7);
        display->setObjectName("display");
        display->setMinimumSize(QSize(80, 0));
        display->setStyleSheet(QString::fromUtf8("padding-left: -0px\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\345\210\267\346\226\260.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        display->setIcon(icon1);

        horizontalLayout_3->addWidget(display);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        searchStu = new QPushButton(widget_7);
        searchStu->setObjectName("searchStu");
        searchStu->setMinimumSize(QSize(90, 0));
        searchStu->setStyleSheet(QString::fromUtf8("padding-left: -10px"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("res/\346\237\245\346\211\276.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchStu->setIcon(icon2);
        searchStu->setIconSize(QSize(40, 30));

        horizontalLayout_3->addWidget(searchStu);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        inputCor = new QLineEdit(widget_7);
        inputCor->setObjectName("inputCor");
        inputCor->setMinimumSize(QSize(120, 0));
        inputCor->setReadOnly(false);

        horizontalLayout_3->addWidget(inputCor);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        searchCor = new QPushButton(widget_7);
        searchCor->setObjectName("searchCor");
        searchCor->setMinimumSize(QSize(100, 0));
        searchCor->setStyleSheet(QString::fromUtf8(""));
        searchCor->setIcon(icon2);
        searchCor->setIconSize(QSize(40, 30));

        horizontalLayout_3->addWidget(searchCor);

        tableWidget = new QTableWidget(widget_2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 150, 751, 311));

        gridLayout_3->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(StudentWindow);

        QMetaObject::connectSlotsByName(StudentWindow);
    } // setupUi

    void retranslateUi(QWidget *StudentWindow)
    {
        StudentWindow->setWindowTitle(QCoreApplication::translate("StudentWindow", "Form", nullptr));
        username->setText(QCoreApplication::translate("StudentWindow", "admin", nullptr));
        exit->setText(QCoreApplication::translate("StudentWindow", "\351\200\200\345\207\272", nullptr));
        title->setText(QCoreApplication::translate("StudentWindow", "\345\255\246\347\224\237\346\210\220\347\273\251\347\256\241\347\220\206\347\263\273\347\273\237(\345\255\246\347\224\237\347\225\214\351\235\242)", nullptr));
        show_course->setText(QCoreApplication::translate("StudentWindow", "\346\230\276\347\244\272\345\217\257\351\200\211\350\257\276\347\250\213", nullptr));
        display->setText(QCoreApplication::translate("StudentWindow", "\351\200\200\351\200\211\345\267\262\351\200\211\350\257\276\347\250\213", nullptr));
        searchStu->setText(QCoreApplication::translate("StudentWindow", "\346\237\245\350\257\242\346\211\200\351\200\211\350\257\276\347\250\213", nullptr));
        inputCor->setPlaceholderText(QCoreApplication::translate("StudentWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\344\277\256\350\257\276\345\220\215\345\255\227", nullptr));
        searchCor->setText(QCoreApplication::translate("StudentWindow", "\346\237\245\347\234\213\346\211\200\351\200\211\350\257\276\347\250\213\346\210\220\347\273\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentWindow: public Ui_StudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
