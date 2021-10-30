#include "acctabc.h"
void AccABC::setBalance(double _balance) {
    balance = _balance;
}
void AccABC::setPro(double _pro) {
    pro = _pro;
}

double AccABC::getPro() const {
    return pro;
}

double AccABC::getBalance() const {
    return balance;
}

AccABC::AccABC(double _balance, double _pro) {
    balance = _balance;
    pro = _pro;
}

double Child1::add() {
    double temp = pro;
    temp++;
    return temp;
}

double Child2::add() {
    double temp = pro;
    temp += 2;
    return temp;
    
}
