#include <iostream>

int main() {
    using namespace std;
    int auks, bats, coots;

    auks = 19.99 + 11.99;

    bats = (int)19.99 + (int)11.99;

    coots = int(19.99) + int(11.99);

    cout << "auks is " << auks << endl;
    cout << "bats is " << bats << endl;
    cout << "coots is " << coots << endl;

    char ch = 'Z';
    cout << "the code for " << ch << " is " << int(ch) << endl;
    // c++ force convert style : static_cast<typeName>(value)
    cout << "also code is " << static_cast<int>(ch) << endl;
    return 0;
}