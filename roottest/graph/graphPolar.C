void graphPolar()
{
	auto canvas_4_2 = new TCanvas("myCanvas","myCanvas",800,800);
	Double_t rmin=0.;
	Double_t rmax=TMath::Pi()*6.;
	const Int_t npoints=1000;
	Double_t r[npoints];
	Double_t theta[npoints];
	for (Int_t ipt = 0; ipt < npoints; ipt++) {
		r[ipt] = ipt*(rmax-rmin)/npoints+rmin;
		theta[ipt] = TMath::Sin(r[ipt]);
	}
	TGraphPolar grP1 (npoints,r,theta);
	grP1.SetTitle("A Fan");
	grP1.SetLineWidth(3);
	grP1.SetLineColor(2);
	grP1.DrawClone("L");
	canvas_4_2->Draw();
}
