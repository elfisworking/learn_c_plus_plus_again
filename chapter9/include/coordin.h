#ifndef COORDIN_H_
#define COORDIN_H_

struct polar{
    double distance;
    double angle;
};

struct rect {
    double x;
    double y;
};

polar rect_to_polar(rect x);
void show_polar(polar pos);


#endif