#include <iostream>
using namespace std;
#include <vector>
void show(vector<int>& a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> a{1,3,5,4,2};
    sort(a.begin(), a.end(), [](int a, int b){return a < b;});
    show(a);
    sort(a.begin(), a.end(), greater<int>());
    show(a);
    return 0;
}