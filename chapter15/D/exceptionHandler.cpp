#include <iostream>

using namespace std;
// a exception handler example
int main() {
    int a, b;
    cout << "Input two number" << endl;
    cin >> a >> b;
    try {
        if (a == b) {
            throw "exception: a is equal to b";
        } else {
            cout << "a is unequal to b" << endl;
        }
    } catch(const char * s) {
        cout << s;
    }
    return 0;
}