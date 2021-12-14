#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    // cin get()
    char ch;
    while( (ch = cin.get()) != '\n') 
        cout << ch;
    cout << endl;
    char * str;
    cout<< "using cin.get(chat *, int)" << endl;
    cin.get(str, 10);
    cout << str << endl;
    cout << "cin.get() function has been used." << endl;
    cout << "using cin.getline() function" << endl;
    // cin.getline()
    // cin >> 
    int a ,b ,c;
    cout << "input 3 parameters" << endl;
    cin >> a >> b >> c ;
    cout << a << b << c << endl;
    scanf("%d%d%d", &a ,&b, &c);
    printf("a = %d , b = %d, c = %d\n", a, b, c);
    return 0;
}