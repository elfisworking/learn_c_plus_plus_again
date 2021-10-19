#include<iostream>
using namespace std;
int main() {
    double * p3 = new double[3];
    p3[0] = 1.2;
    p3[1] = 2.2;
    p3[2] = 3.2;
    cout << *p3 << " " << p3[0] << endl;
    p3++;
    cout << *p3 << " " << p3[1] << endl;
    p3++;
    cout << *p3 << " " << p3[2] << endl;
    p3 = p3 - 2;
    delete [] p3;
    return 0;
}