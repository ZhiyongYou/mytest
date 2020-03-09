hist()
{
  TFile rootfile("hist.root","recreate");
  TCanvas image;
  //image("image","image",800,800);
  TH1D his;
  //his("his","his",100,-3,3);
  for(int i=0;i<1000;i++){
    his.Fill(gRandom->Gaus(0,1));
  }
  his.Draw();
  image.Write();
  //rootfile.Close();

}
