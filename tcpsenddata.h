#ifndef TCPSENDDATA_H
#define TCPSENDDATA_H

#include <QObject>
#include <QQueue>
#include <iostream>
#include <QtNetwork>
#include "QMessageBox"



class tcpSendData : public QTcpServer
{
    Q_OBJECT
public:
    tcpSendData(QObject *parent = 0);


    QTcpServer *tcpServer;
    qintptr socketDescriptor;
    QByteArray bytArrData;

    QTcpSocket clientConnection;
    bool flagDataReady, flagClientConnected, flagIncoming;
    void sendData(QByteArray bAr);

    //tcpThread *thread;

public slots:
    void connectClient();
protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;
};

#endif // TCPSENDDATA_H
