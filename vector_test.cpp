#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    vector<int> b{0,4};
    vector<int> d(4,0);
    vector<int> c{0};
    cout << b.size() << " " << c.size() << " " << d.size() <<  endl;
    return 0;
}