void outflowBin()
{
	TCanvas *canvas = new TCanvas("canvas","canvas",800,600);

	TH1D *hist = new TH1D("hist","hist",15,0,15);
	hist->Fill(-1);
	for(int i=0;i<20;i++)
	{
		int loop = i+1;
		for(int j=0;j<loop;j++)
		{
			hist->Fill(i);
		}
	}
	
	double underflow = hist->GetBinContent(0);
	double bincontent[10];
	for(int i=0;i<10;i++)
	{
		bincontent[i] = hist->GetBinContent(i+1);
		printf("%d: %.2lf\n",i+1,bincontent[i]);
	}
	int Nbins = hist->GetNbinsX();
	int binsY = hist->GetNbinsY();
	int binsZ = hist->GetNbinsZ();
	printf("bins of hist:%d %d %d\n",Nbins,binsY,binsZ);
	double overflow = hist->GetBinContent(Nbins+1);
	printf("%.2lf %.2lf\n",underflow,overflow);
	hist->Draw();
}
