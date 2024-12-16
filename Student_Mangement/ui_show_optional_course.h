/********************************************************************************
** Form generated from reading UI file 'show_optional_course.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_OPTIONAL_COURSE_H
#define UI_SHOW_OPTIONAL_COURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_show_optional_course
{
public:
    QListView *list_course;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QDialog *show_optional_course)
    {
        if (show_optional_course->objectName().isEmpty())
            show_optional_course->setObjectName("show_optional_course");
        show_optional_course->resize(394, 486);
        list_course = new QListView(show_optional_course);
        list_course->setObjectName("list_course");
        list_course->setGeometry(QRect(40, 70, 311, 331));
        label = new QLabel(show_optional_course);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 321, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(show_optional_course);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(33, 420, 311, 42));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(show_optional_course);

        QMetaObject::connectSlotsByName(show_optional_course);
    } // setupUi

    void retranslateUi(QDialog *show_optional_course)
    {
        show_optional_course->setWindowTitle(QCoreApplication::translate("show_optional_course", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("show_optional_course", "\351\200\211\346\213\251\350\257\276\347\250\213", nullptr));
        pushButton->setText(QCoreApplication::translate("show_optional_course", "\347\241\256\345\256\232\351\200\211\346\213\251", nullptr));
        pushButton_2->setText(QCoreApplication::translate("show_optional_course", "\345\217\226\346\266\210\351\200\211\346\213\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class show_optional_course: public Ui_show_optional_course {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_OPTIONAL_COURSE_H
