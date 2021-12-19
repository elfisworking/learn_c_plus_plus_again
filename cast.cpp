// 四种类型转换
#include <iostream>
using namespace std;
int main() {
    const int a = 10;
    int * b =  const_cast<int *>(&a);
    int c = static_cast<int>(*b);
    cout << a << " " << b << " " << c << endl;
    return 0;
}