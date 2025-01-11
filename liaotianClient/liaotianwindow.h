#ifndef LIAOTIANWINDOW_H
#define LIAOTIANWINDOW_H

#include <QContextMenuEvent>
#include <QMouseEvent>
#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTextStream>

class SendThread;   // 声明发送线程
class ReceiveThread; // 声明接收线程

namespace Ui {
class LiaotianWindow;
}

class LiaotianWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LiaotianWindow(QWidget *parent = nullptr);
    ~LiaotianWindow();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


public:
    QString myName;//我的用户名


private slots:
    void on_btnClose_clicked();
    void on_receivedData();// 接收数据槽函数

    void on_btnSend_clicked();

private:
    Ui::LiaotianWindow *ui;
    QTcpSocket *tcpSocket;
    SendThread *sendThread;    // 发送线程
    ReceiveThread *receiveThread;  // 接收线程
    //拖动窗口
    QPoint mOffset;

};

#endif // LIAOTIANWINDOW_H
