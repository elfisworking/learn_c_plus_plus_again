#include <iostream>
#include "acctabc.h"
using namespace std;

int main() {
    AccABC * child1 = new Child1(2, 2);
    AccABC * child2 = new Child2(3, 3);
    cout << "child1 pro value is " << child1->getBalance() << " child2 pro value is "<< child2->getPro() << endl;
    cout << child1->add() << endl;
    cout << child2->add() << endl;
    return 0;
}