#ifndef ACCTABC_H
#define ACCTABC_H
#include <iostream>
using namespace std;

class AccABC {
    private:
        double balance;
    protected:
      double pro;
    public:
        void setBalance(double _balance);
        void setPro(double _pro);
        double getPro() const ;
        double getBalance() const;
        virtual double add() = 0;
        virtual ~AccABC() {}
        AccABC();
        AccABC(double _balance = 0, double _pro = 0);
};
class Child1 : public AccABC {
    public:
        Child1();
        Child1(double _balance = 0, double _pro = 0) :AccABC(_balance, _pro) {}
        virtual double add();

};

class Child2 : public AccABC {
    public :
        Child2();
        Child2(double _balance = 0, double _pro = 0) : AccABC(_balance, _pro) {}
        virtual double add();
};

#endif