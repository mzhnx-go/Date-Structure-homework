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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page_login
{
public:
    QLabel *label;
    QWidget *widget;
    QFormLayout *formLayout;
    QPushButton *btn_login;
    QPushButton *btn_exit;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLineEdit *le_username;
    QLineEdit *le_password;
    QLabel *label_3;
    QLabel *account;
    QLabel *label_2;

    void setupUi(QWidget *Page_login)
    {
        if (Page_login->objectName().isEmpty())
            Page_login->setObjectName("Page_login");
        Page_login->resize(492, 284);
        Page_login->setMinimumSize(QSize(492, 284));
        Page_login->setMaximumSize(QSize(492, 284));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bana.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Page_login->setWindowIcon(icon);
        label = new QLabel(Page_login);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 10, 291, 60));
        label->setMinimumSize(QSize(0, 60));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(Page_login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(100, 170, 291, 85));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        btn_login = new QPushButton(widget);
        btn_login->setObjectName("btn_login");
        btn_login->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(0, QFormLayout::SpanningRole, btn_login);

        btn_exit = new QPushButton(widget);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(1, QFormLayout::SpanningRole, btn_exit);

        widget_2 = new QWidget(Page_login);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(70, 90, 351, 79));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        le_username = new QLineEdit(widget_2);
        le_username->setObjectName("le_username");
        le_username->setMinimumSize(QSize(30, 20));
        le_username->setToolTipDuration(1);
        le_username->setMaxLength(20);

        gridLayout->addWidget(le_username, 0, 1, 1, 2);

        le_password = new QLineEdit(widget_2);
        le_password->setObjectName("le_password");
        le_password->setMaxLength(20);
        le_password->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(le_password, 1, 2, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        QFont font1;
        font1.setPointSize(12);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 1, 0, 1, 2);

        account = new QLabel(widget_2);
        account->setObjectName("account");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(12);
        account->setFont(font2);

        gridLayout->addWidget(account, 0, 0, 1, 1);

        label_2 = new QLabel(Page_login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 70, 271, 20));
        label_2->setFont(font1);

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
        btn_login->setText(QCoreApplication::translate("Page_login", "\347\231\273\345\275\225", nullptr));
        btn_exit->setText(QCoreApplication::translate("Page_login", "\351\200\200\345\207\272", nullptr));
        le_username->setPlaceholderText(QCoreApplication::translate("Page_login", "\350\257\267\350\276\223\345\205\245\345\267\245\345\217\267", nullptr));
        le_password->setPlaceholderText(QCoreApplication::translate("Page_login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("Page_login", "\345\257\206\347\240\201:", nullptr));
        account->setText(QCoreApplication::translate("Page_login", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("Page_login", "\350\257\267\350\200\201\345\270\210\350\276\223\345\205\245\345\267\245\345\217\267,\345\255\246\347\224\237\350\276\223\345\205\245\345\255\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Page_login: public Ui_Page_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_LOGIN_H
