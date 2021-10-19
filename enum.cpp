#include<iostream>
using namespace std;
enum Roster {Tom = 1, Sharon, Bill};
int main() {
    int who;
    cout << "please input" << endl;
    cin >> who;
    switch (who)
    {
    case Tom:
        cout << "Tom's birthday is 1" << endl;
        break;
    case Sharon:
        cout << "Sharon's birthday is 2" << endl;
        break;
    case Bill:
        cout << "Bill's birthday is 3" << endl;
        break;
    default:
        cout << "Other's birthday is 4" << endl;
        break;
    }
    cout << Tom << endl;
    return 0;

}