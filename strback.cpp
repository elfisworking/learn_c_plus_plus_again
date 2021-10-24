#include <iostream>
using namespace std;
char * buildstr(char c, int n); // prototype
int main() {
    int times;
    char ch;
    cout << "Enter a character" << endl;
    cin >> ch;
    cout << "Enter a integer" << endl;
    cin >> times;
    char * ps = buildstr(ch, times);
    cout << ps << endl;
    delete [] ps;
    ps = buildstr('+', 20);
    cout << ps << "-DONE-" << ps << endl;
    delete [] ps;
    return 0; 
}

char * buildstr(char c, int n){
    char * ptr = new char[n + 1];
    ptr[n] = '\0';
    while (n-- > 0) {
        ptr[n] = c;
    }
    return ptr;
}