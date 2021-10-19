#include<iostream>
using namespace std;
int main() {
    int nights = 1001;
    int * pt = new int;
    *pt = 1001;
    cout << "nights value " << nights << " location " << &nights << endl;
    cout << "pt value " << *pt << "location " << pt << endl;
    double * pd = new double;
    *pd = 1000001.0;
    cout << "size of pt " << sizeof(pt) << endl;
    cout << "size of *pt " << sizeof(*pt) << endl;
    cout << "size of pd " << sizeof(pd) << endl;
    cout << "size of *pd " << sizeof(*pd) << endl;
    return 0;
}
