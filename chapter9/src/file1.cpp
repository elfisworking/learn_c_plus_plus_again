#include <iostream>
#include "coordin.h"
using namespace std;

int main() {
    rect replace;
    polar pplace;
    cout << "Enter x and y values" << endl;
    cin >> replace.x >> replace.y;
    pplace = rect_to_polar(replace);
    show_polar(pplace);
    return 0;
}