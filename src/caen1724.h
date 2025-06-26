#ifndef CAEN1724_H
#define CAEN1724_H

#include <iostream>
#include "CAENDigitizer.h"
#include "TH1F.h"
#include <TApplication.h>
#include <bitset>
#include "TCanvas.h"
#include "QThread"
#include "QObject"
#include "filetree.h"
#include "dataserver.h"
#include "QtNetwork"
#include "QTest"
#include "fstream"

#include "modules.h"



using namespace std;

class fileTree;
class dataServer;
class modules;

class caen1724 : public QThread
{
    Q_OBJECT
private:
    void run();
public:

    CAEN_DGTZ_ErrorCode ret;
    int *handle;
    CAEN_DGTZ_BoardInfo_t BoardInfo;
    CAEN_DGTZ_EventInfo_t eventInfo;
    CAEN_DGTZ_UINT16_EVENT_t *Evt;

    char *buffer;
    int *count, isize;
    quint32 nModules;
    char * evtptr;
    quint32 mean[95];
    uint32_t size,bsize;
    uint32_t numEvents;
    uint32_t *moduleAdd;
    uint32_t reg;

    bool flagStop, flagServ, flagServOnOff, flagsaveFile, flagDigitizer, flagChannelSet;

    fileTree tree;
    dataServer *dataSer;
    QThread *threadSer ;

    modules module[12];
    int channelState[95];

    int threshold[95];
    int baseline[95];

    int runNo;

    int error;





    //char *outFileName;
    //char *fileDir;
    QString outFileName, fileDir;


    int localEvtCounter;



    caen1724();
    void initialize(int modules);
    void getBaseLines();
    void startAcq();
    void stopAcq();
    void stopServer();
    void startServer();
    void getFile();
    void saveFile();
//public slots:
  //  void runAcq();
signals:
    void updateBaseline();

};

#endif // CAEN1724_H
