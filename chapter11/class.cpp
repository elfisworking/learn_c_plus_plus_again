#include <iostream>
using namespace std;
class A {
    private:
        int a;
    public:
        A(int b);
        int get_a(){return a;}
        void set_a(int b);

};

A::A(int b){
    this->a = b;
}
void A::set_a(int b) {
    this->a = b;
}

int add(int value,A &a) {
    return value + a.get_a();
}

int main() {
    A a(26);
    cout << a.get_a() << endl;
    A &b = a;
    int value = add(10, b);
    cout << value << endl;
    return 0;
}