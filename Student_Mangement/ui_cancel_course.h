/********************************************************************************
** Form generated from reading UI file 'cancel_course.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANCEL_COURSE_H
#define UI_CANCEL_COURSE_H

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

class Ui_cancel_course
{
public:
    QLabel *label;
    QListView *cancel_view;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *sure_choice;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_choice;

    void setupUi(QDialog *cancel_course)
    {
        if (cancel_course->objectName().isEmpty())
            cancel_course->setObjectName("cancel_course");
        cancel_course->resize(353, 530);
        label = new QLabel(cancel_course);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 10, 231, 61));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\273\221\344\275\223\";\n"
"color: rgb(255, 85, 127);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        cancel_view = new QListView(cancel_course);
        cancel_view->setObjectName("cancel_view");
        cancel_view->setGeometry(QRect(30, 80, 281, 341));
        widget = new QWidget(cancel_course);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 440, 311, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        sure_choice = new QPushButton(widget);
        sure_choice->setObjectName("sure_choice");

        horizontalLayout->addWidget(sure_choice);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel_choice = new QPushButton(widget);
        cancel_choice->setObjectName("cancel_choice");

        horizontalLayout->addWidget(cancel_choice);


        retranslateUi(cancel_course);

        QMetaObject::connectSlotsByName(cancel_course);
    } // setupUi

    void retranslateUi(QDialog *cancel_course)
    {
        cancel_course->setWindowTitle(QCoreApplication::translate("cancel_course", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("cancel_course", "\351\200\200\351\200\211\350\257\276\347\250\213", nullptr));
        sure_choice->setText(QCoreApplication::translate("cancel_course", "\347\241\256\345\256\232\351\200\200\351\200\211", nullptr));
        cancel_choice->setText(QCoreApplication::translate("cancel_course", "\345\217\226\346\266\210\351\200\200\351\200\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cancel_course: public Ui_cancel_course {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANCEL_COURSE_H
