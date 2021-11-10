#include<iostream>
using namespace std;
class A {
    public:
    int data;
    A(int data) {
        cout << "using A(int data)" << endl;
        this->data = data;
    }
    A(const A && a) {
        cout << "using A(int & data)" << endl;
        this->data = a.data;
    }
    ~A() {
        cout << "using ~A() function" << endl;
    }
};

A get() {
    A tmp(1);
    return tmp;
}

void show(A a) {
    cout << a.data << endl;
}

void show(int )
int main() {
    A a = get();
    show(get());
    return 0;
}