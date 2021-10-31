#include <iostream>
#include "tv.h"

using namespace std;
int main() {
    TV tv;
    tv.setNum(10);
    tv.setChannel(20);
    Remote remote;
    cout << remote.getNum(tv) << " " << remote.getChannel(tv) << endl;
    return 0;
}