void Polar()
{
	const Int_t npoints=4;
	auto canvas_4_2 = new TCanvas("myCanvas","myCanvas",800,800);
	double azimuth[npoints] = {-20,-19,-17,-18};

	double zenith[npoints] = {28,29,28.5,27};
	double Azimuth[npoints];// = {-20,-19,-18,-17};
	double Zenith[npoints];// = {28,29,28.5,27};
	double azi;
	for (Int_t ipt = 0; ipt < npoints; ipt++) {
		azi = azimuth[ipt];
		Azimuth[ipt] = azi*TMath::DegToRad();
		printf("%lf\n",Azimuth[ipt]);
		Zenith[ipt] = zenith[ipt];
	}
	TGraphPolar *grP1 = new TGraphPolar(npoints,Azimuth,Zenith);
	grP1->SetTitle("A Fan");
	grP1->SetMarkerStyle(8);
	grP1->SetMarkerSize(1.);
	grP1->SetMarkerColor(4);
	grP1->SetMinPolar(0);
	grP1->SetMaxPolar(2*TMath::Pi());
	grP1->SetMinRadial(0);
	grP1->SetMaxRadial(90);
	grP1->Draw("P");
	canvas_4_2->Update();
	grP1->GetPolargram()->SetToRadian();
	canvas_4_2->Draw();
}
