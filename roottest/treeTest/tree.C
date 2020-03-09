void tree()
{
	struct event
	{
		double energy;
		double p;
		int x;
		int y;
		int z;
	};
	event aevent;
	TFile* f = new TFile("test.root","recreate");
	TTree* Tr = new TTree("Tr","tr test");
	Tr->Branch("aevent",&aevent,"energy/D:p/D:x/I:y:z");//order is agree with struct event
	for(int i=0;i<10;i++)
	{
		aevent.x = i;
		aevent.y = i+1;
		aevent.z = i+2;
		aevent.energy = 10.8;
		aevent.p = 10.9;
		Tr->Fill();
	}
	f->Write();
	f->Close();
}
