//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jan 14 09:22:58 2020 by ROOT version 6.14/00
// from TTree event/info of events
// found on file: /eos/lhaaso/decode/wcda+wfcta/match201912/cal_step2/2019/1129/ES.31057.FULL.WFCTA01.20191129000346.050.cal.root
//////////////////////////////////////////////////////////

#ifndef LHAASOEvent_h
#define LHAASOEvent_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class LHAASOEvent : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> iTel = {fReader, "iTel"};
   TTreeReaderValue<Long64_t> rabbitTime = {fReader, "rabbitTime"};
   TTreeReaderValue<Double_t> rabbittime = {fReader, "rabbittime"};
   TTreeReaderArray<int> isipm = {fReader, "isipm"};
   TTreeReaderArray<double> sipmpe = {fReader, "sipmpe"};
   TTreeReaderArray<double> sipmt = {fReader, "sipmt"};
   TTreeReaderArray<int> cellig = {fReader, "cellig"};
   TTreeReaderArray<double> cellpe = {fReader, "cellpe"};
   TTreeReaderArray<double> cellt = {fReader, "cellt"};
   TTreeReaderArray<int> hitid = {fReader, "hitid"};
   TTreeReaderArray<double> hitpart = {fReader, "hitpart"};
   TTreeReaderArray<double> hitt = {fReader, "hitt"};
   TTreeReaderArray<int> hitmode = {fReader, "hitmode"};
   TTreeReaderValue<Int_t> IsKm2aEvent = {fReader, "IsKm2aEvent"};
   TTreeReaderValue<Int_t> IsWcdaEvent = {fReader, "IsWcdaEvent"};
   TTreeReaderValue<ULong64_t> iwcdaevt = {fReader, "iwcdaevt"};
   TTreeReaderValue<Float_t> km2a_xc = {fReader, "km2a_xc"};
   TTreeReaderValue<Float_t> km2a_yc = {fReader, "km2a_yc"};
   TTreeReaderValue<Float_t> km2a_phi = {fReader, "km2a_phi"};
   TTreeReaderValue<Float_t> km2a_theta = {fReader, "km2a_theta"};
   TTreeReaderValue<unsigned int> fUniqueID = {fReader, "fUniqueID"};
   TTreeReaderValue<unsigned int> fBits = {fReader, "fBits"};
   TTreeReaderValue<Int_t> nhit = {fReader, "nhit"};
   TTreeReaderValue<Int_t> ndetc = {fReader, "ndetc"};
   TTreeReaderValue<Int_t> nfitc = {fReader, "nfitc"};
   TTreeReaderValue<Double_t> mjd = {fReader, "mjd"};
   TTreeReaderValue<Double_t> npea = {fReader, "npea"};
   TTreeReaderValue<Double_t> npec = {fReader, "npec"};
   TTreeReaderValue<Double_t> zen = {fReader, "zen"};
   TTreeReaderValue<Double_t> azi = {fReader, "azi"};
   TTreeReaderValue<Double_t> xc = {fReader, "xc"};
   TTreeReaderValue<Double_t> yc = {fReader, "yc"};
   TTreeReaderValue<Double_t> zenc = {fReader, "zenc"};
   TTreeReaderValue<Double_t> azic = {fReader, "azic"};
   TTreeReaderValue<Double_t> xc1 = {fReader, "xc1"};
   TTreeReaderValue<Double_t> yc1 = {fReader, "yc1"};
   TTreeReaderValue<Double_t> rmd20 = {fReader, "rmd20"};
   TTreeReaderValue<Double_t> omega = {fReader, "omega"};
   TTreeReaderValue<Double_t> chi2p = {fReader, "chi2p"};
   TTreeReaderValue<Double_t> chi2c = {fReader, "chi2c"};
   TTreeReaderValue<Double_t> compactness = {fReader, "compactness"};
   TTreeReaderValue<Double_t> pincness = {fReader, "pincness"};
   TTreeReaderArray<Double_t> CXPE = {fReader, "CXPE[10]"};
   TTreeReaderArray<Double_t> Top5s = {fReader, "Top5s[5]"};
   TTreeReaderArray<Double_t> Top5r = {fReader, "Top5r[5]"};
   TTreeReaderValue<Double_t> inters = {fReader, "inters"};
   TTreeReaderValue<Double_t> intern = {fReader, "intern"};
   TTreeReaderValue<Double_t> outers = {fReader, "outers"};
   TTreeReaderValue<Double_t> outern = {fReader, "outern"};
   TTreeReaderValue<Double_t> recflag = {fReader, "recflag"};


   LHAASOEvent(TTree * /*tree*/ =0) { }
   virtual ~LHAASOEvent() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(LHAASOEvent,0);

};

#endif

#ifdef LHAASOEvent_cxx
void LHAASOEvent::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t LHAASOEvent::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef LHAASOEvent_cxx
