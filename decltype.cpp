#include<iostream>
#include<typeinfo>
using namespace std;

int main() {
    int a = 1;
    decltype(a) b = 2;
    decltype((a)) c = b;
    c = 3;
    cout << typeid(b).name() << " " << typeid(c).name() << endl; // int b; int & c = b; c is reference type
    cout << b << " " << c;
    return 0;
}