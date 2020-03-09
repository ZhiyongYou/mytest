{
	TCanvas canvas_2_5;
	TGraphErrors gr("./lgain.txt");
	gr.Draw("AP");
	canvas_2_5.Draw();
}
