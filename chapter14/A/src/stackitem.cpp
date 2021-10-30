#include <iostream>
#include "stacktp.h"

using namespace std;

int main() {
    Stack<int> stack;
    stack.push(100);
    stack.push(200);
    int popValue = 0;
    stack.pop(popValue);
    cout << popValue << endl;
    return 0;
}