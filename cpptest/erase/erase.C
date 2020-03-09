// CPP program to illustrate 
// // Implementation of erase() function 
#include <iostream> 
#include <vector> 
using namespace std; 

int main() 
{ 
	vector<int> myvector{ 5, 2, 3, 4, 5 }; 
	for (auto it = myvector.begin(); it != myvector.end(); ++it) 
		cout << ' ' << *it;
	cout<<endl;

	cout<<"begin+2:"<<*(myvector.begin()+2)<<endl;

	myvector.erase(myvector.begin(), myvector.begin()+2+1);

	// Printing the Vector
	for (auto it = myvector.begin(); it != myvector.end(); ++it) 
		cout << ' ' << *it;
	cout<<endl;
	return 0; 
} 
