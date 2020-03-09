#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double i = floor(2.2);
    double i1 = floor(2.6);
    double j = floor(-2.2);
    double j1 = floor(-2.6);
    double k = ceil(2.2);
    double k1 = ceil(2.6);
    double m = ceil(-2.2);
    double m1 = ceil(-2.6);
    double n = round(2.2);
    double n1 = round(2.6);
    double l = round(-2.2);
    double l1 = round(-2.6);
    cout << "The floor of 2.2 is " << i << endl;
    cout << "The floor of 2.6 is " << i1 << endl;
    cout << "The floor of -2.2 is " << j << endl;
    cout << "The floor of -2.6 is " << j1 << endl;
    cout << "The ceil of 2.2 is " << k << endl;
    cout << "The ceil of 2.6 is " << k1 << endl;
    cout << "The ceil of -2.2 is " << m << endl;
    cout << "The ceil of -2.6 is " << m1 << endl;
    cout << "The round of 2.2 is " << n << endl;
    cout << "The round of 2.6 is " << n1 << endl;
    cout << "The round of -2.2 is " << l << endl;
    cout << "The round of -2.6 is " << l1 << endl;
    //system("pause");
    return 0;
}
