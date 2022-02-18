#include<iostream>
#include<vector>
using namespace std;
class Bagel {
    public:
        Bagel(vector<string>& ts) : top(move(ts)){}
        string getval() {
            return top[top.size() - 1];
        }
    private:
        vector<string> top;
};

int main() {
    auto t  = vector<string>{};
    t.push_back("salt");
    auto a = Bagel{t};
    cout << t.size() << endl;
    cout << a.getval() << endl;
    t.push_back("second");

    auto b = Bagel{t};
    cout << t.size() << endl;
    // cout << a.getval() << endl;
    t.push_back("third");
    cout << t.size() << endl;
    vector<string> s1{"a","b","c"};
    vector<string> s2 = move(s1);
    cout << s2.size() << " " << s1.size() << endl;
    s1.push_back("d");
    cout << s2.size() << " " << s1.size() << endl;
    return 0;
using namespace std;
int main() {
    int a = 1;
    int & b = a;
    int c = 2;
    b = c;
    b = 4;
    cout << b << c << endl;
    abort();
    return 0;

}