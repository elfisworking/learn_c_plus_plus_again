#include <iostream>
#include "tvf.h"

using namespace std;

int main() {
    TV tv;
    tv.setNum(10);
    Remote remote;
    cout << remote.getNum(tv) << endl;
    return 0;
}