/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Config;
    QAction *actionSave_Config;
    QAction *actionUsage;
    QAction *actionAbout_SIDACQ;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pbStartAcq;
    QLabel *lblInfo;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_22;
    QLabel *lblTotEvents;
    QLabel *label_23;
    QLabel *lblEvePerSec;
    QFrame *frame_2;
    QFrame *frame_3;
    QFrame *frame_4;
    QFrame *frame_5;
    QLabel *label_25;
    QFrame *frame_6;
    QPushButton *pbServer;
    QCheckBox *cbSaveFile;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_24;
    QLabel *lblRun;
    QLabel *lblFile;
    QWidget *tabConfig;
    QFrame *frameconfig;
    QPushButton *pbSetVal;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *cbID;
    QComboBox *cbBuffer;
    QComboBox *cbPolarity;
    QComboBox *cbExtTrig;
    QComboBox *cbSWTrig;
    QLabel *label_20;
    QComboBox *cbPost;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_19;
    QLabel *label_7;
    QLineEdit *leCh0Baseline;
    QLineEdit *leCh0Threshold;
    QComboBox *cbCh0Wire;
    QLabel *label_12;
    QLineEdit *leCh1Baseline;
    QLineEdit *leCh1Threshold;
    QComboBox *cbCh1Wire;
    QLabel *label_13;
    QLineEdit *leCh2Baseline;
    QLineEdit *leCh2Threshold;
    QComboBox *cbCh2Wire;
    QLabel *label_14;
    QLineEdit *leCh3Baseline;
    QLineEdit *leCh3Threshold;
    QComboBox *cbCh3Wire;
    QLabel *label_15;
    QLineEdit *leCh4Baseline;
    QLineEdit *leCh4Threshold;
    QComboBox *cbCh4Wire;
    QLabel *label_16;
    QLineEdit *leCh5Baseline;
    QLineEdit *leCh5Threshold;
    QComboBox *cbCh5Wire;
    QLabel *label_17;
    QLineEdit *leCh6Baseline;
    QLineEdit *leCh6Threshold;
    QComboBox *cbCh6Wire;
    QLabel *label_18;
    QLineEdit *leCh7Baseline;
    QLineEdit *leCh7Threshold;
    QComboBox *cbCh7Wire;
    QComboBox *cbCh0OnOff;
    QComboBox *cbCh1OnOff;
    QComboBox *cbCh2OnOff;
    QComboBox *cbCh3OnOff;
    QComboBox *cbCh4OnOff;
    QComboBox *cbCh5OnOff;
    QComboBox *cbCh6OnOff;
    QComboBox *cbCh7OnOff;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_21;
    QLineEdit *leAddress;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cbModules;
    QWidget *tabFile;
    QLabel *lblRunFileLocation;
    QPushButton *pbRunFileLocation;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(709, 687);
        MainWindow->setMaximumSize(QSize(709, 687));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        actionOpen_Config = new QAction(MainWindow);
        actionOpen_Config->setObjectName(QStringLiteral("actionOpen_Config"));
        actionSave_Config = new QAction(MainWindow);
        actionSave_Config->setObjectName(QStringLiteral("actionSave_Config"));
        actionUsage = new QAction(MainWindow);
        actionUsage->setObjectName(QStringLiteral("actionUsage"));
        actionAbout_SIDACQ = new QAction(MainWindow);
        actionAbout_SIDACQ->setObjectName(QStringLiteral("actionAbout_SIDACQ"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 691, 771));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        tabWidget->setFont(font1);
        tabWidget->setAutoFillBackground(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pbStartAcq = new QPushButton(tab);
        pbStartAcq->setObjectName(QStringLiteral("pbStartAcq"));
        pbStartAcq->setGeometry(QRect(220, 290, 211, 151));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        pbStartAcq->setFont(font2);
        pbStartAcq->setStyleSheet(QStringLiteral(""));
        pbStartAcq->setCheckable(true);
        pbStartAcq->setChecked(false);
        pbStartAcq->setAutoDefault(false);
        pbStartAcq->setDefault(false);
        pbStartAcq->setFlat(false);
        lblInfo = new QLabel(tab);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        lblInfo->setGeometry(QRect(340, 40, 281, 61));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 70, 341, 81));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setStyleSheet(QStringLiteral("font: 16pt \"Sans Serif\";"));

        gridLayout_2->addWidget(label_22, 0, 0, 1, 1);

        lblTotEvents = new QLabel(layoutWidget);
        lblTotEvents->setObjectName(QStringLiteral("lblTotEvents"));
        lblTotEvents->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: 18pt \"Sans Serif\";"));

        gridLayout_2->addWidget(lblTotEvents, 0, 1, 1, 1);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"font: 16pt \"Sans Serif\";"));

        gridLayout_2->addWidget(label_23, 1, 0, 1, 1);

        lblEvePerSec = new QLabel(layoutWidget);
        lblEvePerSec->setObjectName(QStringLiteral("lblEvePerSec"));
        lblEvePerSec->setStyleSheet(QLatin1String("color: rgb(170, 0, 0);\n"
"font: 20pt \"Sans Serif\";"));

        gridLayout_2->addWidget(lblEvePerSec, 1, 1, 1, 1);

        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(160, 60, 361, 51));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(0, 60, 361, 61));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(tab);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(160, 110, 361, 51));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_5 = new QFrame(tab);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(210, 170, 271, 51));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_25 = new QLabel(tab);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(30, 230, 81, 31));
        frame_6 = new QFrame(tab);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(10, 229, 661, 31));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        pbServer = new QPushButton(tab);
        pbServer->setObjectName(QStringLiteral("pbServer"));
        pbServer->setGeometry(QRect(20, 280, 151, 91));
        pbServer->setStyleSheet(QLatin1String("border-image: url(:/new/icons/Ccard3dev-Dynamic-Yosemite-OS-X-Server.ico);\n"
"color: rgb(255, 255, 255);\n"
""));
        pbServer->setCheckable(true);
        cbSaveFile = new QCheckBox(tab);
        cbSaveFile->setObjectName(QStringLiteral("cbSaveFile"));
        cbSaveFile->setGeometry(QRect(21, 370, 141, 91));
        cbSaveFile->setMinimumSize(QSize(131, 61));
        cbSaveFile->setAutoFillBackground(false);
        cbSaveFile->setStyleSheet(QLatin1String("image: url(:/new/icons/Jonathan-Rey-Devices-Pack-3-Hard-Disk-HDD-3.5-SATA.ico);\n"
"border-color: rgb(0, 0, 0);\n"
"color: rgb(170, 0, 0);\n"
"font: 18pt \"Sans Serif\";\n"
"\n"
""));
        cbSaveFile->setIconSize(QSize(50, 50));
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(220, 176, 251, 40));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(widget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setStyleSheet(QLatin1String("font: 24pt \"Sans Serif\";\n"
""));

        horizontalLayout_3->addWidget(label_24);

        lblRun = new QLabel(widget);
        lblRun->setObjectName(QStringLiteral("lblRun"));
        lblRun->setStyleSheet(QLatin1String("color: rgb(0, 170, 0);\n"
"font: 24pt \"Sans Serif\";"));

        horizontalLayout_3->addWidget(lblRun);

        lblFile = new QLabel(tab);
        lblFile->setObjectName(QStringLiteral("lblFile"));
        lblFile->setGeometry(QRect(170, 230, 501, 31));
        lblFile->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        tabWidget->addTab(tab, QString());
        frame_6->raise();
        pbStartAcq->raise();
        lblInfo->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        label_24->raise();
        frame_2->raise();
        frame_4->raise();
        frame_5->raise();
        label_25->raise();
        tabConfig = new QWidget();
        tabConfig->setObjectName(QStringLiteral("tabConfig"));
        frameconfig = new QFrame(tabConfig);
        frameconfig->setObjectName(QStringLiteral("frameconfig"));
        frameconfig->setGeometry(QRect(0, 50, 681, 531));
        QFont font3;
        font3.setPointSize(10);
        frameconfig->setFont(font3);
        frameconfig->setFrameShape(QFrame::StyledPanel);
        frameconfig->setFrameShadow(QFrame::Raised);
        pbSetVal = new QPushButton(frameconfig);
        pbSetVal->setObjectName(QStringLiteral("pbSetVal"));
        pbSetVal->setGeometry(QRect(340, 80, 191, 101));
        pbSetVal->setFont(font2);
        pbSetVal->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        frame = new QFrame(frameconfig);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 10, 181, 201));
        formLayout = new QFormLayout(frame);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        cbID = new QComboBox(frame);
        cbID->setObjectName(QStringLiteral("cbID"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cbID);

        cbBuffer = new QComboBox(frame);
        cbBuffer->setObjectName(QStringLiteral("cbBuffer"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cbBuffer);

        cbPolarity = new QComboBox(frame);
        cbPolarity->setObjectName(QStringLiteral("cbPolarity"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cbPolarity);

        cbExtTrig = new QComboBox(frame);
        cbExtTrig->setObjectName(QStringLiteral("cbExtTrig"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cbExtTrig);

        cbSWTrig = new QComboBox(frame);
        cbSWTrig->setObjectName(QStringLiteral("cbSWTrig"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cbSWTrig);

        label_20 = new QLabel(frame);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_20);

        cbPost = new QComboBox(frame);
        cbPost->setObjectName(QStringLiteral("cbPost"));

        formLayout->setWidget(5, QFormLayout::FieldRole, cbPost);

        layoutWidget1 = new QWidget(frameconfig);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(22, 229, 631, 291));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 1, 1, 1);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 0, 2, 1, 1);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 0, 3, 1, 1);

        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout->addWidget(label_19, 0, 4, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        leCh0Baseline = new QLineEdit(layoutWidget1);
        leCh0Baseline->setObjectName(QStringLiteral("leCh0Baseline"));

        gridLayout->addWidget(leCh0Baseline, 1, 2, 1, 1);

        leCh0Threshold = new QLineEdit(layoutWidget1);
        leCh0Threshold->setObjectName(QStringLiteral("leCh0Threshold"));

        gridLayout->addWidget(leCh0Threshold, 1, 3, 1, 1);

        cbCh0Wire = new QComboBox(layoutWidget1);
        cbCh0Wire->setObjectName(QStringLiteral("cbCh0Wire"));

        gridLayout->addWidget(cbCh0Wire, 1, 4, 1, 1);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        leCh1Baseline = new QLineEdit(layoutWidget1);
        leCh1Baseline->setObjectName(QStringLiteral("leCh1Baseline"));

        gridLayout->addWidget(leCh1Baseline, 2, 2, 1, 1);

        leCh1Threshold = new QLineEdit(layoutWidget1);
        leCh1Threshold->setObjectName(QStringLiteral("leCh1Threshold"));

        gridLayout->addWidget(leCh1Threshold, 2, 3, 1, 1);

        cbCh1Wire = new QComboBox(layoutWidget1);
        cbCh1Wire->setObjectName(QStringLiteral("cbCh1Wire"));

        gridLayout->addWidget(cbCh1Wire, 2, 4, 1, 1);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 3, 0, 1, 1);

        leCh2Baseline = new QLineEdit(layoutWidget1);
        leCh2Baseline->setObjectName(QStringLiteral("leCh2Baseline"));

        gridLayout->addWidget(leCh2Baseline, 3, 2, 1, 1);

        leCh2Threshold = new QLineEdit(layoutWidget1);
        leCh2Threshold->setObjectName(QStringLiteral("leCh2Threshold"));

        gridLayout->addWidget(leCh2Threshold, 3, 3, 1, 1);

        cbCh2Wire = new QComboBox(layoutWidget1);
        cbCh2Wire->setObjectName(QStringLiteral("cbCh2Wire"));

        gridLayout->addWidget(cbCh2Wire, 3, 4, 1, 1);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 4, 0, 1, 1);

        leCh3Baseline = new QLineEdit(layoutWidget1);
        leCh3Baseline->setObjectName(QStringLiteral("leCh3Baseline"));

        gridLayout->addWidget(leCh3Baseline, 4, 2, 1, 1);

        leCh3Threshold = new QLineEdit(layoutWidget1);
        leCh3Threshold->setObjectName(QStringLiteral("leCh3Threshold"));

        gridLayout->addWidget(leCh3Threshold, 4, 3, 1, 1);

        cbCh3Wire = new QComboBox(layoutWidget1);
        cbCh3Wire->setObjectName(QStringLiteral("cbCh3Wire"));

        gridLayout->addWidget(cbCh3Wire, 4, 4, 1, 1);

        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 5, 0, 1, 1);

        leCh4Baseline = new QLineEdit(layoutWidget1);
        leCh4Baseline->setObjectName(QStringLiteral("leCh4Baseline"));

        gridLayout->addWidget(leCh4Baseline, 5, 2, 1, 1);

        leCh4Threshold = new QLineEdit(layoutWidget1);
        leCh4Threshold->setObjectName(QStringLiteral("leCh4Threshold"));

        gridLayout->addWidget(leCh4Threshold, 5, 3, 1, 1);

        cbCh4Wire = new QComboBox(layoutWidget1);
        cbCh4Wire->setObjectName(QStringLiteral("cbCh4Wire"));

        gridLayout->addWidget(cbCh4Wire, 5, 4, 1, 1);

        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 6, 0, 1, 1);

        leCh5Baseline = new QLineEdit(layoutWidget1);
        leCh5Baseline->setObjectName(QStringLiteral("leCh5Baseline"));

        gridLayout->addWidget(leCh5Baseline, 6, 2, 1, 1);

        leCh5Threshold = new QLineEdit(layoutWidget1);
        leCh5Threshold->setObjectName(QStringLiteral("leCh5Threshold"));

        gridLayout->addWidget(leCh5Threshold, 6, 3, 1, 1);

        cbCh5Wire = new QComboBox(layoutWidget1);
        cbCh5Wire->setObjectName(QStringLiteral("cbCh5Wire"));

        gridLayout->addWidget(cbCh5Wire, 6, 4, 1, 1);

        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout->addWidget(label_17, 7, 0, 1, 1);

        leCh6Baseline = new QLineEdit(layoutWidget1);
        leCh6Baseline->setObjectName(QStringLiteral("leCh6Baseline"));

        gridLayout->addWidget(leCh6Baseline, 7, 2, 1, 1);

        leCh6Threshold = new QLineEdit(layoutWidget1);
        leCh6Threshold->setObjectName(QStringLiteral("leCh6Threshold"));

        gridLayout->addWidget(leCh6Threshold, 7, 3, 1, 1);

        cbCh6Wire = new QComboBox(layoutWidget1);
        cbCh6Wire->setObjectName(QStringLiteral("cbCh6Wire"));

        gridLayout->addWidget(cbCh6Wire, 7, 4, 1, 1);

        label_18 = new QLabel(layoutWidget1);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout->addWidget(label_18, 8, 0, 1, 1);

        leCh7Baseline = new QLineEdit(layoutWidget1);
        leCh7Baseline->setObjectName(QStringLiteral("leCh7Baseline"));

        gridLayout->addWidget(leCh7Baseline, 8, 2, 1, 1);

        leCh7Threshold = new QLineEdit(layoutWidget1);
        leCh7Threshold->setObjectName(QStringLiteral("leCh7Threshold"));

        gridLayout->addWidget(leCh7Threshold, 8, 3, 1, 1);

        cbCh7Wire = new QComboBox(layoutWidget1);
        cbCh7Wire->setObjectName(QStringLiteral("cbCh7Wire"));

        gridLayout->addWidget(cbCh7Wire, 8, 4, 1, 1);

        cbCh0OnOff = new QComboBox(layoutWidget1);
        cbCh0OnOff->setObjectName(QStringLiteral("cbCh0OnOff"));

        gridLayout->addWidget(cbCh0OnOff, 1, 1, 1, 1);

        cbCh1OnOff = new QComboBox(layoutWidget1);
        cbCh1OnOff->setObjectName(QStringLiteral("cbCh1OnOff"));

        gridLayout->addWidget(cbCh1OnOff, 2, 1, 1, 1);

        cbCh2OnOff = new QComboBox(layoutWidget1);
        cbCh2OnOff->setObjectName(QStringLiteral("cbCh2OnOff"));

        gridLayout->addWidget(cbCh2OnOff, 3, 1, 1, 1);

        cbCh3OnOff = new QComboBox(layoutWidget1);
        cbCh3OnOff->setObjectName(QStringLiteral("cbCh3OnOff"));

        gridLayout->addWidget(cbCh3OnOff, 4, 1, 1, 1);

        cbCh4OnOff = new QComboBox(layoutWidget1);
        cbCh4OnOff->setObjectName(QStringLiteral("cbCh4OnOff"));

        gridLayout->addWidget(cbCh4OnOff, 5, 1, 1, 1);

        cbCh5OnOff = new QComboBox(layoutWidget1);
        cbCh5OnOff->setObjectName(QStringLiteral("cbCh5OnOff"));

        gridLayout->addWidget(cbCh5OnOff, 6, 1, 1, 1);

        cbCh6OnOff = new QComboBox(layoutWidget1);
        cbCh6OnOff->setObjectName(QStringLiteral("cbCh6OnOff"));

        gridLayout->addWidget(cbCh6OnOff, 7, 1, 1, 1);

        cbCh7OnOff = new QComboBox(layoutWidget1);
        cbCh7OnOff->setObjectName(QStringLiteral("cbCh7OnOff"));

        gridLayout->addWidget(cbCh7OnOff, 8, 1, 1, 1);

        layoutWidget2 = new QWidget(frameconfig);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(210, 20, 214, 44));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(layoutWidget2);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_2->addWidget(label_21);

        leAddress = new QLineEdit(layoutWidget2);
        leAddress->setObjectName(QStringLiteral("leAddress"));

        horizontalLayout_2->addWidget(leAddress);

        layoutWidget3 = new QWidget(tabConfig);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(500, 10, 152, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        cbModules = new QComboBox(layoutWidget3);
        cbModules->setObjectName(QStringLiteral("cbModules"));

        horizontalLayout->addWidget(cbModules);

        tabWidget->addTab(tabConfig, QString());
        tabFile = new QWidget();
        tabFile->setObjectName(QStringLiteral("tabFile"));
        lblRunFileLocation = new QLabel(tabFile);
        lblRunFileLocation->setObjectName(QStringLiteral("lblRunFileLocation"));
        lblRunFileLocation->setGeometry(QRect(190, 70, 341, 41));
        pbRunFileLocation = new QPushButton(tabFile);
        pbRunFileLocation->setObjectName(QStringLiteral("pbRunFileLocation"));
        pbRunFileLocation->setGeometry(QRect(10, 70, 161, 41));
        tabWidget->addTab(tabFile, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 709, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(pbStartAcq, cbSaveFile);
        QWidget::setTabOrder(cbSaveFile, pbServer);
        QWidget::setTabOrder(pbServer, pbSetVal);
        QWidget::setTabOrder(pbSetVal, cbID);
        QWidget::setTabOrder(cbID, cbBuffer);
        QWidget::setTabOrder(cbBuffer, cbPolarity);
        QWidget::setTabOrder(cbPolarity, cbExtTrig);
        QWidget::setTabOrder(cbExtTrig, cbSWTrig);
        QWidget::setTabOrder(cbSWTrig, cbPost);
        QWidget::setTabOrder(cbPost, leCh0Baseline);
        QWidget::setTabOrder(leCh0Baseline, leCh0Threshold);
        QWidget::setTabOrder(leCh0Threshold, cbCh0Wire);
        QWidget::setTabOrder(cbCh0Wire, leCh1Baseline);
        QWidget::setTabOrder(leCh1Baseline, leCh1Threshold);
        QWidget::setTabOrder(leCh1Threshold, cbCh1Wire);
        QWidget::setTabOrder(cbCh1Wire, leCh2Baseline);
        QWidget::setTabOrder(leCh2Baseline, leCh2Threshold);
        QWidget::setTabOrder(leCh2Threshold, cbCh2Wire);
        QWidget::setTabOrder(cbCh2Wire, leCh3Baseline);
        QWidget::setTabOrder(leCh3Baseline, leCh3Threshold);
        QWidget::setTabOrder(leCh3Threshold, cbCh3Wire);
        QWidget::setTabOrder(cbCh3Wire, leCh4Baseline);
        QWidget::setTabOrder(leCh4Baseline, tabWidget);
        QWidget::setTabOrder(tabWidget, leCh4Threshold);
        QWidget::setTabOrder(leCh4Threshold, cbCh4Wire);
        QWidget::setTabOrder(cbCh4Wire, leCh5Baseline);
        QWidget::setTabOrder(leCh5Baseline, leCh5Threshold);
        QWidget::setTabOrder(leCh5Threshold, cbCh5Wire);
        QWidget::setTabOrder(cbCh5Wire, leCh6Baseline);
        QWidget::setTabOrder(leCh6Baseline, leCh6Threshold);
        QWidget::setTabOrder(leCh6Threshold, cbCh6Wire);
        QWidget::setTabOrder(cbCh6Wire, leCh7Baseline);
        QWidget::setTabOrder(leCh7Baseline, leCh7Threshold);
        QWidget::setTabOrder(leCh7Threshold, cbCh7Wire);
        QWidget::setTabOrder(cbCh7Wire, cbCh0OnOff);
        QWidget::setTabOrder(cbCh0OnOff, cbCh1OnOff);
        QWidget::setTabOrder(cbCh1OnOff, cbCh2OnOff);
        QWidget::setTabOrder(cbCh2OnOff, cbCh3OnOff);
        QWidget::setTabOrder(cbCh3OnOff, cbCh4OnOff);
        QWidget::setTabOrder(cbCh4OnOff, cbCh5OnOff);
        QWidget::setTabOrder(cbCh5OnOff, cbCh6OnOff);
        QWidget::setTabOrder(cbCh6OnOff, cbCh7OnOff);
        QWidget::setTabOrder(cbCh7OnOff, leAddress);
        QWidget::setTabOrder(leAddress, cbModules);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen_Config);
        menuFile->addAction(actionSave_Config);
        menuHelp->addAction(actionUsage);
        menuHelp->addAction(actionAbout_SIDACQ);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SIDACQ", 0));
        actionOpen_Config->setText(QApplication::translate("MainWindow", "Open Config", 0));
        actionSave_Config->setText(QApplication::translate("MainWindow", "Save Config", 0));
        actionUsage->setText(QApplication::translate("MainWindow", "Usage", 0));
        actionAbout_SIDACQ->setText(QApplication::translate("MainWindow", "About SIDACQ", 0));
        pbStartAcq->setText(QApplication::translate("MainWindow", "start Acq", 0));
        lblInfo->setText(QString());
        label_22->setText(QApplication::translate("MainWindow", "Total events", 0));
        lblTotEvents->setText(QApplication::translate("MainWindow", "0", 0));
        label_23->setText(QApplication::translate("MainWindow", "Events/Second", 0));
        lblEvePerSec->setText(QApplication::translate("MainWindow", "0/Sec", 0));
        label_25->setText(QApplication::translate("MainWindow", "Run File", 0));
#ifndef QT_NO_TOOLTIP
        pbServer->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Start online server</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pbServer->setText(QApplication::translate("MainWindow", "Server", 0));
        cbSaveFile->setText(QString());
        label_24->setText(QApplication::translate("MainWindow", "Run", 0));
        lblRun->setText(QString());
        lblFile->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Control", 0));
        pbSetVal->setText(QApplication::translate("MainWindow", "Set Values", 0));
        label_2->setText(QApplication::translate("MainWindow", "ID", 0));
        label_3->setText(QApplication::translate("MainWindow", "Buffer", 0));
        label_4->setText(QApplication::translate("MainWindow", "Polarity", 0));
        label_5->setText(QApplication::translate("MainWindow", "Ext. Trigger", 0));
        label_6->setText(QApplication::translate("MainWindow", "SW Trigger", 0));
        label_20->setText(QApplication::translate("MainWindow", "Post", 0));
        label_8->setText(QApplication::translate("MainWindow", "Channel", 0));
        label_9->setText(QApplication::translate("MainWindow", "State", 0));
        label_10->setText(QApplication::translate("MainWindow", "Baseline (Channel)", 0));
        label_11->setText(QApplication::translate("MainWindow", "Trig. Threshold (mV)", 0));
        label_19->setText(QApplication::translate("MainWindow", "Wire", 0));
        label_7->setText(QApplication::translate("MainWindow", "0", 0));
        leCh0Baseline->setText(QApplication::translate("MainWindow", "8000", 0));
        leCh0Threshold->setText(QApplication::translate("MainWindow", "8050", 0));
        label_12->setText(QApplication::translate("MainWindow", "1", 0));
        leCh1Baseline->setText(QApplication::translate("MainWindow", "8000", 0));
        leCh1Threshold->setText(QApplication::translate("MainWindow", "8050", 0));
        label_13->setText(QApplication::translate("MainWindow", "2", 0));
        leCh2Baseline->setText(QApplication::translate("MainWindow", "8000", 0));
        leCh2Threshold->setText(QApplication::translate("MainWindow", "8050", 0));
        label_14->setText(QApplication::translate("MainWindow", "3", 0));
        leCh3Baseline->setText(QApplication::translate("MainWindow", "8000", 0));
        leCh3Threshold->setText(QApplication::translate("MainWindow", "8050", 0));
        label_15->setText(QApplication::translate("MainWindow", "4", 0));
        leCh4Baseline->setText(QApplication::translate("MainWindow", "8000", 0));
        leCh4Threshold->setText(QApplication::translate("MainWindow", "8050", 0));
        label_16->setText(QApplication::translate("MainWindow", "5", 0));
        leCh5Baseline->setText(QApplication::translate("MainWindow", "8000", 0));
        leCh5Threshold->setText(QApplication::translate("MainWindow", "8050", 0));
        label_17->setText(QApplication::translate("MainWindow", "6", 0));
        leCh6Baseline->setText(QApplication::translate("MainWindow", "8000", 0));
        leCh6Threshold->setText(QApplication::translate("MainWindow", "8050", 0));
        label_18->setText(QApplication::translate("MainWindow", "7", 0));
        leCh7Baseline->setText(QApplication::translate("MainWindow", "8000", 0));
        leCh7Threshold->setText(QApplication::translate("MainWindow", "8050", 0));
        label_21->setText(QApplication::translate("MainWindow", "Address", 0));
        leAddress->setText(QApplication::translate("MainWindow", "0x0a010000", 0));
        label->setText(QApplication::translate("MainWindow", "Modules", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabConfig), QApplication::translate("MainWindow", "Configure", 0));
        lblRunFileLocation->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pbRunFileLocation->setText(QApplication::translate("MainWindow", "Change run file location", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabFile), QApplication::translate("MainWindow", "File", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
