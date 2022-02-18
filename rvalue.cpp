#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
class A {
    public:
        A(){
            std::cout << "A construct..." << std::endl;
            ptr_ = new int(100);
        }

        A(const A & a){
            std::cout << "A copy construct ..." << std::endl;
            ptr_ = new int();
            memcpy(ptr_, a.ptr_, sizeof(int));
        }

        ~A(){
            std::cout << "A deconstruct ..." << std::endl;
            if(ptr_){
                delete ptr_;
            }
        }

        A& operator=(const A & a) {
            std::cout << " A operator= ...." << std::endl;
            return *this;
        }

        int * getVal(){
            return ptr_;
        }
    private:
        int *ptr_;
};
A get() {
    return A();
}

int main(int argc, char *argv[]){
    // A && a = get();
    // cout << "==============" << endl;
    A b = get();
    return 0;
}


