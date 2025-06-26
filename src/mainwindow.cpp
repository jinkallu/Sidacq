#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
 #include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QColor>
#include <QColorDialog>
#include "QThread"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{



    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    c1724 = new caen1724();
    connect(c1724, SIGNAL(updateBaseline()), this, SLOT(updateBaselines()));
   //thread = new QThread;
    //c1724->moveToThread(thread);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateUI()));
    //canvas = new TCanvas("canvas", "", 800, 700);
    // Number of modules
    stringList<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12";
    ui->cbModules->addItems(stringList);
    stringList.clear();
    // Module id
    stringList<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12";
    ui->cbID->addItems(stringList);
    stringList.clear();
    // Reccord length
    stringList<<"512K"<<"256K"<<"128K"<<"64K"<<"32K"<<"16K"<<"8K"<<"4K"<<"2K"<<"1K"<<"512";
    ui->cbBuffer->addItems(stringList);
    //ui->cbBuffer->setCurrentIndex(5);
    stringList.clear();
    // Post trigger
    stringList<<"4000"<<"8000"<<"12000"<<"16000"<<"20000"<<"24000"<<"28000"<<"32000";
    ui->cbPost->addItems(stringList);
    stringList.clear();
    // Polarity
    stringList<<"+"<<"-";
    ui->cbPolarity->addItems(stringList);
    stringList.clear();
    // External trigger
    stringList<<"OFF"<<"ON";
    ui->cbExtTrig->addItems(stringList);
    stringList.clear();
    // Software trigger
    stringList<<"OFF"<<"ON";
    ui->cbSWTrig->addItems(stringList);
    stringList.clear();
    // channel on or off
    stringList<<"OFF"<<"ON";
    ui->cbCh0OnOff->addItems(stringList);
    ui->cbCh1OnOff->addItems(stringList);
    ui->cbCh2OnOff->addItems(stringList);
    ui->cbCh3OnOff->addItems(stringList);
    ui->cbCh4OnOff->addItems(stringList);
    ui->cbCh5OnOff->addItems(stringList);
    ui->cbCh6OnOff->addItems(stringList);
    ui->cbCh7OnOff->addItems(stringList);
    stringList.clear();
    // Wire Mapping
    stringList<<"none"
              <<"WP1Wire1"<<"WP1Wire2"<<"WP1Wire3"<<"WP1Wire4"<<"WP1Wire5"<<"WP1Wire6"<<"WP1Wire7"<<"WP1Wire8"<<
                "WP1Wire9"<<"WP1Wire10"<<"WP1Wire11"<<"WP1Wire12"<<"WP1Wire13"<<"WP1Wire14"<<"WP1Wire15"<<"WP1Wire16"<<
                "WP1Wire17"<<"WP1Wire18"<<"WP1Wire19"
             <<
                "WP2Wire1"<<"WP2Wire2"<<"WP2Wire3"<<"WP2Wire4"<<"WP2Wire5"<<"WP2Wire6"<<"WP2Wire7"<<"WP2Wire8"<<
                                "WP2Wire9"<<"WP2Wire10"<<"WP2Wire11"<<"WP2Wire12"<<"WP2Wire13"<<"WP2Wire14"<<"WP2Wire15"<<"WP2Wire16"<<
                                "WP2Wire17"<<"WP2Wire18"<<"WP2Wire19"
             <<
                "WP3Wire1"<<"WP3Wire2"<<"WP3Wire3"<<"WP3Wire4"<<"WP3Wire5"<<"WP3Wire6"<<"WP3Wire7"<<"WP3Wire8"<<
                                "WP3Wire9"<<"WP3Wire10"<<"WP3Wire11"<<"WP3Wire12"<<"WP3Wire13"<<"WP3Wire14"<<"WP3Wire15"<<"WP3Wire16"<<
                                "WP3Wire17"<<"WP3Wire18"<<"WP3Wire19"
             <<
                "WP4Wire1"<<"WP4Wire2"<<"WP4Wire3"<<"WP4Wire4"<<"WP4Wire5"<<"WP4Wire6"<<"WP4Wire7"<<"WP4Wire8"<<
                                "WP4Wire9"<<"WP4Wire10"<<"WP4Wire11"<<"WP4Wire12"<<"WP4Wire13"<<"WP4Wire14"<<"WP4Wire15"<<"WP4Wire16"<<
                                "WP4Wire17"<<"WP4Wire18"<<"WP4Wire19"
             <<
                "WP5Wire1"<<"WP5Wire2"<<"WP5Wire3"<<"WP5Wire4"<<"WP5Wire5"<<"WP5Wire6"<<"WP5Wire7"<<"WP5Wire8"<<
                                "WP5Wire9"<<"WP5Wire10"<<"WP5Wire11"<<"WP5Wire12"<<"WP5Wire13"<<"WP5Wire14"<<"WP5Wire15"<<"WP5Wire16"<<
                                "WP5Wire17"<<"WP5Wire18"<<"WP5Wire19"
                ;
    ui->cbCh0Wire->addItems(stringList);
    ui->cbCh1Wire->addItems(stringList);
    ui->cbCh2Wire->addItems(stringList);
    ui->cbCh3Wire->addItems(stringList);
    ui->cbCh4Wire->addItems(stringList);
    ui->cbCh5Wire->addItems(stringList);
    ui->cbCh6Wire->addItems(stringList);
    ui->cbCh7Wire->addItems(stringList);

    //connect(thread, SIGNAL(started()), c1724, SLOT(runAcq()));

    openConfig("../config/sid.cfg");
    timer->start(1000);
    c1724->getFile();
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::plotGraph(){
    //gr = new TGraph();
    canvas->Draw();
}

void MainWindow::saveConfigFile()
{
    QFile fileConfig("../config/sid.cfg");
         if (!fileConfig.open(QIODevice::WriteOnly | QIODevice::Text)){
             cout<<"Configuration file could not be saved"<<endl;
             return;
         }

         QTextStream out(&fileConfig);
         out << "NumberOfModules    " << ui->cbModules->currentIndex()+1 <<endl;
         for(int i=0; i<ui->cbModules->currentIndex()+1; i++){
            out << "    ID  "<<c1724->module[i].id<<endl;
            out << "        Address  "<<c1724->module[i].address<<endl;
            out << "        ReccordLength   "<<c1724->module[i].buffer<<endl;
            out << "        Polarity    "<<c1724->module[i].polarity<<endl;
            out << "        ExtTrigger  "<<c1724->module[i].ExtTrigger<<endl;
            out << "        SWTrigger   "<<c1724->module[i].SWTrigger<<endl;
            out << "        PostTrigger "<<c1724->module[i].PostTrigger<<endl;
            for(int j=0; j<8; j++){
                out << "            channel "<<j<<endl;
                out << "                ChannelState    "<<c1724->module[i].chnnelState[j]<<endl;
                out << "                ChannelBaseline    "<<c1724->module[i].channelBaseline[j]<<endl;
                out << "                ChannelTrigThreshold    "<<c1724->module[i].channelTrigThreshold[j]<<endl;
                out << "                WireMap "<<c1724->module[i].ChannelWireMap[j]<<endl;
            }
         }
         out<<"File     "<< ui->lblRunFileLocation->text();
         fileConfig.close();
}


void MainWindow::on_pbSetVal_clicked()
{
    //module[0]->id = ui->cbID->currentIndex()+1;
    //module[0]->buffer = ui->cbBuffer->currentText().toInt();

    c1724->module[ui->cbID->currentIndex()].id = ui->cbID->currentText();
    c1724->module[ui->cbID->currentIndex()].address = ui->leAddress->text();
    c1724->module[ui->cbID->currentIndex()].buffer = ui->cbBuffer->currentText();

    c1724->module[ui->cbID->currentIndex()].polarity = ui->cbPolarity->currentText();
    c1724->module[ui->cbID->currentIndex()].ExtTrigger = ui->cbExtTrig->currentText();
    c1724->module[ui->cbID->currentIndex()].SWTrigger = ui->cbSWTrig->currentText();
    c1724->module[ui->cbID->currentIndex()].PostTrigger = ui->cbPost->currentText();

    c1724->module[ui->cbID->currentIndex()].chnnelState[0] = ui->cbCh0OnOff->currentText();
    c1724->module[ui->cbID->currentIndex()].chnnelState[1] = ui->cbCh1OnOff->currentText();
    c1724->module[ui->cbID->currentIndex()].chnnelState[2] = ui->cbCh2OnOff->currentText();
    c1724->module[ui->cbID->currentIndex()].chnnelState[3] = ui->cbCh3OnOff->currentText();
    c1724->module[ui->cbID->currentIndex()].chnnelState[4] = ui->cbCh4OnOff->currentText();
    c1724->module[ui->cbID->currentIndex()].chnnelState[5] = ui->cbCh5OnOff->currentText();
    c1724->module[ui->cbID->currentIndex()].chnnelState[6] = ui->cbCh6OnOff->currentText();
    c1724->module[ui->cbID->currentIndex()].chnnelState[7] = ui->cbCh7OnOff->currentText();

    c1724->module[ui->cbID->currentIndex()].channelBaseline[0] = ui->leCh0Baseline->text();
    c1724->module[ui->cbID->currentIndex()].channelBaseline[1] = ui->leCh1Baseline->text();
    c1724->module[ui->cbID->currentIndex()].channelBaseline[2] = ui->leCh2Baseline->text();
    c1724->module[ui->cbID->currentIndex()].channelBaseline[3] = ui->leCh3Baseline->text();
    c1724->module[ui->cbID->currentIndex()].channelBaseline[4] = ui->leCh4Baseline->text();
    c1724->module[ui->cbID->currentIndex()].channelBaseline[5] = ui->leCh5Baseline->text();
    c1724->module[ui->cbID->currentIndex()].channelBaseline[6] = ui->leCh6Baseline->text();
    c1724->module[ui->cbID->currentIndex()].channelBaseline[7] = ui->leCh7Baseline->text();

    c1724->module[ui->cbID->currentIndex()].channelTrigThreshold[0] = ui->leCh0Threshold->text();
    c1724->module[ui->cbID->currentIndex()].channelTrigThreshold[1] = ui->leCh1Threshold->text();
    c1724->module[ui->cbID->currentIndex()].channelTrigThreshold[2] = ui->leCh2Threshold->text();
    c1724->module[ui->cbID->currentIndex()].channelTrigThreshold[3] = ui->leCh3Threshold->text();
    c1724->module[ui->cbID->currentIndex()].channelTrigThreshold[4] = ui->leCh4Threshold->text();
    c1724->module[ui->cbID->currentIndex()].channelTrigThreshold[5] = ui->leCh5Threshold->text();
    c1724->module[ui->cbID->currentIndex()].channelTrigThreshold[6] = ui->leCh6Threshold->text();
    c1724->module[ui->cbID->currentIndex()].channelTrigThreshold[7] = ui->leCh7Threshold->text();

    c1724->module[ui->cbID->currentIndex()].ChannelWireMap[0] = ui->cbCh0Wire->currentIndex();
    c1724->module[ui->cbID->currentIndex()].ChannelWireMap[1] = ui->cbCh1Wire->currentIndex();
    c1724->module[ui->cbID->currentIndex()].ChannelWireMap[2] = ui->cbCh2Wire->currentIndex();
    c1724->module[ui->cbID->currentIndex()].ChannelWireMap[3] = ui->cbCh3Wire->currentIndex();
    c1724->module[ui->cbID->currentIndex()].ChannelWireMap[4] = ui->cbCh4Wire->currentIndex();
    c1724->module[ui->cbID->currentIndex()].ChannelWireMap[5] = ui->cbCh5Wire->currentIndex();
    c1724->module[ui->cbID->currentIndex()].ChannelWireMap[6] = ui->cbCh6Wire->currentIndex();
    c1724->module[ui->cbID->currentIndex()].ChannelWireMap[7] = ui->cbCh7Wire->currentIndex();



}

void MainWindow::on_actionOpen_Config_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Config File"));
    openConfig(fileName);
}

void MainWindow::openConfig(QString fileName){
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox msgBox;
        msgBox.setText("The file could not read.");
        msgBox.exec();
        // return true;
    }
    else{

        QTextStream in(&file);
        QStringList word;
        word = in.readLine().split(" ", QString::SkipEmptyParts);//1
        countModules=word[1].toInt();
        ui->cbModules->setCurrentIndex(countModules-1);
        for(int i=0; i<countModules; i++){
            word = in.readLine().split(" ", QString::SkipEmptyParts);//1
            c1724->module[i].id = word[1];
            word = in.readLine().split(" ", QString::SkipEmptyParts);//1
            c1724->module[i].address = word[1];
            word = in.readLine().split(" ", QString::SkipEmptyParts);//1
            c1724->module[i].buffer = word[1];

            word = in.readLine().split(" ", QString::SkipEmptyParts);//1
            c1724->module[i].polarity = word[1];
            word = in.readLine().split(" ", QString::SkipEmptyParts);//1
            c1724->module[i].ExtTrigger = word[1];
            word = in.readLine().split(" ", QString::SkipEmptyParts);//1
            c1724->module[i].SWTrigger = word[1];
            word = in.readLine().split(" ", QString::SkipEmptyParts);//1
            c1724->module[i].PostTrigger = word[1];
            for(int j=0; j<8; j++){
                word = in.readLine().split(" ", QString::SkipEmptyParts);//1
                word = in.readLine().split(" ", QString::SkipEmptyParts);//1
                c1724->module[i].chnnelState[j] = word[1];
                word = in.readLine().split(" ", QString::SkipEmptyParts);//1
                c1724->module[i].channelBaseline[j] = word[1];
                word = in.readLine().split(" ", QString::SkipEmptyParts);//1
                c1724->module[i].channelTrigThreshold[j] = word[1];
                word = in.readLine().split(" ", QString::SkipEmptyParts);//1
                c1724->module[i].ChannelWireMap[j] = word[1].toInt();
            }
        }
        word = in.readLine().split(" ", QString::SkipEmptyParts);//1
        c1724->fileDir = word[1];
    }
    setValuesonScreen();
}

void MainWindow::setValuesonScreen(){
       int currentid = ui->cbID->currentIndex();
       //ui->cbBuffer->setEditText(c1724->module[currentid].buffer);
       ui->cbBuffer->setCurrentText(c1724->module[currentid].buffer);

       ui->leAddress->setText(c1724->module[currentid].address);

       if(c1724->module[currentid].polarity=="+")
           ui->cbPolarity->setCurrentIndex(0);
       else
           ui->cbPolarity->setCurrentIndex(1);

       if(c1724->module[currentid].ExtTrigger == "OFF")
           ui->cbExtTrig->setCurrentIndex(0);
       else if(c1724->module[currentid].ExtTrigger == "ON")
           ui->cbExtTrig->setCurrentIndex(1);

       if(c1724->module[currentid].SWTrigger == "OFF")
           ui->cbSWTrig->setCurrentIndex(0);
       else if(c1724->module[currentid].SWTrigger == "ON")
           ui->cbSWTrig->setCurrentIndex(1);

       ui->cbPost->setCurrentText(c1724->module[currentid].PostTrigger);


// ------------------- Channel state ---------------------- /////
       if(c1724->module[currentid].chnnelState[0] == "OFF")
           ui->cbCh0OnOff->setCurrentIndex(0);
       else if(c1724->module[currentid].chnnelState[0] == "ON")
           ui->cbCh0OnOff->setCurrentIndex(1);

       if(c1724->module[currentid].chnnelState[1] == "OFF")
           ui->cbCh1OnOff->setCurrentIndex(0);
       else if(c1724->module[currentid].chnnelState[1] == "ON")
           ui->cbCh1OnOff->setCurrentIndex(1);

       if(c1724->module[currentid].chnnelState[2] == "OFF")
           ui->cbCh2OnOff->setCurrentIndex(0);
       else if(c1724->module[currentid].chnnelState[2] == "ON")
           ui->cbCh2OnOff->setCurrentIndex(1);

       if(c1724->module[currentid].chnnelState[3] == "OFF")
           ui->cbCh3OnOff->setCurrentIndex(0);
       else if(c1724->module[currentid].chnnelState[3] == "ON")
           ui->cbCh3OnOff->setCurrentIndex(1);

       if(c1724->module[currentid].chnnelState[4] == "OFF")
           ui->cbCh4OnOff->setCurrentIndex(0);
       else if(c1724->module[currentid].chnnelState[4] == "ON")
           ui->cbCh4OnOff->setCurrentIndex(1);

       if(c1724->module[currentid].chnnelState[5] == "OFF")
           ui->cbCh5OnOff->setCurrentIndex(0);
       else if(c1724->module[currentid].chnnelState[5] == "ON")
           ui->cbCh5OnOff->setCurrentIndex(1);

       if(c1724->module[currentid].chnnelState[6] == "OFF")
           ui->cbCh6OnOff->setCurrentIndex(0);
       else if(c1724->module[currentid].chnnelState[6] == "ON")
           ui->cbCh6OnOff->setCurrentIndex(1);

       if(c1724->module[currentid].chnnelState[7] == "OFF")
           ui->cbCh7OnOff->setCurrentIndex(0);
       else if(c1724->module[currentid].chnnelState[7] == "ON")
           ui->cbCh7OnOff->setCurrentIndex(1);
// ---------------------------------------------------------- //


       ui->leCh0Baseline->setText(c1724->module[currentid].channelBaseline[0]);
       ui->leCh1Baseline->setText(c1724->module[currentid].channelBaseline[1]);
       ui->leCh2Baseline->setText(c1724->module[currentid].channelBaseline[2]);
       ui->leCh3Baseline->setText(c1724->module[currentid].channelBaseline[3]);
       ui->leCh4Baseline->setText(c1724->module[currentid].channelBaseline[4]);
       ui->leCh5Baseline->setText(c1724->module[currentid].channelBaseline[5]);
       ui->leCh6Baseline->setText(c1724->module[currentid].channelBaseline[6]);
       ui->leCh7Baseline->setText(c1724->module[currentid].channelBaseline[7]);

       ui->leCh0Threshold->setText(c1724->module[currentid].channelTrigThreshold[0]);
       ui->leCh1Threshold->setText(c1724->module[currentid].channelTrigThreshold[1]);
       ui->leCh2Threshold->setText(c1724->module[currentid].channelTrigThreshold[2]);
       ui->leCh3Threshold->setText(c1724->module[currentid].channelTrigThreshold[3]);
       ui->leCh4Threshold->setText(c1724->module[currentid].channelTrigThreshold[4]);
       ui->leCh5Threshold->setText(c1724->module[currentid].channelTrigThreshold[5]);
       ui->leCh6Threshold->setText(c1724->module[currentid].channelTrigThreshold[6]);
       ui->leCh7Threshold->setText(c1724->module[currentid].channelTrigThreshold[7]);

       ui->cbCh0Wire->setCurrentIndex(c1724->module[currentid].ChannelWireMap[0]);
       ui->cbCh1Wire->setCurrentIndex(c1724->module[currentid].ChannelWireMap[1]);
       ui->cbCh2Wire->setCurrentIndex(c1724->module[currentid].ChannelWireMap[2]);
       ui->cbCh3Wire->setCurrentIndex(c1724->module[currentid].ChannelWireMap[3]);
       ui->cbCh4Wire->setCurrentIndex(c1724->module[currentid].ChannelWireMap[4]);
       ui->cbCh5Wire->setCurrentIndex(c1724->module[currentid].ChannelWireMap[5]);
       ui->cbCh6Wire->setCurrentIndex(c1724->module[currentid].ChannelWireMap[6]);
       ui->cbCh7Wire->setCurrentIndex(c1724->module[currentid].ChannelWireMap[7]);

       ui->lblRunFileLocation->setText(c1724->fileDir);


}

void MainWindow::on_cbID_currentIndexChanged(int index)
{
    setValuesonScreen();
}

void MainWindow::on_actionSave_Config_triggered()
{
    saveConfigFile();
}

void MainWindow::on_pbStartAcq_clicked(bool checked)
{
    if(ui->leAddress->text()==""){
        cout<<"Enter a valid address"<<endl;
        msgBox.setText("Address error");
        msgBox.setInformativeText("Enter a valid address");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        ui->pbStartAcq->setChecked(false);
    }
    else{
        if(checked){
            if(ui->cbSaveFile->isChecked()){
                c1724->saveFile();
            }
            else c1724->flagsaveFile = false;
            c1724->flagChannelSet = false;
            c1724->initialize(ui->cbModules->currentIndex()+1);
            if(c1724->flagDigitizer){
                if(!c1724->flagChannelSet){
                    msgBox.setText("No channel has been enabled");
                    msgBox.setInformativeText("Enable atleast one channel");
                    msgBox.setIcon(QMessageBox::Warning);
                    msgBox.exec();

                }
                else{
                    c1724->getBaseLines();
                    //c1724->startAcq();
                    if(!c1724->isRunning()){
                        c1724->start() ;
                        if(c1724->isRunning()){
                            //timer->start(1000);
                            ui->pbStartAcq->setText("Running");
                            QColor col = Qt::green;
                            QString qss = QString("background-color: %1").arg(col.name());
                            ui->pbStartAcq->setStyleSheet(qss);
                        }
                    }
                }
            }
            else{
                cout<<"Could not open Digitizer"<<endl;
                msgBox.setText("Digitizer error");
                msgBox.setInformativeText("Could not open digitizer");
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.exec();
                ui->pbStartAcq->setChecked(false);
            }
        }
        else{
            c1724->getFile();
            c1724->stopAcq();
            cout<<"-----------------------------------------------------------------------------------------------------------------------------1"<<endl;
            //while(c1724->flagStop){}
            cout<<"-----------------------------------------------------------------------------------------------------------------------------2"<<endl;
            //if(c1724->isRunning()){

                cout<<"-----------------------------------------------------------------------------------------------------------------------------"<<endl;
                while(c1724->dataSer->isRunning()){}
                c1724->quit();
                while(c1724->isRunning()){}
                //c1724->wait(2000);
                //timer->stop();
                //if(c1724->isFinished()){
                    c1724->dataSer->totalEvents = 0;
                    ui->lblTotEvents->setText("0");
                    ui->pbStartAcq->setText("Stopped");
                    QColor col = Qt::red;
                    QString qss = QString("background-color: %1").arg(col.name());
                    ui->pbStartAcq->setStyleSheet(qss);
                //}
           // }

        }
    }
}



void MainWindow::on_pbServer_clicked(bool checked)
{
    if(checked){

        c1724->startServer();
    }
    else{
        c1724->stopServer();
    }

}

void MainWindow::updateUI(){
    int events = c1724->dataSer->totalEvents;
    ui->lblEvePerSec->setText(QString::number(events-ui->lblTotEvents->text().toInt()) + "/S");
    ui->lblTotEvents->setText(QString::number(events));
    ui->lblRun->setText(QString::number(c1724->runNo));
    ui->lblFile->setText(c1724->outFileName);

    if(c1724->flagServOnOff){
        ui->pbServer->setText("Running");
        //QColor col = Qt::green;
        //QString qss = QString("background-color: %1").arg(col.name());
        QString qss = "border-image: url(:/new/icons/Rimshotdesign-Nod2-Hard-Disk-Server.ico);color: rgb(255, 255, 255);";
        ui->pbServer->setStyleSheet(qss);
    }
    else{
        ui->pbServer->setText("Start");
        //QColor col = Qt::red;
        //QString("background-color: %1").arg(col.name());
        QString qss = "border-image: url(:/new/icons/Ccard3dev-Dynamic-Yosemite-OS-X-Server.ico);color: rgb(255, 255, 255);";
        ui->pbServer->setStyleSheet(qss);
    }

}

void MainWindow::updateBaselines(){
    for(int i=0; i<countModules; i++){
        for(int cha = 0; cha<8; cha++){
            if(c1724->channelState[i*8 + cha]){
                c1724->module[i].channelBaseline[cha] = QString::number(c1724->mean[i*8 + cha]);
                //c1724->module[i].channelTrigThreshold[cha] = QString::number(c1724->baseline[i*8 + cha]);

            }
        }
    }
    setValuesonScreen();
}

void MainWindow::on_actionAbout_SIDACQ_triggered()
{
    msgBox.setText("SIDACQ Data acquisition software");
    msgBox.setInformativeText("Version : 1.0");
    msgBox.setDetailedText("Contact \n jinesh.bond@gmail.com");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

void MainWindow::on_pbRunFileLocation_clicked()
{
    QString fileName =  QFileDialog::getExistingDirectory(this, tr("Location of saved run files"),
                                                          "/media/DATA",
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);//QFileDialog::getOpenFileName(this,tr("Config File"), QFileDialog::fileMode().);
    ui->lblRunFileLocation->setText(fileName);
    c1724->fileDir = fileName;
    c1724->getFile();
}
