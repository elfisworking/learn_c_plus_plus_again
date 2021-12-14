#include<iostream>
#include<vector>
using namespace std;
void func(vector<int> & a) {
    int b = a.size();
    int a[b];
    a[0] = 2;
    cout << a[0] << endl;
    
}

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    func(a);
    return 0;
}