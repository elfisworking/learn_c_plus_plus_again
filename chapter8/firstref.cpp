#include <iostream>
using namespace std;
int main() {
    int rats = 1024;
    cout << "rats: " << rats << endl;
    int & ref = rats;
    ref++;
    cout << "rats: " << rats << " ref: " << ref << endl;
    cout << "address rats's is " << &rats << endl;
    cout << "address ref's is " << &ref << endl;
    return 0;
}