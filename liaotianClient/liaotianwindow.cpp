#include "liaotianwindow.h"
#include "ui_liaotianwindow.h"
LiaotianWindow::LiaotianWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LiaotianWindow)
    , sendThread(nullptr)
    , receiveThread(nullptr)
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
    QString message = ui->editIn->toPlainText();
    if (!message.isEmpty()) {
        tcpSocket->write(message.toUtf8());
        tcpSocket->flush();
        ui->editIn->clear();
        qDebug()<<"sendmsg";
    }
}
void LiaotianWindow::on_receivedData()
{
    QByteArray msg = tcpSocket->readAll();  // 从 tcpSocket 中读取数据
    QString message = QString::fromUtf8(msg);
    ui->editOut->append(message); // 显示接收到的数据
}


void LiaotianWindow::mousePressEvent(QMouseEvent *event)
{
    mOffset=event->globalPos()-this->pos();
}

void LiaotianWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()-mOffset);
}
