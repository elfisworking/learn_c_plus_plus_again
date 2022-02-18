#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Report {
    private:
        string str;
    public:
        Report(const string s) : str(s) {cout << "obj created!" << endl;}
        ~Report() {cout << "obj deleted" << endl;}
        void comment() const {cout << str << endl;}
};
int main() {
    {
        auto_ptr<Report> ps(new Report("using auto_ptr"));
        ps->comment();
    }
    {
        shared_ptr<Report> ps(new Report("using shared ptr"));
        ps->comment();
    }
    {
        unique_ptr<Report> ps(new Report("using unique ptr"));
        ps->comment();
    }
    find()
    return 0;
}