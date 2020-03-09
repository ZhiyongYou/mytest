// Builds a graph with errors, displays it and saves it as
// image. First, include some header files
// (not necessary for Cling)
//#include <iostram>
#include "TROOT.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"
void canvas()
{ 
	//#1
	// The values and the errors on the Y axis
	const int n_points=10;
	double x_vals[n_points]={1,2,3,4,5,6,7,8,9,10};
	double y_vals[n_points]={6,12,14,20,22,24,35,45,44,53};
	double y_errs[n_points]={5,5,4.7,4.5,4.2,5.1,2.9,4.1,4.8,5.43};
	// Instance of the graph
	//#2
	TGraphErrors graph(n_points,x_vals,y_vals,NULL,y_errs);
	graph.SetTitle("Measurement XYZ;lenght in cm;Arb Units");
	// Make the plot estetically better
	//#3
	graph.SetMarkerStyle(kOpenCircle);
	graph.SetMarkerColor(kBlue);
	graph.SetLineColor(kBlue);
	graph.SetFillColor(kYellow);
	// The canvas on which we’ll draw the graph
	//#4
	TCanvas *Canvas_3_2_1 = new TCanvas();
	// Draw the graph !
	//#5
	graph.DrawClone("AE3L");
	graph.DrawClone("PE");
	// Define a linear function
	//#6
	TF1 function_3_2_1("Linear law","[0]+x*[1]",.5,10.5);
	// Let’s make the funcion line nicer
	//#7
	function_3_2_1.SetLineColor(kRed); function_3_2_1.SetLineStyle(2);
	// Fit it to the graph and draw it
	//#8
	graph.Fit(&function_3_2_1);
	function_3_2_1.DrawClone("Same");
	// Build and Draw a legend
	//#9
	TLegend leg(.2,.7,.5,.9,"Lab. Lesson 1");
	leg.SetFillColor(0);
	graph.SetFillColor(0);
	leg.AddEntry(&graph,"Exp. Points");
	leg.AddEntry(&function_3_2_1,"Th. Law");
	leg.DrawClone("Same");
	// Draw an arrow on the canvas
	//#10
	TArrow arrow(8,8,6.2,23,0.02,"|>");
	arrow.SetLineWidth(2);
	arrow.DrawClone();
	// Add some text to the plot
	//#11
	TLatex text(8.2,7.5,"#splitline{Maximum}{Deviation}");
	text.DrawClone();
	/*this command will create a pdf file with the graph in the same folder.
	 * If you want to use it you can uncoment it and comment the Draw command bellow.*/
	//#12
	//mycanvas->Print("graph_with_law.pdf");
	Canvas_3_2_1->Print("graph_with_law.pdf(","pdf");
	Canvas_3_2_1->Clear();
	Canvas_3_2_1->Print("graph_with_law.pdf)","pdf");
	//TCanvas* cnew=new TCanvas();
	//cnew->Print(Form("CheckResulte/%04d_tel%02d_Routinue.pdf)",date,telescope),"pdf");
	//delete cnew;
}

int main()
{
	canvas();
	return 0;
}




