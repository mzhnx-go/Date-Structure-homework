/********************************************************************************
** Form generated from reading UI file 'page_modify.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_MODIFY_H
#define UI_PAGE_MODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page_modify
{
public:
    QWidget *widget_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *stu_text;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *cou_text;
    QLabel *label_3;
    QPushButton *show_button;
    QLabel *label_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *sure_button;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QTableWidget *modi_tab;

    void setupUi(QDialog *page_modify)
    {
        if (page_modify->objectName().isEmpty())
            page_modify->setObjectName("page_modify");
        page_modify->resize(514, 486);
        widget_4 = new QWidget(page_modify);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(10, 10, 501, 461));
        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(9, 34, 471, 59));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        widget = new QWidget(widget_3);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        stu_text = new QLineEdit(widget);
        stu_text->setObjectName("stu_text");

        horizontalLayout->addWidget(stu_text);


        horizontalLayout_3->addWidget(widget);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        cou_text = new QLineEdit(widget_2);
        cou_text->setObjectName("cou_text");

        horizontalLayout_2->addWidget(cou_text);


        horizontalLayout_3->addWidget(widget_2);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 10, 80, 19));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        label_3->setFont(font);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";\n"
"color: rgb(0, 170, 255);"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        show_button = new QPushButton(widget_4);
        show_button->setObjectName("show_button");
        show_button->setGeometry(QRect(210, 100, 80, 23));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 150, 471, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"color: rgb(0, 0, 0);"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(20, 350, 441, 41));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        sure_button = new QPushButton(widget_5);
        sure_button->setObjectName("sure_button");

        horizontalLayout_4->addWidget(sure_button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(widget_5);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_4->addWidget(pushButton_3);

        modi_tab = new QTableWidget(widget_4);
        modi_tab->setObjectName("modi_tab");
        modi_tab->setGeometry(QRect(-5, 180, 501, 161));

        retranslateUi(page_modify);

        QMetaObject::connectSlotsByName(page_modify);
    } // setupUi

    void retranslateUi(QDialog *page_modify)
    {
        page_modify->setWindowTitle(QCoreApplication::translate("page_modify", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("page_modify", "\345\255\246\345\217\267", nullptr));
        stu_text->setText(QString());
        stu_text->setPlaceholderText(QCoreApplication::translate("page_modify", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267\346\210\226\345\255\246\347\224\237\345\220\215\345\255\227", nullptr));
        label_2->setText(QCoreApplication::translate("page_modify", "\350\257\276\347\250\213\345\217\267", nullptr));
        cou_text->setText(QString());
        cou_text->setPlaceholderText(QCoreApplication::translate("page_modify", "\350\257\267\350\276\223\345\205\245\350\257\276\347\250\213\345\217\267\346\210\226\350\257\276\347\250\213\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("page_modify", "\344\277\256\346\224\271\346\210\220\347\273\251", nullptr));
        show_button->setText(QCoreApplication::translate("page_modify", "\346\230\276\347\244\272\346\210\220\347\273\251\346\225\260\346\215\256", nullptr));
        label_4->setText(QCoreApplication::translate("page_modify", "\350\257\267\345\234\250\350\241\250\346\240\274\344\270\255\344\277\256\346\224\271\346\210\220\347\273\251\346\225\260\346\215\256\357\274\210\344\277\256\346\224\271\346\227\266\350\257\267\346\214\211\344\270\213\345\233\236\350\275\246\357\274\211", nullptr));
        sure_button->setText(QCoreApplication::translate("page_modify", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        pushButton_3->setText(QCoreApplication::translate("page_modify", "\345\217\226\346\266\210\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page_modify: public Ui_page_modify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_MODIFY_H
