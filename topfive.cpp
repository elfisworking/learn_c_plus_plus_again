#include <iostream>
#include <string>
using namespace std;
const int SIZE = 5;
void display(const string a[], int n);
int main() {
    string a[SIZE];
    cout << "Enter your " << SIZE << " favouriate sights\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << ":";
        getline(cin, a[i]);
    }
    cout << "Your list\n";
    display(a, SIZE);
    return 0;
}
void display(const string a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " :" << a[i] << endl;
    }
}