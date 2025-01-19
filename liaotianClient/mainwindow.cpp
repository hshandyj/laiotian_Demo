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
    zhucePage=new zhuceMainWindow(this);
    connect(zhucePage,&zhuceMainWindow::sigSwitchLogin,this,&MainWindow::slotSwitchLogin);
}

MainWindow::~MainWindow()
{
    //qDebug()<<"MainWindow";
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
}

void MainWindow::on_btnClose_clicked()
{
    QApplication::quit();
}

void MainWindow::on_btnSignUp_clicked()
{
    this->hide();
    this->zhucePage->show();
}

void MainWindow::on_editUser_selectionChanged()
{
    if(ui->editUser->text()=="输入QQ号")
        ui->editUser->clear();
}

void MainWindow::on_editPassword_selectionChanged()
{
    if(ui->editPassword->text()=="输入QQ密码")
    {
        ui->editPassword->clear();
        ui->editPassword->setEchoMode(QLineEdit::Password);
    }

}

void MainWindow::slotSwitchLogin()
{
    this->zhucePage->hide();
    this->show();
}

