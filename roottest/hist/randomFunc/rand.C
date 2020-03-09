{
	TCanvas canvas_2_6;
	TF1 efunc("efunc","exp([0]+[1]*x)",0.,5.);
	efunc.SetParameter(0,1);
	efunc.SetParameter(1,-2);
	TH1F hist_2_6_1("histogram 2.6.1","example histogram",100,0.,5.);
	for (int i=0;i<1000000;i++) {hist_2_6_1.Fill(efunc.GetRandom());}
	hist_2_6_1.Draw();
	canvas_2_6.Draw();
}
