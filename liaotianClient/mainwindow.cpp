#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);//设置窗口无边框
    setFixedSize(width(),height());//设置固定大小
    setAttribute(Qt::WA_TranslucentBackground);// 设置窗口支持透明背景
    liaotianPage=new LiaotianWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mOffset=event->globalPos()-this->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()-mOffset);
}

void MainWindow::on_btnArticle_clicked(bool checked)
{
    if(checked){
        ui->btnSignIn->setStyleSheet("border:none;background-color: rgb(55, 142, 255);border-radius:10px;color: rgb(255, 255, 255);");
        ui->btnSignIn->setEnabled(true);
    }
    else{
        ui->btnSignIn->setStyleSheet("border:none;background-color: rgb(170, 214, 255);border-radius:10px;color: rgb(255, 255, 255);");
        ui->btnSignIn->setEnabled(false);
    }
}


void MainWindow::on_btnSignIn_clicked()
{
    this->hide();
    this->liaotianPage->show();
    this->liaotianPage->myName=ui->editUser->text();
}


void MainWindow::on_btnClose_clicked()
{
    QApplication::quit();
}

