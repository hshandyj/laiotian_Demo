#include "liaotianwindow.h"
#include "ui_liaotianwindow.h"
LiaotianWindow::LiaotianWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LiaotianWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);//设置窗口无边框
    setFixedSize(width(),height());//设置固定大小
    setAttribute(Qt::WA_TranslucentBackground);// 设置窗口支持透明背景

}

LiaotianWindow::~LiaotianWindow()
{
    delete ui;
}

void LiaotianWindow::on_btnClose_clicked()
{
    QApplication::quit();
}


void LiaotianWindow::on_btnSend_clicked()
{
}



void LiaotianWindow::mousePressEvent(QMouseEvent *event)
{
    mOffset=event->globalPos()-this->pos();
}

void LiaotianWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()-mOffset);
}
