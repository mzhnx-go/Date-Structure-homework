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
    QLabel *title;
    QWidget *widget_5;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *username;
    QPushButton *exit;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *modify;
    QSpacerItem *horizontalSpacer;
    QPushButton *display;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *delete_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *inputText;
    QSpacerItem *horizontalSpacer_4;
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
        StudentWindow->resize(1181, 698);
        StudentWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        gridLayout_3 = new QGridLayout(StudentWindow);
        gridLayout_3->setObjectName("gridLayout_3");
        widget = new QWidget(StudentWindow);
        widget->setObjectName("widget");
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 0, 1144, 644));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(11, 11, 1196, 81));
        widget_3->setMinimumSize(QSize(1081, 80));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 191, 255);"));
        widget_4 = new QWidget(widget_3);
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

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(910, 10, 181, 61));
        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(30, 0, 131, 50));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(82, 147, 255);"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        username = new QLabel(widget_6);
        username->setObjectName("username");

        horizontalLayout_4->addWidget(username);

        exit = new QPushButton(widget_6);
        exit->setObjectName("exit");
        exit->setMaximumSize(QSize(60, 60));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        exit->setFont(font1);
        exit->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 57, 255);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(exit);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(20, 100, 931, 50));
        horizontalLayout_3 = new QHBoxLayout(widget_7);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        modify = new QPushButton(widget_7);
        modify->setObjectName("modify");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/\344\277\256\346\224\271.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        modify->setIcon(icon);

        horizontalLayout_3->addWidget(modify);

        horizontalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        display = new QPushButton(widget_7);
        display->setObjectName("display");
        display->setStyleSheet(QString::fromUtf8("padding-left: -0px\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\345\210\267\346\226\260.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        display->setIcon(icon1);

        horizontalLayout_3->addWidget(display);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        delete_2 = new QPushButton(widget_7);
        delete_2->setObjectName("delete_2");
        delete_2->setStyleSheet(QString::fromUtf8("padding-left: -20px;\n"
"        icon-align: left;   \n"
" background-color: lightgray;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/\345\210\240\351\231\244.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        delete_2->setIcon(icon2);
        delete_2->setIconSize(QSize(40, 20));

        horizontalLayout_3->addWidget(delete_2);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        inputText = new QLineEdit(widget_7);
        inputText->setObjectName("inputText");

        horizontalLayout_3->addWidget(inputText);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        searchStu = new QPushButton(widget_7);
        searchStu->setObjectName("searchStu");
        searchStu->setStyleSheet(QString::fromUtf8("padding-left: -10px"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("res/\346\237\245\346\211\276.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchStu->setIcon(icon3);
        searchStu->setIconSize(QSize(40, 30));

        horizontalLayout_3->addWidget(searchStu);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        inputCor = new QLineEdit(widget_7);
        inputCor->setObjectName("inputCor");
        inputCor->setReadOnly(false);

        horizontalLayout_3->addWidget(inputCor);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        searchCor = new QPushButton(widget_7);
        searchCor->setObjectName("searchCor");
        searchCor->setStyleSheet(QString::fromUtf8("padding-left: -10px"));
        searchCor->setIcon(icon3);
        searchCor->setIconSize(QSize(40, 30));

        horizontalLayout_3->addWidget(searchCor);

        tableWidget = new QTableWidget(widget_2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 150, 991, 501));

        gridLayout_3->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(StudentWindow);

        QMetaObject::connectSlotsByName(StudentWindow);
    } // setupUi

    void retranslateUi(QWidget *StudentWindow)
    {
        StudentWindow->setWindowTitle(QCoreApplication::translate("StudentWindow", "Form", nullptr));
        title->setText(QCoreApplication::translate("StudentWindow", "\345\255\246\347\224\237\346\210\220\347\273\251\347\256\241\347\220\206\347\263\273\347\273\237(\345\255\246\347\224\237\347\225\214\351\235\242)", nullptr));
        username->setText(QCoreApplication::translate("StudentWindow", "admin", nullptr));
        exit->setText(QCoreApplication::translate("StudentWindow", "\351\200\200\345\207\272", nullptr));
        modify->setText(QCoreApplication::translate("StudentWindow", "\344\277\256\346\224\271\346\210\220\347\273\251", nullptr));
        display->setText(QCoreApplication::translate("StudentWindow", "\346\230\276\347\244\272\346\210\220\347\273\251", nullptr));
        delete_2->setText(QCoreApplication::translate("StudentWindow", "\345\210\240\351\231\244", nullptr));
        inputText->setPlaceholderText(QCoreApplication::translate("StudentWindow", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267\346\210\226\345\247\223\345\220\215", nullptr));
        searchStu->setText(QCoreApplication::translate("StudentWindow", "\346\237\245\346\211\276", nullptr));
        inputCor->setPlaceholderText(QCoreApplication::translate("StudentWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\344\277\256\350\257\276", nullptr));
        searchCor->setText(QCoreApplication::translate("StudentWindow", "\346\237\245\347\234\213\351\200\211\344\277\256\350\257\276\346\210\220\347\273\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentWindow: public Ui_StudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
