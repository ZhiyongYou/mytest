void format_h(TH1F* h, int linecolor)
{
	h->SetLineWidth(3);
	h->SetLineColor(linecolor);
}
void addANDdivide()
{
	auto sig_h=new TH1F("sig_h","Signal Histo",50,0,10);
	auto gaus_h1=new TH1F("gaus_h1","Gauss Histo 1",30,0,10);
	auto gaus_h2=new TH1F("gaus_h2","Gauss Histo 2",30,0,10);
	auto bkg_h=new TH1F("exp_h","Exponential Histo",50,0,10);
	// simulate the measurements
	TRandom3 rndgen_5_2;
	for (int imeas=0; imeas<4000; imeas++){
		bkg_h->Fill(rndgen_5_2.Exp(4));
		if (imeas%4==0) gaus_h1->Fill(rndgen_5_2.Gaus(5,2));
		if (imeas%4==0) gaus_h2->Fill(rndgen_5_2.Gaus(5,2));
		if (imeas%10==0)sig_h->Fill(rndgen_5_2.Gaus(5,.5));
	}
	// Format Histograms
	int i=0;
	for (auto hist : {sig_h,bkg_h,gaus_h1,gaus_h2})
		format_h(hist,1+i++);
	// Sum
	auto sum_h= new TH1F(*bkg_h);
	sum_h->Add(sig_h,1.);
	sum_h->SetTitle("Exponential + Gaussian;X variable;Y variable");
	format_h(sum_h,kBlue);
	auto canvas_5_2_sum= new TCanvas("GausExp","GausExp",1200,800);
	sum_h->Draw("hist");
	bkg_h->Draw("SameHist");
	sig_h->Draw("SameHist");
	// Divide
	auto dividend=new TH1F(*gaus_h1);
	dividend->Divide(gaus_h2);
	// Graphical Maquillage
	dividend->SetTitle(";X axis;Gaus Histogram 1 / Gaus Histogram 2");
	format_h(dividend,kOrange);
	gaus_h1->SetTitle(";;Gaus Histo 1 and Gaus Histo 2");
	gStyle->SetOptStat(0);
	TCanvas* canvas_5_2_divide= new TCanvas("divide","divide",1200,800);
	canvas_5_2_divide->Divide(1,2,0,0);
	//canvas_5_2_divide->Divide(1,2);
	canvas_5_2_divide->cd(1);
	canvas_5_2_divide->GetPad(1)->SetRightMargin(.01);
	gaus_h1->DrawNormalized("Hist");
	gaus_h2->DrawNormalized("HistSame");
	canvas_5_2_divide->cd(2);
	canvas_5_2_divide->GetPad(2)->SetGridy();
	canvas_5_2_divide->GetPad(2)->SetRightMargin(.01);
	dividend->Draw();
	canvas_5_2_sum->Draw();
	canvas_5_2_divide->Draw();
}























