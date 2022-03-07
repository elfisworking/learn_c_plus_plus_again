#include <iostream>
#include <sstream>
using namespace std;
class Complex {
private:
    int real;
    int imag;
public:
    Complex(int x, int y):real(x),imag(y) {}
    int getReal() {
        return real;
    }
    int getImag() {
        return imag;
    }
    Complex operator+(Complex &b) {
        Complex x(this->real + b.getReal(), this->imag + b.getImag());
        return x;
    }
};

ostream& operator<<(ostream& ss, Complex& x) {
    ss << x.getReal() << " + " << x.getImag() << " i" << endl;
    return ss;
}
int main() {
    Complex a(2, 3);
    Complex b(4, 5);
    Complex x = a + b;
    cout << x.getImag() << endl ;
    cout << x;
    return 0;
}