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

class Ui_StudentWindow
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QWidget *widget_6;
    QWidget *widget_7;
    QLabel *label_5;
    QWidget *widget_8;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QWidget *page_4;
    QLabel *label_4;
    QTreeWidget *treeWidget_2;

    void setupUi(QWidget *StudentWindow)
    {
        if (StudentWindow->objectName().isEmpty())
            StudentWindow->setObjectName("StudentWindow");
        StudentWindow->resize(1181, 653);
        gridLayout_3 = new QGridLayout(StudentWindow);
        gridLayout_3->setObjectName("gridLayout_3");
        widget = new QWidget(StudentWindow);
        widget->setObjectName("widget");
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        widget_6 = new QWidget(widget);
        widget_6->setObjectName("widget_6");
        widget_6->setMinimumSize(QSize(1081, 80));
        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(350, 0, 311, 80));
        label_5 = new QLabel(widget_7);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 10, 261, 51));
        QFont font;
        font.setPointSize(16);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget_8 = new QWidget(widget_6);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(910, 10, 181, 61));
        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(30, 0, 131, 50));
        horizontalLayout_5 = new QHBoxLayout(widget_9);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(widget_9);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        pushButton_2 = new QPushButton(widget_9);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMaximumSize(QSize(60, 60));

        horizontalLayout_5->addWidget(pushButton_2);


        gridLayout_2->addWidget(widget_6, 0, 0, 1, 1);

        stackedWidget_2 = new QStackedWidget(widget);
        stackedWidget_2->setObjectName("stackedWidget_2");
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        stackedWidget_2->addWidget(page_4);

        gridLayout_2->addWidget(stackedWidget_2, 3, 1, 1, 2);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 1, 2, 1, 1);

        treeWidget_2 = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget_2->setHeaderItem(__qtreewidgetitem);
        treeWidget_2->setObjectName("treeWidget_2");
        treeWidget_2->setMinimumSize(QSize(181, 541));
        treeWidget_2->setMaximumSize(QSize(181, 541));

        gridLayout_2->addWidget(treeWidget_2, 3, 0, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(StudentWindow);

        QMetaObject::connectSlotsByName(StudentWindow);
    } // setupUi

    void retranslateUi(QWidget *StudentWindow)
    {
        StudentWindow->setWindowTitle(QCoreApplication::translate("StudentWindow", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("StudentWindow", "\345\255\246\347\224\237\346\210\220\347\273\251\347\263\273\347\273\237", nullptr));
        label_6->setText(QCoreApplication::translate("StudentWindow", "admin", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StudentWindow", "\351\200\200\345\207\272", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StudentWindow: public Ui_StudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
