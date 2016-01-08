#include <TSystem.h>
#include <TChain.h>
#include <TROOT.h>
#include <TRint.h>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TEventList.h>
#include "TClonesArray.h"
#include <TH1D.h>
#include <TH1D.h>
#include <TH2F.h>
#include <TF1.h>
#include "TLorentzVector.h"
#include "TCanvas.h"
#include <TMath.h>
#include <TProfile.h>
#include "TStyle.h"
#include <time.h>
#include <TString.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

#include <algorithm> // std sort icin

#include "TLatex.h"
#include "TLegend.h"

#include "TVectorD.h"
#include "ExRootAnalysis/ExRootTreeReader.h"
#include "DelphesClasses.h"


using namespace std;

int main(int argc, char*argv[])
{
 gSystem->Load("libDelphes");
 gSystem->Load("libExRootAnalysis");
 //arg
 string inputFile=argv[1];
 string outputFile=argv[2];
 TFile *out = TFile::Open(outputFile.c_str(),"RECREATE");
 // Create chain of root trees
 TChain chain("Delphes");
 chain.Add(inputFile.c_str());

 // Create object of class ExRootTreeReader
 ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
 Long64_t numberOfEntries = treeReader->GetEntries();

 // Get pointers to branches used in this analysis
 TClonesArray *branchJet  = treeReader->UseBranch("Jet");
 TClonesArray *branchGenJet = treeReader->UseBranch("GenJet");
 TClonesArray *scalarht = treeReader->UseBranch("ScalarHT");

 /////////////////////////////
 //Histograms/////////////////
 /////////////////////////////

 TH2 *hist_deltaY_60_100 = new TH2F("hist_deltaY_60_100","hist_deltaY_60_100",500,-5.0,5.0,500,-0.2,0.2);
 TH2 *hist_deltaY_100_150 = new TH2F("hist_deltaY_100_150","hist_deltaY_100_150",500,-5.0,5.0,500,-0.2,0.2);
 TH2 *hist_deltaY_150_200 = new TH2F("hist_deltaY_150_200","hist_deltaY_150_200",500,-5.0,5.0,500,-0.2,0.2);

 TH1 *histevent60100 = new TH1F("histevent60100","histevent60100",500,-0.5,0.5);
 TH1 *histevent100150 = new TH1F("histevent100150","histevent60100",500,-0.5,0.5);
 TH1 *histevent150200 = new TH1F("histevent150200","histevent60100",500,-0.5,0.5);

 TH1 *hist_PT_resolution = new TH1F("hist_PT_resolution","hist_PT_resolution",500,-1.0,1);

 TH2 *hist_PT_resolution_for_each[3];
 hist_PT_resolution_for_each[0] = new TH2F("hist_leading_pt_res","hist_PT_resolution_for_each",500,0.0,4000,500,-1.0,1.0);
 hist_PT_resolution_for_each[1] = new TH2F("hist_nleading_pt_res","hist_PT_resolution_for_each",500,0.0,4000,500,-1.0,1.0);
 hist_PT_resolution_for_each[2] = new TH2F("hist_nnleading_pt_res","hist_PT_resolution_for_each",500,0.0,4000,500,-1.0,1.0);

 TH1 *histleadingcolojetpt = new TH1F("leadingcolojetpt", "leadingcolojetpt", 50, 0.0, 400.0);
 TH1 *histnleadingcolojetpt = new TH1F("nleadingcolojetpt", "nleadingcolojetpt", 50, 0.0, 400.0);
 TH1 *histnnleadingcolojetpt = new TH1F("nnleadingcolojetpt", "nnleadingcolojetpt", 50, 0.0, 400.0);

 TH1 *histcolojetht = new TH1F("histcolojetht","histcolojetht",1000, 0.0, 10000.0);




 TH2 *histresleadingjet = new TH2F("histresleadingjet","histresleadingjet",500,0.0,4000,500,-1.0,1.0);
 TH2 *histres2leadingjet = new TH2F("histres2leadingjet","histresleadingjet",500,0.0,4000,500,-1.0,1.0);
 TH2 *histres3leadingjet = new TH2F("histres3leadingjet","histresleadingjet",500,0.0,2500,500,-1.0,1.0);

 TH1 *histcolo2jetht = new TH1F("histcolo2jetht",">2jet ht",500,0.0,10000.0);
 TH1 *histcolo3jetht = new TH1F("histcolo3jetht",">3jet ht",500,0.0,10000.0);

 TH1 *histgen2jetht = new TH1F("histgen2jetht",">2jet ht",500,0.0,10000.0);
 TH1 *histgen3jetht = new TH1F("histgen3jetht",">3jet ht",500,0.0,10000.0);

  //Definition
 vector<Jet *> colojet;
 vector<Jet *> genjet;

 ScalarHT* scht=0;
 Jet *cjet;
 Jet *gjet;

 int nocolojet = 0;
 //double ptrescut = 0;


  for(int entry = 0; entry < numberOfEntries; ++entry)
  {
     //her 10000 olayda bıze bılgı verıyor
     if(entry%10000 == 0) cout << "event number: " << entry << endl;
     // Load selected branches with data from specified event
     treeReader->ReadEntry(entry);

     //////////////////////////////////////
     ///Scalerht yı scht ye dolduruyor.////
     //////////////////////////////////////

     for(int i =0 ;i<scalarht->GetEntriesFast();++i )
     {
       scht =(ScalarHT*) scalarht->At(i);
     }

     ///////////////////////////////////////////////
     ////genjet bilgilerini alıyor//////////////////
     ///////////////////////////////////////////////

     genjet.clear();
     for(int i=0;i < branchGenJet->GetEntriesFast();++i)
     {
       gjet = (Jet*) branchGenJet->At(i);
       genjet.push_back(gjet);
     }

     //////////////////////////////////////////////
     ///colojet bilgilerini alıyor ////////////////
     //////////////////////////////////////////////

     colojet.clear();
     for(int i=0;i < branchJet->GetEntriesFast(); ++i)
     {
      cjet = (Jet*) branchJet->At(i);
      colojet.push_back(cjet);
     }

     /////////////////////////////////////////////
     /////// delta(y) for (60 - (100) - (150) - 250)///////////
     /////////////////////////////////////////////

     double ptbins=0;
     if(genjet.size()==colojet.size())
     {

       for(unsigned i = 0; i< genjet.size();++i)
       {
         ptbins=genjet[i]->PT;
         if( ptbins > 60 && ptbins < 100)
         {
           hist_deltaY_60_100->Fill(genjet[i]->Eta,genjet[i]->Eta - colojet[i]->Eta);
           histevent60100->Fill(genjet[i]->Eta - colojet[i]->Eta);
         }
         if(ptbins > 100 && ptbins < 150)
         {
           hist_deltaY_100_150->Fill(genjet[i]->Eta,genjet[i]->Eta - colojet[i]->Eta);
           histevent100150->Fill(genjet[i]->Eta - colojet[i]->Eta);
         }
         if(ptbins > 150 && ptbins < 200)
         {
           hist_deltaY_150_200->Fill(genjet[i]->Eta,genjet[i]->Eta - colojet[i]->Eta);
           histevent150200->Fill(genjet[i]->Eta - colojet[i]->Eta);
         }
       }
     }



     //////////////////////////////////////////////////////////////////////
     //R parametresi buluyor ve pt resolution yapıyor//////////////////////
     //////////////////////////////////////////////////////////////////////

     double r =0;
     double pt_res_cut=0;
     if(genjet.size()> 1 && colojet.size()>1)
     {
       for(unsigned i = 0; i<3;i++)
       {
         if(abs(genjet[i]->Eta) <= 2.5 && abs(colojet[i]->Eta) <= 2.5)
         {
           double deltaPhi = abs(genjet[i]->Phi - colojet[i]->Phi);
           double deltaEta = abs(genjet[i]->Eta - colojet[i]->Eta);
           r = sqrt( pow(deltaPhi,2) + pow(deltaEta,2));
            if(r<0.25)
            {
             pt_res_cut = ((genjet[i]->PT - colojet[i]->PT) / (genjet[i]->PT));
            }
           hist_PT_resolution->Fill(pt_res_cut);
           hist_PT_resolution_for_each[i]->Fill(genjet[i]->PT,pt_res_cut);
          }
        }
      }

     ///////////////////////////////////
     ////jet > 2  ve jet > 3 için HT////
     ///////////////////////////////////

     int genjetsay=0;
     double genjetht2=0;
     double genjetht3=0;
     if(genjet.size() >= 2)
     {
       if(r<2.5)
       {
       for(unsigned i = 0; i<genjet.size();++i)
       {
         if(genjet[i]->PT > 50 && abs( genjet[i]->Eta ) <= 2.5)
         {
           genjetsay++;
         }
       }
      }
     }

     if(genjetsay>=2)
     {
       for(unsigned i =0;i<genjet.size();++i)
       {
         genjetht2=genjetht2+genjet[i]->PT;
       }
     }
     if(genjetsay>=3)
     {
       for(unsigned i = 0;i<genjet.size();++i)
       {
         genjetht3=genjetht3+genjet[i]->PT;
       }
     }
     histgen2jetht->Fill(genjetht2);
     histgen3jetht->Fill(genjetht3);

     ///////////////////////////////////
     ///R32 Colo ///////////////////////
     ///////////////////////////////////
     int say=0;
     for(unsigned i=0; i < colojet.size() ; i++)
     {
       if(colojet[i]->PT >= 50.0 && abs( colojet[i]->Eta ) <= 2.5)
       {
         say++;
       }
     }

     if( say >= 2 )
     {
       histcolo2jetht->Fill(scht->HT);
     }
     if( say >= 3 )
     {
       histcolo3jetht->Fill(scht->HT);
     }



     if(colojet.size()<1)
     {
       nocolojet=nocolojet+1;
     }
     else
     {
       double colojetht=0;
       for(unsigned i = 0 ; i < colojet.size();++i)
       {
         colojetht=colojetht+colojet[i]->PT;
       }
       histcolojetht->Fill(colojetht);
     }
     if(colojet.size()==1)
     {
       histleadingcolojetpt->Fill(colojet[0]->PT);
     }
     if(colojet.size()==2)
     {
       histnleadingcolojetpt->Fill(colojet[1]->PT);
     }
     if(colojet.size()==3)
     {
       histnnleadingcolojetpt->Fill(colojet[2]->PT);
     }
     //////////////

     if(genjet.size()>0 && colojet.size()>0)
     {
       if(abs(genjet[0]->Eta)<=2.5 ){
       histresleadingjet->Fill(genjet[0]->PT,((genjet[0]->PT - colojet[0]->PT)/genjet[0]->PT));
       }

     }
     if(genjet.size()>1 && colojet.size()>1)
     {
       if(abs(genjet[1]->Eta)<=2.5 ){
       histres2leadingjet->Fill(genjet[1]->PT,((genjet[1]->PT - colojet[1]->PT)/genjet[1]->PT));
       }
     }
     if(genjet.size()>2 && colojet.size()>2)
     {
       if(abs(genjet[2]->Eta)<=2.5 ){
       histres3leadingjet->Fill(genjet[2]->PT,((genjet[2]->PT - colojet[2]->PT)/genjet[2]->PT));
     }
     }

  }
  out->Write();
  out->Close();

 }
