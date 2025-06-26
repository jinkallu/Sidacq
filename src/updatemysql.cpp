#include "updatemysql.h"
#include "tcpsenddata.h"

updateMySql::updateMySql()
{
    flagupdateMySql = flagOutCopy = flagServCon = flagDataReady = false;
    idMySql = 1;



}

void updateMySql::run(){




    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "rawdata");
    db.setHostName("localhost");
    db.setDatabaseName("siddata");
    db.setUserName("root");
    db.setPassword("*let*it*go*");
    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "-------------------------- Failed to connect -----------------------------------------" );
    }
    else
        cout<<" --------------------------------- Database opened successfull --------------------------------- "<<endl;
     QSqlQuery query(db.database("rawdata"));
     for(int i=1; i<=10; i++){
         query.prepare("UPDATE rawdata SET flag=:flag WHERE id=:id");
         query.bindValue(":id", i);
         query.bindValue(":flag", 1);



         if(!query.exec()) {
             qWarning() << __FUNCTION__ <<":"<<__LINE__<<query.lastError();
         }
         else{
             cout<<"Database updated"<<endl;
         }
         cout<<"--------------------- Database ready -------------------------"<<endl;
     }
    while(1){
       QThread::usleep(200);
        if(flagupdateMySql){
            //flagServCon = false;
            //quint32 teSize;
            //(&sidEve, QIODevice::WriteOnly);


            QBuffer qBuffer(&outQueue);
            qBuffer.open(QIODevice::WriteOnly);

            QDataStream outQueueStr(&qBuffer);
            outQueueStr.setVersion(QDataStream::Qt_5_0);

            QByteArray boardQueue;//(&sidEve, QIODevice::WriteOnly);

            QBuffer boardBuffer(&boardQueue);
            boardBuffer.open(QIODevice::WriteOnly);
            //boardBuffer.seek(0);
            QDataStream boardQueueStr(&boardBuffer);
            boardQueueStr.setVersion(QDataStream::Qt_5_0);

            //cout<<"hi"<<endl;


            if(flagOutCopy){
                outQueueStr << copyQueueFifo;
                boardQueueStr << idFifoCopy;
                //cout<<"--------------------------------------------------test board id -----------------------"<<idFifoCopy.dequeue()<<endl;
                copyQueueFifo.clear();
                idFifoCopy.clear();

            }
            else{
                outQueueStr <<queueFifo;
                boardQueueStr << idFifo;
                //cout<<"--------------------------------------------------test board id -----------------------"<<idFifo.dequeue()<<endl;
                queueFifo.clear();
                idFifo.clear();
            }
            //tcpData.thread->bAr = tcpData.bytArrData;
            //tcpData.flagDataReady = true;
            //if(tcpData.flagClientConnected)
              //  tcpData.sendData();
            //flagDataReady = true;
            //cout<<"size           ---------"<<outQueue.size()<<"---------------------"<<boardQueue.size()<<endl;
            query.prepare("SELECT flag FROM rawdata WHERE id=:id");
            query.bindValue(":id", idMySql);


            if(!query.exec()) {
                qWarning() << __FUNCTION__ <<":"<<__LINE__<<query.lastError();
            }
            else{
                if(query.next()){
                    if(query.value(0).toInt()==0){
                        query.prepare("UPDATE rawdata SET boardID = :boardID,  data=:data, flag=:flag WHERE id=:id");
                        query.bindValue(":id", idMySql);
                        query.bindValue(":boardID", boardQueue);
                        query.bindValue(":data", outQueue);
                        query.bindValue(":flag", 1);
                        if(!query.exec()) {
                            qWarning() << __FUNCTION__ <<":"<<__LINE__<<query.lastError();
                            //exit(0);
                        }
                        else{
                            cout<<"-------------------------------------------------- updated rawdata --------------------------------------------------------- "<<endl;
                            idMySql++;
                            if(idMySql>1) idMySql = 1;
                        }
                    }
                }
            }

            flagupdateMySql = false;

          //emit signalDataReady();
            //flagupdateMySql = false;
          /* if(flagServCon){
               QTcpSocket *clientConnection1 = tcpServer.nextPendingConnection();
               //clientConnection->setParent(NULL);
               //clientConnection->moveToThread(QThread::currentThread());
                cout<<"Sending data---------------------------------------------------------------"<<endl;

                //clientConnection = tcpServer->nextPendingConnection();


                clientConnection1->write(outQueue);
                clientConnection1->waitForBytesWritten(5000);
                clientConnection1->disconnectFromHost();
                flagServCon = false;
            }*/
            //flagServCon = true;


            //cout<<"------------------------------------------------- Updating rawdata database -------------------------------------------------------"<<endl;

            outQueue.clear();
            boardQueue.clear();
            //while(!outQueue.isNull()){}
            //while(!boardQueue.isNull()){}
            qBuffer.reset();
            boardBuffer.reset();
            outQueueStr.device()->seek(0);
            outQueueStr.device()->reset();
            boardQueueStr.device()->seek(0);
            boardQueueStr.device()->reset();

        }

    }
    db.close();
    exec();
}

void updateMySql::servConnected(){

    //while(!flagServCon){}
    //if(flagServCon){
        //cout<<"Sending data---------------------------------------------------------------"<<endl;


        /*connect(clientConnection, SIGNAL(disconnected()),
                clientConnection, SLOT(deleteLater()));*/

    //}
}
void updateMySql::sendData(){
    //clientConnection = tcpServer.nextPendingConnection();

    flagServCon = true;
    //cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<QThread::currentThreadId()<<endl;
    //upMySql.clientConnection->moveToThread(&upMySql);
  /*  QTcpSocket *clientConnection1 = tcpServer.nextPendingConnection();
    while(1){
        QThread::usleep(200);
        if(flagDataReady && (clientConnection1->state() == QTcpSocket::ConnectedState)){
            cout<<"Sending data---------------------------------------------------------------"<<endl;

            //clientConnection = tcpServer->nextPendingConnection();


            clientConnection1->write(outQueue);
            clientConnection1->waitForBytesWritten(5000);
            clientConnection1->disconnectFromHost();
            flagDataReady = false;
        }

    }*/
}
