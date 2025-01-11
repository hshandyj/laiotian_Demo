/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QToolButton *btnSet;
    QToolButton *btnClose;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLineEdit *editUser;
    QLineEdit *editPassword;
    QRadioButton *btnArticle;
    QPushButton *btnSignIn;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnMore;
    QLabel *label_2;
    QPushButton *btnSignUp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(391, 551);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 391, 551));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"	\n"
"	background-image: url(:/res/background.png);\n"
"	border: 1px solid rgb(222, 215, 208);\n"
"	border-radius: 15px;\n"
"}\n"
"font: '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
""));
        btnSet = new QToolButton(widget);
        btnSet->setObjectName("btnSet");
        btnSet->setGeometry(QRect(320, 10, 24, 21));
        btnSet->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgba(0 , 0, 0, 0);\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/Search.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSet->setIcon(icon);
        btnClose = new QToolButton(widget);
        btnClose->setObjectName("btnClose");
        btnClose->setGeometry(QRect(350, 10, 24, 21));
        btnClose->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border: none;\n"
"	\n"
"	background-color: rgba(0 , 0, 0, 0);\n"
"}\n"
"QToolButton:hover{\n"
"	background-color: rgb(255, 0 , 0);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon1);
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 30, 191, 281));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/touxiang.png")));
        label->setScaledContents(true);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(60, 260, 271, 271));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(24);
        editUser = new QLineEdit(widget_2);
        editUser->setObjectName("editUser");
        editUser->setMinimumSize(QSize(0, 40));
        editUser->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"                color: gray; /* \351\273\230\350\256\244\346\226\207\346\234\254\351\242\234\350\211\262\344\270\272\346\265\205\347\201\260\350\211\262 */\n"
"				border-radius: 15px;\n"
"				font: '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"                font-size: 14px;\n"
"            }\n"
"\n"
"            QLineEdit:focus {\n"
"                color: black; /* \350\276\223\345\205\245\346\227\266\346\226\207\346\234\254\351\242\234\350\211\262\344\270\272\351\273\221\350\211\262 */\n"
"				border-radius: 15px;\n"
"				font: '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"                font-size: 14px;\n"
"            }\n"
""));
        editUser->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(editUser, 0, 0, 1, 1);

        editPassword = new QLineEdit(widget_2);
        editPassword->setObjectName("editPassword");
        editPassword->setMinimumSize(QSize(0, 40));
        editPassword->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"                color: gray; /* \351\273\230\350\256\244\346\226\207\346\234\254\351\242\234\350\211\262\344\270\272\346\265\205\347\201\260\350\211\262 */\n"
"				border-radius: 15px;\n"
"                font-size: 14px;\n"
"            }\n"
"QLineEdit:focus {\n"
"                color: black; /* \350\276\223\345\205\245\346\227\266\346\226\207\346\234\254\351\242\234\350\211\262\344\270\272\351\273\221\350\211\262 */\n"
"				border-radius: 15px;\n"
"                font-size: 14px;\n"
"            }"));
        editPassword->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(editPassword, 1, 0, 1, 1);

        btnArticle = new QRadioButton(widget_2);
        btnArticle->setObjectName("btnArticle");
        btnArticle->setStyleSheet(QString::fromUtf8(" color: gray; /* \351\273\230\350\256\244\346\226\207\346\234\254\351\242\234\350\211\262\344\270\272\346\265\205\347\201\260\350\211\262 */"));

        gridLayout->addWidget(btnArticle, 2, 0, 1, 1);

        btnSignIn = new QPushButton(widget_2);
        btnSignIn->setObjectName("btnSignIn");
        btnSignIn->setEnabled(false);
        btnSignIn->setMinimumSize(QSize(0, 40));
        btnSignIn->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgb(170, 214, 255);\n"
"border-radius:10px;\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));

        gridLayout->addWidget(btnSignIn, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(50, -1, 50, -1);
        btnMore = new QPushButton(widget_2);
        btnMore->setObjectName("btnMore");
        btnMore->setStyleSheet(QString::fromUtf8("border:none;\n"
"color: rgb(45, 119, 229);\n"
"border-radius:10px;\n"
""));

        horizontalLayout->addWidget(btnMore);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        btnSignUp = new QPushButton(widget_2);
        btnSignUp->setObjectName("btnSignUp");
        btnSignUp->setStyleSheet(QString::fromUtf8("border:none;\n"
"color: rgb(45, 119, 229);\n"
"border-radius:10px;\n"
""));

        horizontalLayout->addWidget(btnSignUp);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnSet->setText(QString());
        btnClose->setText(QString());
        label->setText(QString());
        editUser->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245QQ\345\217\267", nullptr));
        editPassword->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245QQ\345\257\206\347\240\201", nullptr));
        btnArticle->setText(QCoreApplication::translate("MainWindow", "\345\267\262\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217\346\234\215\345\212\241\345\215\217\350\256\256\345\222\214QQ\351\232\220\347\247\201\344\277\235\346\212\244\346\214\207\345\274\225", nullptr));
        btnSignIn->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        btnMore->setText(QCoreApplication::translate("MainWindow", "\346\233\264\345\244\232\351\200\211\351\241\271", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "|", nullptr));
        btnSignUp->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
