#include "filetree.h"

fileTree::fileTree()
{
    /*treeFile = new TFile("test.root","recreate");

    T1= new TTree("T1","SID");
    T1->Branch("header",&EventNo,"EventNo/I:EventClock/i:No_Planes/I");
    T1->Branch("Planes",&P1,"P1/I:P2/I:P3/I:P4/I:P5/I");
    T1->Branch("No_Wires",&WP1,"WP1/I:WP2/I:WP3/I:WP4/I:WP5/I");
    T1->Branch("WiresTrigP1",Which_WP1,"Which_WP1[WP1]/I");
    T1->Branch("WiresTrigP2",Which_WP2,"Which_WP2[WP2]/I");
    T1->Branch("WiresTrigP3",Which_WP3,"Which_WP3[WP3]/I");
    T1->Branch("WiresTrigP4",Which_WP4,"Which_WP4[WP4]/I");
    T1->Branch("WiresTrigP5",Which_WP5,"Which_WP5[WP5]/I");
    T1->Branch("DataP1",DataP1,"DataP1[311296]/s");
    T1->Branch("DataP2",DataP2,"DataP2[311296]/s");
    T1->Branch("DataP3",DataP3,"DataP3[311296]/s");
    T1->Branch("DataP4",DataP4,"DataP4[311296]/s");
    T1->Branch("DataP5",DataP5,"DataP5[311296]/s");*/
}

void fileTree::saveTree(){
    //treeFile->Write();
    //treeFile->Close();
}
