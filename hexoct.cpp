#include <iostream>
int main() {
    using namespace std;
    int chest = 42;   // decimal integer literal
    int waist = 0x42; // hexadecimal integer literal
    int inseam = 042; // octal integer literal

    cout << chest << " 42 in decimal " << endl;
    cout << waist << " 0x42 in hexadecimal " << endl;
    cout << inseam << " 042 in octal" << endl;
    return 0;

}