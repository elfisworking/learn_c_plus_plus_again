#include<iostream>
using namespace std;
struct widget {
    char brand[20];
    int type;
    union id {
        long id_num;
        char id_char[20];
    } id_val;
};

int main() {
    widget price;
    int type;
    cout << "input type" << endl;
    cin >> type;
    price.type = type;
    if (price.type == 1) {
        cin >> price.id_val.id_num;
    }else {
        cin >> price.id_val.id_char;
    }
    cout << price.id_val.id_num <<endl;
    return 0;
}