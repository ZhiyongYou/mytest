#include <iostream>  
#include <algorithm>  
#include <vector>  

using namespace std;  

int main ()   
{  
	vector<int> myvector1 = {1, 2, 3, 4, 5, 60, 7};  
	vector<int> myvector2;  

	myvector2.assign(myvector1.begin(),myvector1.end());

	cout << "myvector contains: ";  
	for ( int ii = 0;  ii < myvector2.size();  ++ii )  
	{  
		cout << " " << myvector2.at(ii); 
	}  
	cout << endl;  

	return 0;  
}  
