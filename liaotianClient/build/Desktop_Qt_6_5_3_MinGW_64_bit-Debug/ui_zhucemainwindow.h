/********************************************************************************
** Form generated from reading UI file 'zhucemainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUCEMAINWINDOW_H
#define UI_ZHUCEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zhuceMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLineEdit *editUsername;
    QLineEdit *editEmail;
    QLineEdit *editPassword;
    QLineEdit *editPasswordYes;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *editCode;
    QPushButton *btnGetCode;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSignup;
    QPushButton *btnExit;

    void setupUi(QMainWindow *zhuceMainWindow)
    {
        if (zhuceMainWindow->objectName().isEmpty())
            zhuceMainWindow->setObjectName("zhuceMainWindow");
        zhuceMainWindow->resize(738, 696);
        centralwidget = new QWidget(zhuceMainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 740, 698));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"	background-image: url(:/res/zhuce.png);\n"
"	border: 1px solid rgb(222, 215, 208);\n"
"	border-radius: 15px;\n"
"}\n"
"font: '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
""));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(220, 290, 301, 341));
        widget_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"                color: gray; /* \351\273\230\350\256\244\346\226\207\346\234\254\351\242\234\350\211\262\344\270\272\346\265\205\347\201\260\350\211\262 */\n"
"				border-radius: 15px;\n"
"				font: '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"                font-size: 14px;\n"
"            }\n"
"QLineEdit:focus {\n"
"                color: black; /* \350\276\223\345\205\245\346\227\266\346\226\207\346\234\254\351\242\234\350\211\262\344\270\272\351\273\221\350\211\262 */\n"
"				border-radius: 15px;\n"
"				font: '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"                font-size: 14px;\n"
"            }\n"
""));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        editUsername = new QLineEdit(widget_2);
        editUsername->setObjectName("editUsername");
        editUsername->setMinimumSize(QSize(0, 40));
        editUsername->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(editUsername, 0, 0, 1, 1);

        editEmail = new QLineEdit(widget_2);
        editEmail->setObjectName("editEmail");
        editEmail->setMinimumSize(QSize(0, 40));
        editEmail->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(editEmail, 1, 0, 1, 1);

        editPassword = new QLineEdit(widget_2);
        editPassword->setObjectName("editPassword");
        editPassword->setMinimumSize(QSize(0, 40));
        editPassword->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(editPassword, 2, 0, 1, 1);

        editPasswordYes = new QLineEdit(widget_2);
        editPasswordYes->setObjectName("editPasswordYes");
        editPasswordYes->setMinimumSize(QSize(0, 40));
        editPasswordYes->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(editPasswordYes, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        editCode = new QLineEdit(widget_2);
        editCode->setObjectName("editCode");
        editCode->setMinimumSize(QSize(0, 40));
        editCode->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(editCode);

        btnGetCode = new QPushButton(widget_2);
        btnGetCode->setObjectName("btnGetCode");
        btnGetCode->setMinimumSize(QSize(90, 40));
        btnGetCode->setStyleSheet(QString::fromUtf8("background-color: rgb(55, 142, 255);\n"
"border-radius: 10px;\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_2->addWidget(btnGetCode);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(40);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(50, -1, 40, -1);
        btnSignup = new QPushButton(widget_2);
        btnSignup->setObjectName("btnSignup");
        btnSignup->setMinimumSize(QSize(80, 30));
        btnSignup->setStyleSheet(QString::fromUtf8("background-color: rgb(55, 142, 255);\n"
"border-radius: 10px;\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout->addWidget(btnSignup);

        btnExit = new QPushButton(widget_2);
        btnExit->setObjectName("btnExit");
        btnExit->setMinimumSize(QSize(80, 30));
        btnExit->setStyleSheet(QString::fromUtf8("background-color: rgb(55, 142, 255);\n"
"border-radius: 10px;\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout->addWidget(btnExit);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);

        zhuceMainWindow->setCentralWidget(centralwidget);

        retranslateUi(zhuceMainWindow);

        QMetaObject::connectSlotsByName(zhuceMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *zhuceMainWindow)
    {
        zhuceMainWindow->setWindowTitle(QCoreApplication::translate("zhuceMainWindow", "MainWindow", nullptr));
        editUsername->setText(QCoreApplication::translate("zhuceMainWindow", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        editEmail->setText(QCoreApplication::translate("zhuceMainWindow", "\350\276\223\345\205\245\351\202\256\347\256\261", nullptr));
        editPassword->setText(QCoreApplication::translate("zhuceMainWindow", "\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        editPasswordYes->setText(QCoreApplication::translate("zhuceMainWindow", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        editCode->setText(QCoreApplication::translate("zhuceMainWindow", "\351\252\214\350\257\201\347\240\201", nullptr));
        btnGetCode->setText(QCoreApplication::translate("zhuceMainWindow", "\345\217\221\351\200\201\351\252\214\350\257\201\347\240\201", nullptr));
        btnSignup->setText(QCoreApplication::translate("zhuceMainWindow", "\346\263\250\345\206\214", nullptr));
        btnExit->setText(QCoreApplication::translate("zhuceMainWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zhuceMainWindow: public Ui_zhuceMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUCEMAINWINDOW_H
