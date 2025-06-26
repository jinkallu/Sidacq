#include "dataserver.h"
#include "QByteArray"
#include <QtNetwork>
#include "QDebug"
#include "QObject"

dataServer::dataServer()
{
    messageNo = 1;
    flagConnection = false;

    flagbbSql =  flagServer = flagStop  = false;
    buffer = NULL;
    evtptr = NULL;
    Evt = NULL;

    //datStream = new QDataStream(&datBuffer );
    localEvtCounter = 0;
    buf = new char[1000000];

    out.setVersion(QDataStream::Qt_4_0);
    outCopy.setVersion(QDataStream::Qt_4_0);


    databaseCounter = 1;
    totalEvents = 0;





}



void dataServer::run(){

    //QDataStream datStreamSql1(&bbSql1, QIODevice::ReadWrite);
    //datStreamSql1.setVersion(QDataStream::Qt_4_0);
    //QDataStream datStreamSql2(&bbSql2, QIODevice::ReadWrite);
    //datStreamSql2.setVersion(QDataStream::Qt_4_0);
    qDebug()<<"--------Server started----------------";


    quint32 evtSqlCounter = 0;
    //evtStartNo = totalEvents;


    //upMySql.tcpServer.moveToThread(&upMySql);
    /*if (!upMySql.tcpServer.listen(QHostAddress::Any, 45454)) {
             //QMessageBox::critical("Error in opening port");
        QMessageBox msgBox;
         msgBox.setText("Server not connected");
         msgBox.exec();
        qDebug()<<"Error in opening port";
             upMySql.tcpServer.close();
             return;
         }
    std::cout<<upMySql.tcpServer.serverPort()<<std::endl;

    connect(&upMySql.tcpServer, SIGNAL(newConnection()), this, SLOT(sendData()), Qt::DirectConnection);
    //connect(&upMySql, SIGNAL(signalDataReady()), this, SLOT(sendDataArray()), Qt::DirectConnection);

    //QThread testThread;*/

    upMySql.start();

    //upMySql.tcpServer.moveToThread(&testThread);
    //upMySql.moveToThread(&testThread);
    //testThread.start();


    //upMySql.clientConnection->moveToThread(&upMySql);
    //upMySql.tcpServer->moveToThread(&upMySql);

    while(1){
       /*if(upMySql.flagServCon){
            upMySql.clientConnection->setParent(NULL);
            upMySql.clientConnection->moveToThread(&upMySql);
            upMySql.flagServCon = false;
            upMySql.flagDataReady = true;
        }*/
        QThread::usleep(200);

        if(flagStop){

            break;
        }

        if(flagServer){


            QByteArray bb(buffer, bsize);
            if(upMySql.flagOutCopy){

               upMySql.queueFifo.enqueue(bb);
               upMySql.idFifo.enqueue(BoardId);
            }
            else{

                upMySql.copyQueueFifo.enqueue(bb);
                upMySql.idFifoCopy.enqueue(BoardId);
            }


            evtSqlCounter++;
            if(evtSqlCounter==500){
                evtSqlCounter = 0;
                upMySql.flagOutCopy = !upMySql.flagOutCopy;
                //copyQueue();
                //while(upMySql.flagupdateMySql){}
                upMySql.flagupdateMySql = true;
            }


            cout<<"End "<<endl;

            bb.clear();
            while(!bb.isNull()){}




            flagServer = false;

        }
        if(flagStop){


            qDebug()<<"----------- Connection Closed ----------";


            emit finished();
            break;
        }

        // }
        if(flagStop){
            flagStop = false;
            qDebug()<<"----------- Server Stopped ----------";
            emit finished();
            break;
        }

    }
    emit finished();

}

void dataServer::copyQueue(){



}

void dataServer::sendData(){
    qDebug()<<"----------------- ****************************** Server connected ********************************* --------------------------";
    //QMessageBox msgBox;
     //msgBox.setText("Server connected");
     //msgBox.exec();

   //upMySql.clientConnection = upMySql.tcpServer.nextPendingConnection();
   upMySql.flagServCon = true;
  /* while(1){
        if(upMySql.flagDataReady){
            upMySql.clientConnection->write(upMySql.outQueue);
            upMySql.clientConnection->waitForBytesWritten(5000);
            //upMySql.clientConnection->disconnectFromHost();
            upMySql.flagDataReady = false;
        }
   }*/
   // upMySql.clientConnection->moveToThread(&upMySql);
   // upMySql.servConnected();

   /* if(upMySql.flagServCon){
        cout<<"Sending data---------------------------------------------------------------"<<endl;

        //clientConnection = tcpServer->nextPendingConnection();


        upMySql.clientConnection->write(upMySql.outQueue);
        upMySql.clientConnection->waitForBytesWritten(5000);
        upMySql.clientConnection->disconnectFromHost();
        upMySql.flagServCon = false;
    }*/

}

void dataServer::sendDataArray(){
    //upMySql.flagDataReady = true;
    /*if(upMySql.flagServCon){
        upMySql.clientConnection->write(upMySql.outQueue);
        upMySql.clientConnection->waitForBytesWritten(5000);
        upMySql.clientConnection->disconnectFromHost();
        upMySql.flagServCon = false;
    }*/
}
