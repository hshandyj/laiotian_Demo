#include "receivethread.h"
#include <QDataStream>

ReceiveThread::ReceiveThread(QTcpSocket *socket, QObject *parent)
    : QThread(parent),
    tcpSocket(socket)
{
}

void ReceiveThread::run()
{
    while (true) {
        if (tcpSocket->waitForReadyRead()) {
            QByteArray data = tcpSocket->readAll();
            emit dataReceived(QString::fromUtf8(data));
        }
    }
}
