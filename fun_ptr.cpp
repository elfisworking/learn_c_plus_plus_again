#include <iostream>
using namespace std;
double betsy(int);
double pam(int);
void estimate(int lines, double (*fp)(int));

int main() {
    int code;
    cout << "how many lines of code do you need? \n";
    cin >> code;
    cout << "Here's betsy's estimate \n";
    estimate(code, betsy);
    cout << "Here's pam's estimate \n";
    estimate(code, pam);
    return 0;
}

double betsy(int lns) {
    return 0.05 * lns;
}

double pam(int lns) {
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*fp)(int)) {
    cout << lines << " lines will take ";
    cout << fp(lines) << " hours \n";
}