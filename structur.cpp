#include <iostream>

struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main() {
    using namespace std;
    inflatable guest = {
        "Gloria",
        1.88,
        29.99
    };
    cout << guest.name << endl;
    return 0;

}