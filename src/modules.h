#ifndef MODULES_H
#define MODULES_H

#include <QString>

class modules
{
public:
    QString id;
    QString address;
    QString buffer;
    QString polarity;
    QString ExtTrigger;
    QString SWTrigger;
    QString PostTrigger;
    QString chnnelState[8];
    QString channelBaseline[8];
    QString channelTrigThreshold[8];
    int ChannelWireMap[8];
    modules();
    void readConfigFile();
    void readADCConfig();
    void WriteConfigFile();
    void WriteADCConfig();
};

#endif // MODULES_H
