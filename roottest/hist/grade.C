void grade()
{
	double grade[100]={0};
	double ge_grade[100]={0};
	for(int i=1;i<101;i++)
	{
		grade[i-1] = i;
		ge_grade[i-1] = 1+3*(100-i)/40.;
	}
	TCanvas *canvas = new TCanvas("canvas","canvas",800,800);
	TGraph *g = new TGraph(100,grade,ge_grade);
	canvas->SetGridx();
	canvas->SetGridy();
	g->SetMarkerStyle(2);
	g->Draw("AP");
}
