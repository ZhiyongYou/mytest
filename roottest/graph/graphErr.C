{
	TCanvas canvas_2_5;
	TGraphErrors gr("./ExampleData.txt");
	gr.Draw("AP");
	canvas_2_5.Draw();
}
