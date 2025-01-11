#ifndef RECEIVETHREAD_H
#define RECEIVETHREAD_H

#include <QThread>
#include <QTcpSocket>

class ReceiveThread : public QThread
{
    Q_OBJECT

public:
    explicit ReceiveThread(QTcpSocket *socket, QObject *parent = nullptr);
    void run() override;

signals:
    void dataReceived(const QString &data);

private:
    QTcpSocket *tcpSocket;
};

#endif // RECEIVETHREAD_H
