/// \file
/// \ingroup tutorial_hist
/// \notebook
/// This tutorial illustrates how to create an histogram with polygonal
/// bins (TH2Poly). The bins are boxes.
///
/// \macro_image
/// \macro_code
///
/// \author Olivier Couet

TCanvas *th2polyBoxes() {
   TCanvas *ch2p2 = new TCanvas("ch2p2","ch2p2",800,800);
   gStyle->SetPalette(57);
   TH2Poly *h2p = new TH2Poly();
   h2p->SetName("Boxes");
   h2p->SetTitle("Boxes");

   Int_t i,j;
   Int_t nx = 40;
   Int_t ny = 40;
   Double_t xval1,yval1,xval2,yval2;
   Double_t dx=0.1, dy=0.1;
   xval1 = 0.;
   xval2 = dx;

   int ibin=0;
   for (i = 0; i<nx; i++) {
      xval1 = dx*i;
      xval2 = dx*(i+1);
      for (j = 0; j<ny; j++) {
		  yval1 = dy*j;
		  yval2 = dy*(j+1);
		  h2p->AddBin(xval1, yval1, xval2, yval2);
		  double binc_x = (xval1+xval2)/2;
		  double binc_y = (yval1+yval2)/2;
		  ibin++;
		  h2p->Fill(binc_x,binc_y,ibin);
      }
   }

   //h2p->Draw("colz textn");
   h2p->Draw("COLZ");
   return ch2p2;
}
