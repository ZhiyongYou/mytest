llma()
{
  TFile *file = new TFile("0610.4.500.root");
  TF1 *func = new TF1("fit",fitf,0,10000,2);
  func->SetParameters(10000,-1);

  cosmicEvent->Draw("CleanImagePe","CleanImagePe<8000&&repeat==0")
  // h_adc_high_300->Draw();
  // h_adc_high_300->Fit("fit","","",0,2000);

}
Double_t fitf(Double_t *x,Double_t *par)
{
  Double_t fitval;
  fitval = par[0]*pow(x[0],par[1]);
  //if(x[0]<500)
  //  fitval = par[0]/par[1]*exp(-(x[0]-par[2])*(x[0]-par[2])/pow(par[1],2));
  //else
  //  fitval = par[3]*pow(x[0],par[4]);
  return fitval;
}
