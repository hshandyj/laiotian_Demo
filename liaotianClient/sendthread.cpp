#include "sendthread.h"
#include <QMutex>
#include <QMutexLocker>

SendThread::SendThread(QTcpSocket *socket, QObject *parent)
    : QThread(parent),
    tcpSocket(socket)
{
}

void SendThread::run()
{
    while (true) {
        if (!message.isEmpty()) {
            tcpSocket->write(message.toUtf8());
            tcpSocket->flush();
            message.clear();
        }
        QThread::sleep(1); // 控制发送频率
    }
}

void SendThread::sendText(const QString &text)
{
    message = text;
}
