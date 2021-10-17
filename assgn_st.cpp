#include <iostream>
using namespace std;
// 结构赋值
struct inflatbale {
    char name[20];
    float volume;
    double price;
};
// anonymous struct
struct {
    int x;
    int y;
} position; // a structure variable

struct perks {
    int key_member;
} var1, var2; // two structure variable

struct park{
    char location[20];
} park1 = {
    "london"
};



int main() {
    inflatbale bouguet = {"sunflower", 12.0, 123};
    cout<< "bouguet volume:" << bouguet.volume << "bouguet price: " << bouguet.price << endl;
    inflatbale choice;
    choice = bouguet;
    choice.price = 120; // 成员赋值 memberwise assignment
    cout << "choice price is " << choice.price << " bouguet price is " << bouguet.price << endl;
    return 0;
}