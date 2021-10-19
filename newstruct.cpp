#include<iostream>
using namespace std;
struct inflatable {
    char name[20];
    float volume;
    double price;
};
int main() {
    inflatable * ptr = new inflatable;
    cout << "Enter name of inflatble item" << endl;
    cin >> ptr->name;
    cout << "Enter volume in cubic feet" << endl;
    cin >> (*ptr).volume;
    cout << "Enter price" << endl;
    cin >> ptr->price;
    cout << (*ptr).name << " " << ptr->price << " " << ptr->volume << endl;
    delete ptr;
    return 0;
}