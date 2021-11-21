#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

void process(int a[][4], int n, int m) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            *(*(a + i) + j) /= *(*(a + i) + j);
        }
}

int main() {
    int a[][4] = {1, 2, 3, 4, 3, 4, 5, 6, 5,6, 7, 8};
    process(a, 3, 4);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    int x = 123;
    int * ptr = &x;
    *ptr = 125;
    cout << x << endl;
    int array[2][2] = {{1,2},{3,4}};
    cout << *(array[0] + 1) << endl;
    return 0;
}