/********************************************************************************
** Form generated from reading UI file 'liaotianwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIAOTIANWINDOW_H
#define UI_LIAOTIANWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LiaotianWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QTextEdit *editOut;
    QTextEdit *editIn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *btnSend;
    QToolButton *btnClose;

    void setupUi(QMainWindow *LiaotianWindow)
    {
        if (LiaotianWindow->objectName().isEmpty())
            LiaotianWindow->setObjectName("LiaotianWindow");
        LiaotianWindow->resize(801, 601);
        centralwidget = new QWidget(LiaotianWindow);
        centralwidget->setObjectName("centralwidget");
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 801, 601));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget#widget_2{\n"
"	background-color: rgb(242, 242, 242);\n"
"	border: 1px solid rgb(58, 59, 60);\n"
"	border-radius: 15px;\n"
"}"));
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 30, 701, 551));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(0);
        editOut = new QTextEdit(widget);
        editOut->setObjectName("editOut");
        editOut->setStyleSheet(QString::fromUtf8("	background-color: rgb(242, 242, 242);\n"
"	border: 1px solid rgb(222, 215, 208);\n"
""));

        gridLayout->addWidget(editOut, 0, 0, 1, 1);

        editIn = new QTextEdit(widget);
        editIn->setObjectName("editIn");
        editIn->setStyleSheet(QString::fromUtf8("	background-color: rgb(242, 242, 242);\n"
"	border: 1px solid rgb(222, 215, 208);\n"
""));

        gridLayout->addWidget(editIn, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSend = new QToolButton(widget);
        btnSend->setObjectName("btnSend");

        horizontalLayout->addWidget(btnSend);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        btnClose = new QToolButton(widget_2);
        btnClose->setObjectName("btnClose");
        btnClose->setGeometry(QRect(750, 10, 41, 31));
        btnClose->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border: none;\n"
"	\n"
"	background-color: rgba(0 , 0, 0, 0);\n"
"}\n"
"QToolButton:hover{\n"
"	background-color: rgb(255, 0 , 0);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon);
        btnClose->setIconSize(QSize(24, 24));
        LiaotianWindow->setCentralWidget(centralwidget);

        retranslateUi(LiaotianWindow);

        QMetaObject::connectSlotsByName(LiaotianWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LiaotianWindow)
    {
        LiaotianWindow->setWindowTitle(QCoreApplication::translate("LiaotianWindow", "MainWindow", nullptr));
        btnSend->setText(QCoreApplication::translate("LiaotianWindow", "\345\217\221\351\200\201", nullptr));
        btnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LiaotianWindow: public Ui_LiaotianWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIAOTIANWINDOW_H
