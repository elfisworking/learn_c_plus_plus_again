// arrstruc.cpp -- an array of structures
#include <iostream>
using namespace std;
struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main() {
    inflatable guests[2] = {
        {"Bambi", 0.5, 21.99},
        {"Godzilla", 2000, 565.99}
    };

    cout << guests[0].price << guests[1].price << endl;
    return 0;
}