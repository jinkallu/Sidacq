#include "tcpsenddata.h"

tcpSendData::tcpSendData(QObject *parent)
    : QTcpServer(parent)
{
    flagDataReady = flagClientConnected = flagIncoming = false;
    /*this->tcpServer = new QTcpServer(this);
    if (!tcpServer->listen(QHostAddress::Any, 45454)) {
                 //QMessageBox::critical("Error in opening port");
            QMessageBox msgBox;
             msgBox.setText("Server not connected");
             msgBox.exec();
            qDebug()<<"Error in opening port";
                 tcpServer->close();
                 return;
             }
        std::cout<<tcpServer->serverPort()<<std::endl;
        //tcpServer.moveToThread(this);
        connect(tcpServer, SIGNAL(newConnection()), this, SLOT(connectClient()));
       // cout<<"---------------------------------------------------------------------------------------------------------------------------"<<QThread::currentThreadId()<<endl;*/
}

void tcpSendData::connectClient(){

    flagClientConnected = true;
   /* clientConnection = tcpServer->nextPendingConnection();
    while (flagClientConnected) {
        if(flagDataReady){
            qDebug()<<"-------------------------------------------- sioze "<<bytArrData.size();
            clientConnection->write(bytArrData);
            clientConnection->waitForBytesWritten(5000);
            clientConnection->disconnectFromHost();
            flagDataReady = false;
            flagClientConnected = false;
        }
    }
    qDebug()<<"-------------------------------------------------------Server connected to client -----------------------------------";
*/
}

void tcpSendData::sendData(QByteArray bAr){
    /*if(flagClientConnected){

            qDebug()<<"-------------------------------------------- 1111111111111111111111111111    sioze "<<bytArrData.size();
            //thread->bAr = bytArrData;
    }
    clientConnection.moveToThread(QThread::currentThread());
    if(flagIncoming){
        if (!clientConnection.setSocketDescriptor(socketDescriptor)) {
            //emit error(tcpSocket.error());
            qDebug()<<"---------------------------------- Could not connect to client ---------------------------------------";
            return;
        }
        else {
             qDebug()<<"---------------------------------- Connected to client ---------------------------------------";
        }
    }*/

    //qDebug()<<"size ------------------------------------------------------------------------------------------- "<<flagClientConnected;
    flagDataReady = true;
   /* if(flagClientConnected){
        qDebug()<<"-------------------------------------------- sioze "<<bytArrData.size();
        clientConnection.write(bytArrData);
        clientConnection.waitForBytesWritten(5000);
        clientConnection.disconnectFromHost();
        flagDataReady = false;
        flagClientConnected = false;
            qDebug()<<"-------------------------------------------------------Data sent -----------------------------------";
    }*/
}

void tcpSendData::incomingConnection(qintptr socketDescrip)
{
    //socketDescriptor = socketDescrip;
    if (!clientConnection.setSocketDescriptor(socketDescriptor)) {
        //emit error(tcpSocket.error());
        qDebug()<<"---------------------------------- Could not connect to client ---------------------------------------";
        return;
    }
    else{
        flagClientConnected = true;
        qDebug()<<"---------------------------------- Connected to client ---------------------------------------";
        while (flagClientConnected) {
            if(flagDataReady){
                qDebug()<<"-------------------------------------------- sioze "<<bytArrData.size();
                clientConnection.write(bytArrData);
                clientConnection.waitForBytesWritten(300);
                clientConnection.disconnectFromHost();
                flagDataReady = false;
                flagClientConnected = false;
            }
        }
        flagIncoming = true;
        qDebug()<<"--------------------------------------------Incoming connection   "<<bytArrData.size();
    }

}
