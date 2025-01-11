#include "zhucemainwindow.h"
#include "ui_zhucemainwindow.h"

zhuceMainWindow::zhuceMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::zhuceMainWindow)
{
    liaotianPage=new LiaotianWindow();
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);//设置窗口无边框
    setFixedSize(width(),height());//设置固定大小
    setAttribute(Qt::WA_TranslucentBackground);// 设置窗口支持透明背景



}

zhuceMainWindow::~zhuceMainWindow()
{
    delete ui;
}

void zhuceMainWindow::mousePressEvent(QMouseEvent *event)
{
    mOffset=event->globalPos()-this->pos();
}

void zhuceMainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()-mOffset);
}



void zhuceMainWindow::on_btnExit_clicked()
{
    QApplication::quit();
}


void zhuceMainWindow::on_btnSignup_clicked()
{
    this->hide();
    this->liaotianPage->show();
}


void zhuceMainWindow::on_editUsername_selectionChanged()
{
    if(ui->editUsername->text()=="输入用户名"){
        ui->editUsername->clear();
    }
}


void zhuceMainWindow::on_editEmail_selectionChanged()
{
    if(ui->editEmail->text()=="输入邮箱"){
        ui->editEmail->clear();
    }
}


void zhuceMainWindow::on_editPassword_selectionChanged()
{
    if(ui->editPassword->text()=="输入密码"){
        ui->editPassword->clear();
        ui->editPassword->setEchoMode(QLineEdit::Password);
    }
}


void zhuceMainWindow::on_editPasswordYes_selectionChanged()
{
    if(ui->editPasswordYes->text()=="确认密码"){
        ui->editPasswordYes->clear();
        ui->editPasswordYes->setEchoMode(QLineEdit::Password);
    }
}


void zhuceMainWindow::on_editCode_selectionChanged()
{
    if(ui->editCode->text()=="验证码"){
        ui->editCode->clear();
    }
}

