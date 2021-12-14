#include<iostream>
using namespace std;
int main() {
    int a = 1;
    int & b = a;
    int c = 2;
    b = c;
    b = 4;
    cout << b << c << endl;
    abort();
    return 0;

}