#ifndef UPDATEMYSQL_H
#define UPDATEMYSQL_H
#include <QThread>
#include <QtSql>
#include <QObject>
#include <QQueue>
#include <iostream>
#include <QtNetwork>
#include "QMessageBox"

using namespace std;
class QUdpSocket;
class updateMySql : public QThread
{
    Q_OBJECT
private:
    void run();
public:
    updateMySql();
    //QSqlDatabase db;
    QQueue<QByteArray> queueFifo, copyQueueFifo;
    QQueue<quint32> idFifo, idFifoCopy;
    bool flagupdateMySql, flagOutCopy, flagServCon, flagDataReady;
    QUdpSocket *udp;
    QTcpServer tcpServer;
    void servConnected();
    int idMySql;
    QByteArray outQueue;
    QTcpSocket *clientConnection;
private slots:
    void sendData();
signals:
   void signalDataReady();
    //void sedUDP();
};

#endif // UPDATEMYSQL_H
