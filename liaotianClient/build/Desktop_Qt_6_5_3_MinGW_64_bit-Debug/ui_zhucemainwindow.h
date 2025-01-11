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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zhuceMainWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *zhuceMainWindow)
    {
        if (zhuceMainWindow->objectName().isEmpty())
            zhuceMainWindow->setObjectName("zhuceMainWindow");
        zhuceMainWindow->resize(800, 600);
        centralwidget = new QWidget(zhuceMainWindow);
        centralwidget->setObjectName("centralwidget");
        zhuceMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(zhuceMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        zhuceMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(zhuceMainWindow);
        statusbar->setObjectName("statusbar");
        zhuceMainWindow->setStatusBar(statusbar);

        retranslateUi(zhuceMainWindow);

        QMetaObject::connectSlotsByName(zhuceMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *zhuceMainWindow)
    {
        zhuceMainWindow->setWindowTitle(QCoreApplication::translate("zhuceMainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zhuceMainWindow: public Ui_zhuceMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUCEMAINWINDOW_H
