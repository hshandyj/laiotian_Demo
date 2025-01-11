#ifndef SENDTHREAD_H
#define SENDTHREAD_H

#include <QThread>
#include <QTcpSocket>

class SendThread : public QThread
{
    Q_OBJECT

public:
    explicit SendThread(QTcpSocket *socket, QObject *parent = nullptr);
    void run() override;
    void sendText(const QString &text);

private:
    QTcpSocket *tcpSocket;
    QString message;
};

#endif // SENDTHREAD_H
