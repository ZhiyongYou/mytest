void drawNomalized()
{
  TCanvas *image = new TCanvas();
  //image("image","image",800,800);
  TH1D *his = new TH1D("his","his",100,-5,5);
  //his("his","his",100,-3,3);
  for(int i=0;i<200000;i++){
    his->Fill(gRandom->Gaus(0,1));
  }
  his->DrawNormalized();
  //rootfile.Close();

}
