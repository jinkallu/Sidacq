#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TCanvas.h"
#include "TGraph.h"
#include "modules.h"
#include "QStringList"
#include "caen1724.h"
#include "dataserver.h"
#include "QThread"
#include "QtTest/QTest"
#include "QTimer"

class dataServer;
class modules;
class caen1724;
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void plotGraph();
    void setValuesonScreen();
    void saveConfigFile();
    void openConfig(QString fileName);

private slots:

    void on_pbSetVal_clicked();

    void on_actionOpen_Config_triggered();

    void on_cbID_currentIndexChanged(int index);

    void on_actionSave_Config_triggered();


    void on_pbStartAcq_clicked(bool checked);


    void on_pbServer_clicked(bool checked);

    void updateUI();
    void updateBaselines();

    void on_actionAbout_SIDACQ_triggered();

    void on_pbRunFileLocation_clicked();

private:
    Ui::MainWindow *ui;
    TCanvas *canvas;
    TGraph *gr;
    int countModules;
    modules module[12];
    caen1724 *c1724;
    QStringList stringList;
    QThread* thread ;
    QMessageBox msgBox;
    QTimer *timer;
};

#endif // MAINWINDOW_H
