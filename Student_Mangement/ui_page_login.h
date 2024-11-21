/********************************************************************************
** Form generated from reading UI file 'page_login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_LOGIN_H
#define UI_PAGE_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page_login
{
public:
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLineEdit *le_password;
    QLabel *label_3;
    QLabel *account;
    QLineEdit *le_username;
    QWidget *widget;
    QFormLayout *formLayout;
    QPushButton *btn_login;
    QPushButton *btn_exit;

    void setupUi(QWidget *Page_login)
    {
        if (Page_login->objectName().isEmpty())
            Page_login->setObjectName("Page_login");
        Page_login->resize(400, 376);
        Page_login->setMinimumSize(QSize(100, 100));
        Page_login->setMaximumSize(QSize(2000, 2000));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bana.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Page_login->setWindowIcon(icon);
        Page_login->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0\n"
"rgba(150,177,255,220), stop:1 rgba(238,204,218,220));\n"
""));
        widget_3 = new QWidget(Page_login);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(30, 50, 341, 281));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget_3);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 60));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        le_password = new QLineEdit(widget_2);
        le_password->setObjectName("le_password");
        le_password->setMaxLength(20);
        le_password->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(le_password, 1, 2, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        QFont font2;
        font2.setPointSize(12);
        label_3->setFont(font2);

        gridLayout->addWidget(label_3, 1, 0, 1, 2);

        account = new QLabel(widget_2);
        account->setObjectName("account");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(12);
        account->setFont(font3);

        gridLayout->addWidget(account, 0, 0, 1, 1);

        le_username = new QLineEdit(widget_2);
        le_username->setObjectName("le_username");
        le_username->setMinimumSize(QSize(30, 20));
        le_username->setToolTipDuration(1);
        le_username->setMaxLength(20);

        gridLayout->addWidget(le_username, 0, 1, 1, 2);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(widget_3);
        widget->setObjectName("widget");
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        btn_login = new QPushButton(widget);
        btn_login->setObjectName("btn_login");
        btn_login->setMinimumSize(QSize(0, 25));
        btn_login->setStyleSheet(QString::fromUtf8("font: 25 14pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"color: rgb(255,255,255);\n"
"background-color: rgb(20,196,188);\n"
"                              \n"
"  border: none;\n"
"border-radius:15px;\n"
"  background-color: rgb(22,218,208);\n"
" background-color: rgb(250,95,136);\n"
"\n"
"\n"
""));

        formLayout->setWidget(0, QFormLayout::SpanningRole, btn_login);

        btn_exit = new QPushButton(widget);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setMinimumSize(QSize(0, 25));
        btn_exit->setStyleSheet(QString::fromUtf8("font: 25 14pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"color: rgb(255,255,255);\n"
"background-color: rgb(20,196,188);\n"
"                              \n"
"  border: none;\n"
"border-radius:15px;\n"
"  background-color: rgb(22,218,208);\n"
" background-color: rgb(250,95,136);\n"
"\n"
"\n"
""));

        formLayout->setWidget(1, QFormLayout::SpanningRole, btn_exit);


        verticalLayout->addWidget(widget);


        retranslateUi(Page_login);

        QMetaObject::connectSlotsByName(Page_login);
    } // setupUi

    void retranslateUi(QWidget *Page_login)
    {
        Page_login->setWindowTitle(QCoreApplication::translate("Page_login", "\346\210\220\347\273\251\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
#if QT_CONFIG(tooltip)
        Page_login->setToolTip(QCoreApplication::translate("Page_login", "\347\231\273\345\275\225\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("Page_login", "\351\200\211\344\277\256\350\257\276\346\210\220\347\273\251\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label_2->setText(QString());
        le_password->setPlaceholderText(QCoreApplication::translate("Page_login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("Page_login", "\345\257\206\347\240\201:", nullptr));
        account->setText(QCoreApplication::translate("Page_login", "\350\264\246\345\217\267", nullptr));
        le_username->setPlaceholderText(QCoreApplication::translate("Page_login", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267/\345\267\245\345\217\267", nullptr));
        btn_login->setText(QCoreApplication::translate("Page_login", "\347\231\273\345\275\225", nullptr));
        btn_exit->setText(QCoreApplication::translate("Page_login", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Page_login: public Ui_Page_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_LOGIN_H
