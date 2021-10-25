#include <iostream>
using namespace std;
template <typename T>
void Swap(T &a, T &b);

int main() {
    int i = 1;
    int j = 2;
    double a = 3;
    double b = 4;
    Swap(a, b);
    Swap(i, j);
    cout << "a " << a << " b " << b << endl;
    cout << "i " << i << " j " << j << endl;
    return 0;
}
template <typename T>
void Swap(T &a ,T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}