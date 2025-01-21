/********************************************************************************
** Form generated from reading UI file 'resetwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETWINDOW_H
#define UI_RESETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickedlabel.h"

QT_BEGIN_NAMESPACE

class Ui_ResetWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *err_tip;
    QLineEdit *editUsername;
    QLineEdit *editEmail;
    QHBoxLayout *horizontalLayout;
    QLineEdit *editCode;
    QPushButton *btnVarify;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *editPassword;
    ClickedLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnSure;
    QPushButton *btnBack;

    void setupUi(QMainWindow *ResetWindow)
    {
        if (ResetWindow->objectName().isEmpty())
            ResetWindow->setObjectName("ResetWindow");
        ResetWindow->resize(390, 550);
        centralwidget = new QWidget(ResetWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 391, 551));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"	background-image: url(:/res/background.png);\n"
"	border: 1px solid rgb(222, 215, 208);\n"
"	border-radius: 15px;\n"
"}\n"
"font: '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
""));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(80, 160, 240, 311));
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
"QPushButton{\n"
"background-color: rgb(55, 142, 255);\n"
"border-radius: 10px;\n"
"color: rgb(255, 255, 255);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        err_tip = new QLabel(widget_2);
        err_tip->setObjectName("err_tip");
        err_tip->setStyleSheet(QString::fromUtf8("#err_tip[state='normal']{\n"
"	color: rgb(0, 255, 8);\n"
"}\n"
"#err_tip[state='err']{\n"
"	color: rgb(255, 0, 0);\n"
"}"));
        err_tip->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(err_tip);

        editUsername = new QLineEdit(widget_2);
        editUsername->setObjectName("editUsername");
        editUsername->setMinimumSize(QSize(0, 40));
        editUsername->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(editUsername);

        editEmail = new QLineEdit(widget_2);
        editEmail->setObjectName("editEmail");
        editEmail->setMinimumSize(QSize(0, 40));
        editEmail->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(editEmail);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(13);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        editCode = new QLineEdit(widget_2);
        editCode->setObjectName("editCode");
        editCode->setMinimumSize(QSize(0, 40));
        editCode->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(editCode);

        btnVarify = new QPushButton(widget_2);
        btnVarify->setObjectName("btnVarify");
        btnVarify->setMinimumSize(QSize(80, 40));
        btnVarify->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(btnVarify);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        editPassword = new QLineEdit(widget_2);
        editPassword->setObjectName("editPassword");
        editPassword->setMinimumSize(QSize(0, 40));
        editPassword->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(editPassword);

        label = new ClickedLabel(widget_2);
        label->setObjectName("label");
        label->setMinimumSize(QSize(20, 20));
        label->setMaximumSize(QSize(20, 20));
        label->setStyleSheet(QString::fromUtf8("#label[state='unvisible']{\n"
"   border-image: url(:/res/unvisible.png);\n"
"}\n"
"\n"
"#label[state='unvisible_hover']{\n"
"   border-image: url(:/res/unvisible_hover.png);\n"
"}\n"
"\n"
"#label[state='visible']{\n"
"   border-image: url(:/res/visible.png);\n"
"}\n"
"\n"
"#label[state='visible_hover']{\n"
"   border-image: url(:/res/visible_hover.png);\n"
"}"));

        horizontalLayout_3->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(40, -1, 40, -1);
        btnSure = new QPushButton(widget_2);
        btnSure->setObjectName("btnSure");
        btnSure->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(btnSure);

        btnBack = new QPushButton(widget_2);
        btnBack->setObjectName("btnBack");
        btnBack->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(btnBack);


        verticalLayout->addLayout(horizontalLayout_2);

        ResetWindow->setCentralWidget(centralwidget);

        retranslateUi(ResetWindow);

        QMetaObject::connectSlotsByName(ResetWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ResetWindow)
    {
        ResetWindow->setWindowTitle(QCoreApplication::translate("ResetWindow", "MainWindow", nullptr));
        err_tip->setText(QString());
        editUsername->setText(QCoreApplication::translate("ResetWindow", "QQ\350\264\246\345\217\267", nullptr));
        editEmail->setText(QCoreApplication::translate("ResetWindow", "QQ\351\202\256\347\256\261", nullptr));
        editCode->setText(QCoreApplication::translate("ResetWindow", "\351\252\214\350\257\201\347\240\201", nullptr));
        btnVarify->setText(QCoreApplication::translate("ResetWindow", "\345\217\221\351\200\201\351\252\214\350\257\201\347\240\201", nullptr));
        editPassword->setText(QCoreApplication::translate("ResetWindow", "\346\226\260\345\257\206\347\240\201", nullptr));
        label->setText(QString());
        btnSure->setText(QCoreApplication::translate("ResetWindow", "\347\241\256\345\256\232", nullptr));
        btnBack->setText(QCoreApplication::translate("ResetWindow", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetWindow: public Ui_ResetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETWINDOW_H
