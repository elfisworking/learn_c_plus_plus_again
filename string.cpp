#include <iostream>
#include <cstring>
int main() {
    using namespace std;
    const int Size =15;
    char name1[Size];
    char name2[Size] = "C++ Hello";
    cout << "Please input length < 15" << endl;
    cin >> name1;
    cout << "input is " << name1 << endl;
    cout << "size of name1 is " << sizeof name1 << endl;
    cout << "length of name1 is " << strlen(name1) << endl;
    name2[3] = '\0';
    cout << name2 << endl;
    return 0;
}