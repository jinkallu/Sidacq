#ifndef DATASERVER_H
#define DATASERVER_H

#include "Riostream.h"
#include "QMessageBox"
#include <QObject>
#include "stdint.h"
#include "QtNetwork"

#include "QThread"
#include "CAENDigitizer.h"
#include <bitset>
#include <QtSql/QSqlDatabase>
#include <QTest>
#include <QtSql>
#include "updatemysql.h"



class updateMySql;
class QUdpSocket;
class QNetworkSession;

class dataServer: public QThread
{
    Q_OBJECT
    void run();

public:
    u_int32_t     EventNo;
    u_int32_t    EventClock;
    quint32     BoardId;
    u_int32_t     ChannelMask;
    quint32   ChaSize[8];
    quint16  Data[8*16384];

    bool flagServer, flagStop, flagConnection,  flagbbSql;
    bool con;

    //QUdpSocket *udpSocket;
    QString ipAddress;
    QMutex mutex;


     //

    //

       QStringList fortunes;
       QNetworkSession *networkSession;

       CAEN_DGTZ_ErrorCode ret;
       int handle;
       CAEN_DGTZ_BoardInfo_t BoardInfo;
       CAEN_DGTZ_EventInfo_t eventInfo;
       CAEN_DGTZ_UINT16_EVENT_t *Evt;
       uint32_t numEvents;

       char *buffer;
       char *buf;
       quint32 blocksize;
       //int *count, isize, modules;
       char * evtptr;
       //float mean[95];
       int modules;
       uint32_t size,bsize, totalEvents;

    QDataStream out, outCopy;


    dataServer();
    int messageNo;

    QByteArray datBuffer;
    QByteArray bbSql1, bbSql2;
    updateMySql upMySql;

    int localEvtCounter;
    int databaseCounter;
    void copyQueue();

//public slots:
  //  void runServ();
private slots:
    void sendData();
    void sendDataArray();
signals:
    void finished();




private:



};

#endif // DATASERVER_H
