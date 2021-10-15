#include <iostream>
#include <vector>

int main() {
    using namespace std;
    vector<int> test;
    test.push_back(1);
    for(auto x = test.begin(); x != test.end(); x++) {
        cout << *x << endl;
    }
    return 0;
}