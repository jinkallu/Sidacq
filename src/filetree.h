#ifndef FILETREE_H
#define FILETREE_H

#include "Riostream.h"
#include "TTree.h"
#include "TFile.h"



class fileTree
{
public:
    Int_t     EventNo;
    UInt_t    EventClock;
    UInt_t    BoardId;
    UInt_t    ChannelMask;
    UInt_t    ChaSize[8];
    UShort_t  Data[8*16384];
    //Int_t     No_Planes;
    //Int_t     P1,P2,P3,P4,P5;
    //Int_t     WP1,WP2,WP3,WP4,WP5;
    //Int_t     Which_WP1[19], Which_WP2[19],
    //Which_WP3[19], Which_WP4[19], Which_WP5[19];
    //UShort_t     DataP1[19*16384], DataP2[19*16384],
    //DataP3[19*16384], DataP4[19*16384], DataP5[19*16384];

    TTree *T1;
    TFile *treeFile;

    fileTree();
    void saveTree();


};

#endif // FILETREE_H
