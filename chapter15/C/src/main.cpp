#include <iostream>
#include <cstdlib>

using namespace std;

double hmean(double x, double y);

int main() {
    cout << " No exception " << endl;
    cout << hmean(1, 1) << endl;
    cout << "Exception happen " << endl;
    double x = 1, y = -1;
    hmean(x, y);
    return 0;
}

double hmean(double x, double y) {
    if ( x == -y) {
        cout << "intenable arguments to hmean" << endl;
        abort(); 
    }
    return 2.0 * x * y / (x + y);
}