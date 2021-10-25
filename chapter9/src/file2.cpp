#include <iostream>
#include <cmath>
#include "coordin.h"
using namespace std;

polar rect_to_polar(rect x){
    polar ans;
    cout << x.x << x.y << endl;
    ans.distance = sqrt( x.x * x.x + x.y * x.y);
    ans.angle = atan2(x.y, x.x);
    return ans;
}

void show_polar(polar pos){
    cout << pos.angle << endl;
    cout << pos.distance << endl;
}