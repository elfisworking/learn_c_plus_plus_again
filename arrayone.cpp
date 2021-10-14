#include <iostream>

int main() {
    using namespace std;
    int yams[3];
    yams[0] = 1;
    yams[1] = 2;
    yams[2] = 3;
    int yamcost[3] = {20, 30, 5};
    cout << sizeof yams << endl;
    cout << sizeof yamcost[0] << endl;
    // output yams's memory address
    cout << yams << endl;
    cout << yamcost[0] << endl;
    return 0;
}