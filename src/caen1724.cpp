#include "caen1724.h"

#define CHANNEL_STATE 0xf0

caen1724::caen1724()
{
    dataSer = new dataServer();
    //threadSer = new QThread;
    //dataSer->moveToThread(threadSer);
    //connect(threadSer, SIGNAL(started()), dataSer, SLOT(runServ()));
    //connect(dataSer, SIGNAL(finished()), threadSer, SLOT(quit()));
    buffer = NULL;
    evtptr = NULL;
    Evt = NULL;
    isize = sizeof(CAEN_DGTZ_TriggerMode_t);
    flagStop = false;
    error = 0;
    flagServ = false;

    localEvtCounter = 0;
    flagsaveFile = false;
    flagDigitizer = false;
    flagChannelSet = false;

    //fileDir = "/media/DATA/";




}

void caen1724::initialize(int mod){
    // get file name
    getFile();
    int newB = -1;
    nModules = mod;
    count = new int[nModules];
    handle = new int[nModules];
    //moduleAdd = new uint32_t[nModules];
    //moduleAdd[0] = (quint32)module[0].address.toInt(0, 16); //0x0a040000;
    //moduleAdd[1] = 0x0a0c0000;
    cout<<"address "<<(quint32)module[0].address.toInt(0, 16)<<" " <<module[0].address.toLocal8Bit().constData()<<endl;
    //cout<<"address "<<module[0].channelTrigThreshold[0].toInt()<<endl;
    for(quint32 b=0; b<nModules; b++){
        flagChannelSet = false;

        bitset<8> regChannelState;
        for(int countChannelState =0; countChannelState<8; countChannelState++){
            if(module[b].chnnelState[countChannelState]=="ON"){
                regChannelState[countChannelState] = 1;
                channelState[b*8+countChannelState] = 1;
                flagChannelSet = true;
            }
            else{
                regChannelState[countChannelState] = 0;
                channelState[b*8+countChannelState] = 0;
            }
        }
        if(flagChannelSet){
            newB = b;
            ret = CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_USB,0,0,(quint32)module[b].address.toInt(0, 16),&handle[b]);
            error += ret;
            if(ret != CAEN_DGTZ_Success) {
                cout<<"Can't open digitizer "<<module[b].address.data()<<endl;
                ret = CAEN_DGTZ_FreeReadoutBuffer(&dataSer->buffer);
                for(quint32 j=0; j<nModules; j++)
                    ret = CAEN_DGTZ_CloseDigitizer(handle[j]);
                flagDigitizer = false;
            }
            else{
                flagDigitizer = true;
                cout<<"address **********************"<<endl;
                ret = CAEN_DGTZ_Reset(handle[b]);
                // Once we have the handler to the digitizer, we use it to call the other functions
                ret = CAEN_DGTZ_GetInfo(handle[b], &BoardInfo);
                error += ret;
                cout<<"\nConnected to CAEN Digitizer Model "<<BoardInfo.ModelName<<" recognized as board "<<b<<endl;
                cout<<"\tROC FPGA Release is "<<BoardInfo.ROC_FirmwareRel<<endl;
                cout<<"\tAMC FPGA Release is "<<BoardInfo.AMC_FirmwareRel<<endl;
                cout<<"ret "<<ret<<endl;
                //ret = CAEN_DGTZ_GetInfo(handle[b], &BoardInfo);
                //error += ret;
                //cout<<"ret "<<ret<<endl;
                //quint8 cState = 0x0f;


                //cout<<"-------------------------------------------------------------------- "<<(bitset<16>)cState<<endl;


                ret = CAEN_DGTZ_SetChannelEnableMask(handle[b], regChannelState.to_ulong());
                error += ret;
                cout<<"ret "<<ret<<endl;
                ret = CAEN_DGTZ_WriteRegister(handle[b],  0x8114, 6000);//post trigger
                error += ret;
                cout<<"ret "<<ret<<endl;
                for(quint32 ch=0; ch<8; ch++){
                    ret = CAEN_DGTZ_SetChannelPulsePolarity (handle[b], ch, CAEN_DGTZ_PulsePolarityPositive);
                    error += ret;
                    ret = CAEN_DGTZ_SetChannelDCOffset(handle[b], ch, 0x8000);
                    error += ret;
                }
                cout<<"ret "<<ret<<endl;
                // ------------------- buffer size -------------- //
                // 0 - 512K samples/block
                // 1 - 256K samples/block
                // 2 - 128K samples/block
                // 3 - 64K samples/block
                // 4 - 32K samples/block
                // 5 - 16K samples/block
                // 6 - 8K samples/block
                // 7 - 4K samples/block
                // 8 - 2K samples/block
                // 9 - 1K samples/block
                // A - 512 samples/block
                int bufferSize;
                if(module[b].buffer == "512K")
                    bufferSize = 0;
                else if(module[b].buffer == "256K")
                    bufferSize = 1;
                else if(module[b].buffer == "128K")
                    bufferSize = 2;
                else if(module[b].buffer == "64K")
                    bufferSize = 3;
                else if(module[b].buffer == "32K")
                    bufferSize = 4;
                else if(module[b].buffer == "16K")
                    bufferSize = 5;
                else if(module[b].buffer == "8K")
                    bufferSize = 6;
                else if(module[b].buffer == "4K")
                    bufferSize = 7;
                else if(module[b].buffer == "2K")
                    bufferSize = 8;
                else if(module[b].buffer == "1K")
                    bufferSize = 9;
                else if(module[b].buffer == "512")
                    bufferSize = 10;

                ret = CAEN_DGTZ_WriteRegister(handle[b],  0x800C, bufferSize);//buffer size
                error += ret;
                cout<<"ret "<<ret<<endl;
                ret = CAEN_DGTZ_SetChannelSelfTrigger(handle[b],CAEN_DGTZ_TRGMODE_ACQ_ONLY,0xff);
                error += ret;
                cout<<"ret "<<ret<<endl;


                ret = CAEN_DGTZ_WriteRegister(handle[b],  0x810c, 0xC00000FF);
                error += ret;
                cout<<"ret "<<ret<<endl;

                ret = CAEN_DGTZ_ReadRegister(handle[b], 0x800c, &reg);
                cout<<"ret "<<ret<<endl;
                ret = CAEN_DGTZ_ReadRegister(handle[b], 0x8114, &reg);
                cout<<"ret "<<ret<<endl;
                ret = CAEN_DGTZ_SetSWTriggerMode(handle[b],CAEN_DGTZ_TRGMODE_ACQ_ONLY);
                error += ret;
                cout<<"ret "<<ret<<endl;
                ret = CAEN_DGTZ_SetMaxNumEventsBLT(handle[b],1);
                error += ret;
                cout<<"ret "<<ret<<endl;
                ret = CAEN_DGTZ_SetAcquisitionMode(handle[b],CAEN_DGTZ_SW_CONTROLLED);
                error += ret;
                cout<<"ret "<<ret<<endl;
                if(error>0)
                    break;


            }
        }
        else {
            error = 1;
            break;
        }

    }
    if(error >0) {

        if(newB>-1){
            cout<<"Errors during Digitizer Configuration.\n";
            ret = CAEN_DGTZ_FreeReadoutBuffer(&dataSer->buffer);
            for(quint32 stopb=0; stopb<=newB; stopb++){
                ret = CAEN_DGTZ_Reset(handle[stopb]);
                ret = CAEN_DGTZ_CloseDigitizer(handle[stopb]);

            }

        }
        flagChannelSet = false;
        error = 0;
    }


}

void caen1724::getBaseLines(){
    if(error>0)
        cout<<"Error in opening v1724";
    else{
        for(quint32 b=0; b<nModules; b++){
            count[b] = 0;
            ret = CAEN_DGTZ_MallocReadoutBuffer(handle[b],&dataSer->buffer,&size);
            cout<<"ret "<<ret<<endl;
            ret = CAEN_DGTZ_SWStartAcquisition(handle[b]);
            cout<<"ret "<<ret<<endl;
            // soft trigger
            ret = CAEN_DGTZ_SendSWtrigger(handle[b]);

            cout<<"ret "<<ret<<endl;

            ret = CAEN_DGTZ_ReadData(handle[b],CAEN_DGTZ_SLAVE_TERMINATED_READOUT_MBLT,dataSer->buffer,&bsize);
            cout<<"ret "<<ret<<endl;

            ret = CAEN_DGTZ_GetNumEvents(handle[b],dataSer->buffer,bsize,&numEvents);
            cout<<"ret "<<ret<<endl;

            //cout<<"Number of events "<<numEvents<<" Total events "<<count[b]<<endl;
            if(numEvents>0){
                for (int i=0;i<1;i++) {
                    // Get the Infos and pointer to the event
                    ret = CAEN_DGTZ_GetEventInfo(handle[b],dataSer->buffer,bsize,i,&eventInfo,&evtptr);

                    cout<<"Event size "<<eventInfo.EventSize<<endl;

                    // Decode the event to get the data
                    ret = CAEN_DGTZ_DecodeEvent(handle[b],evtptr,(void**)&Evt);
                    for(int cha =0; cha<8; cha++){
                        cout<<Evt->ChSize[cha]<<endl;
                    }
                    //for(int histCount = 0; histCount<8; histCount++){
                    cout<<"good1"<<endl;
                    for(int cha = 0; cha<8; cha++){
                        if(channelState[b*8+cha]){
                            mean[b*8+cha] = 0;
                            for(quint32 j=0; j<Evt->ChSize[cha] ; j++){
                                mean[b*8+cha] += Evt->DataChannel[cha][j];
                                if(j==0)
                                    cout<<Evt->DataChannel[cha][j]<<endl;
                            }
                            mean[b*8+cha] = mean[b*8+cha]/Evt->ChSize[cha];
                            cout<<"Mean "<<b*8+cha<<" "<<mean[b*8+cha]<<endl;
                            threshold[b*8+cha] = module[b].channelTrigThreshold[cha].toFloat()*(16384.0/2250.0); //  16384 channels in amplitude (Amplitude is 2250 mV)
                            baseline[b*8+cha] = mean[b*8+cha] + threshold[b*8+cha];
                            ret = CAEN_DGTZ_SetChannelTriggerThreshold(handle[b], cha, baseline[b*8+cha]);
                        }
                    }

                    cout<<"good2"<<endl;
                    ret = CAEN_DGTZ_FreeEvent(handle[b],(void**)&Evt);
                }
            }
        }
        emit updateBaseline();
    }
}


void caen1724::run(){
    if(error>0)
        cout<<"Error in opening v1724"<<endl;
    else{

        QByteArray sidEve;
        QDataStream outServer(&sidEve, QIODevice::ReadWrite);
        outServer.setVersion(QDataStream::Qt_5_0);
        QFile outFile(outFileName.toUtf8().data());
        if(flagsaveFile){
            cout<<outFileName.data()<<endl;

            if (!outFile.open(QIODevice::WriteOnly)) {
                cerr << "Cannot open file for reading: "
                     << qPrintable(outFile.errorString()) << endl;
                return;
            }

        }
        QDataStream out(&outFile);
        out.setVersion(QDataStream::Qt_5_0);
        //outFile.close();
        for(quint32 b=0; b<nModules; b++){
            ret = CAEN_DGTZ_SetZeroSuppressionMode(handle[b], CAEN_DGTZ_ZS_AMP);
            for(int ch =0; ch<8; ch++){
                ret = CAEN_DGTZ_SetChannelZSParams(handle[b], ch, CAEN_DGTZ_ZS_FINE, (qint32)mean[b*8+ch], 1);


            }
            ret = CAEN_DGTZ_WriteRegister(handle[b], 0x1024, (0x3fffffff & (baseline[b*8+0])));
            ret = CAEN_DGTZ_WriteRegister(handle[b], 0x1124, (0x3fffffff & (baseline[b*8+1])));
            ret = CAEN_DGTZ_WriteRegister(handle[b], 0x1224, (0x3fffffff & (baseline[b*8+2])));
            ret = CAEN_DGTZ_WriteRegister(handle[b], 0x1324, (0x3fffffff & (baseline[b*8+3])));
            ret = CAEN_DGTZ_WriteRegister(handle[b], 0x1424, (0x3fffffff & (baseline[b*8+4])));
            ret = CAEN_DGTZ_WriteRegister(handle[b], 0x1524, (0x3fffffff & (baseline[b*8+5])));
            ret = CAEN_DGTZ_WriteRegister(handle[b], 0x1624, (0x3fffffff & (baseline[b*8+6])));
            ret = CAEN_DGTZ_WriteRegister(handle[b], 0x1724, (0x3fffffff & (baseline[b*8+7])));

            // Count accepted triggers only
            ret = CAEN_DGTZ_ReadRegister(handle[b], 0x8100, &reg);
            cout<<(bitset<32>)reg<<endl;
            //ret = CAEN_DGTZ_WriteRegister(handle[b], 0x8100, (0x3fffffff & (mean[b*8+0]+35)));

        }
        ret = CAEN_DGTZ_FreeReadoutBuffer(&dataSer->buffer);
        ret = CAEN_DGTZ_MallocReadoutBuffer(handle[0],&dataSer->buffer,&size);

        ret = CAEN_DGTZ_ReadRegister(handle[0], 0x1024, &reg);
        cout<< "zero supp ret "<<(bitset<32>)reg<<endl;

        cout<<"--------------- Acquisition Started --------------"<<endl;
        while(1) {

            QThread::usleep(200);

            if(flagServ){
                if(!dataSer->isRunning()){
                    dataSer->flagStop = false;
                    dataSer->start();
                    if(dataSer->isRunning()){
                        flagServOnOff = true;
                    }
                }
                else{
                }
            }

            else{
                if(dataSer->isRunning()){
                    dataSer->flagStop = true;
                    dataSer->quit();
                    //dataSer->wait(2000);
                    while(dataSer->isRunning()){}
                    if(!dataSer->isRunning()){
                        flagServOnOff = false;
                    }
                }
                else {
                    //cout<<"----- Already stopped-------"<<endl;
                }

            }




            for(quint32 b=0; b<nModules; b++) {

                //ret = CAEN_DGTZ_SendSWtrigger(handle[b]);
                ret = CAEN_DGTZ_ReadData(handle[b],CAEN_DGTZ_SLAVE_TERMINATED_READOUT_MBLT,dataSer->buffer,&bsize);
                //dataSer->flagServer = true;
                ret = CAEN_DGTZ_GetNumEvents(handle[b],dataSer->buffer,bsize,&numEvents);
                dataSer->totalEvents+=numEvents;
                if(numEvents>0){
                    cout<<" Events "<<dataSer->totalEvents<<endl;

                    dataSer->handle = handle[b];
                    dataSer->bsize = bsize;
                    dataSer->BoardId = b;

                    if(flagsaveFile){
                        QByteArray bb(dataSer->buffer, bsize);
                        out<<bsize<<b<<bb;
                    }
                    dataSer->flagServer = true;
                    numEvents = 0;
                }



            } // end of loop on boards
            if(flagStop){
                ret = CAEN_DGTZ_FreeReadoutBuffer(&dataSer->buffer);
                for(quint32 stopb=0; stopb<nModules; stopb++){
                    ret = CAEN_DGTZ_Reset(handle[stopb]);
                    ret = CAEN_DGTZ_CloseDigitizer(handle[stopb]);
                }
                cout<<endl<<"----------------Acqusition stopped-----------------"<<endl;
                //tree.saveTree();
                if(dataSer->isRunning()){
                    dataSer->flagStop = true;
                    dataSer->quit();
                    //dataSer->wait(2000);
                    while(dataSer->isRunning()){}
                    if(!dataSer->isRunning()){
                        flagServOnOff = false;
                        cout<<"--------------- Server Closed --------------"<<endl;
                    }
                }
                cout<<"--------------- Server Closed --------------1"<<endl;
                flagStop = false;
                //dataSer.quit();
                dataSer->flagStop = true;

                //if(dataSer->isFinished())

                break;
            }
        }
    }
    exec();
}
void caen1724::startAcq(){
    flagStop = false;
    flagServ = false;
}

void caen1724::stopAcq(){
    flagStop = true;
}

void caen1724::stopServer(){
    flagServ = false;

}

void caen1724::startServer(){
    flagServ = true;
}

void caen1724::getFile(){
    int i=0;
    //outFileName = new char[50];

    while(1){
        //sprintf(outFileName, "%s/run%03d.dat", fileDir, i);
        outFileName = QString(fileDir + "/run%1.dat")
                         .arg(i, 3, 10, QChar('0'));

        runNo = i;
        ifstream in(outFileName.toUtf8().data());
        if(!in.is_open()){
            break;
        }
        i++;
    }

}

void caen1724::saveFile(){
    flagsaveFile = true;
}

