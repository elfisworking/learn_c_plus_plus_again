#include<iostream>
using namespace std;

int main() {
    int tmp = 5;
    int* ptr = &tmp;
    cout << tmp << &tmp << endl;
    cout << *ptr << ptr << endl;
    return 0;
}