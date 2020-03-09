{
	gStyle->SetPalette(kDeepSea);
	gStyle->SetPalette(kCherry);
	gStyle->SetPalette(kCool);
	gStyle->SetPalette();
	//TColor::InvertPalette();
	TF2 *f2 = new TF2("f2","0.1+(1-(x-2)*(x-2))*(1-(y-2)*(y-2))",1,3,1,3);
	TF2 *f3 = new TF2("f3","0.1+(1-(x-2)*(x-2))*(1-(y-2)*(y-2))",1,3,1,3);
	TCanvas *c2  = new TCanvas("c2","c2",0,0,1600,600);
	c2->Divide(2,1);
	c2->cd(1);
	f2->Draw("surf2");
	c2->cd(2);
	f3->Draw("surf1");
	return c2;
}
