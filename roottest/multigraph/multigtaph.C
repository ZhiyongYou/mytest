#include <vector>
void multigtaph()
{
	TCanvas *canvas_4_4 = new TCanvas("canvas_4_4","multigraph",700,500);
	canvas_4_4->SetGrid();
	TMultiGraph *multigraph_4_4 = new TMultiGraph("mg","mg");

	// create first graph
	std::vector<double> px1 {-0.1, 0.05, 0.25, 0.35, 0.5, 0.61, 0.7, 0.85, 0.89, 0.95};
	std::vector<double> py1 {-1,2.9,5.6,7.4,9,9.6,8.7,6.3,4.5,1};
	std::vector<double> ex1 {.05,.1,.07,.07,.04,.05,.06,.07,.08,.05};
	std::vector<double> ey1 {.8,.7,.6,.5,.4,.4,.5,.6,.7,.8};
	const Int_t n1 = px1.size();
	TGraphErrors *error_graph_1 = new TGraphErrors(n1,px1.data(),py1.data(),ex1.data(),ey1.data());
	error_graph_1->SetMarkerColor(kBlue);
	error_graph_1->SetMarkerStyle(21);
	multigraph_4_4->Add(error_graph_1);

	// create second graph
	std::vector<float> x2 {-0.28, 0.005, 0.19, 0.29, 0.45, 0.56,0.65,0.80,0.90,1.01};
	std::vector<float> y2 {2.1,3.86,7,9,10,10.55,9.64,7.26,5.42,2};
	std::vector<float> ex2 {.04,.12,.08,.06,.05,.04,.07,.06,.08,.04};
	std::vector<float> ey2 {.6,.8,.7,.4,.3,.3,.4,.5,.6,.7};
	const Int_t n2 = x2.size();
	TGraphErrors *error_graph_2 = new TGraphErrors(n2,x2.data(),y2.data(),ex2.data(),ey2.data());
	error_graph_2->SetMarkerColor(kRed);
	error_graph_2->SetMarkerStyle(20);
	multigraph_4_4->Add(error_graph_2);

	multigraph_4_4->Draw("APL");
	multigraph_4_4->GetXaxis()->SetTitle("X values");
	multigraph_4_4->GetYaxis()->SetTitle("Y values");
	canvas_4_4->Draw();
}
