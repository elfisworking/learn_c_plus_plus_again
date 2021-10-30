#include <iostream>
using namespace std;
template <typename T>
class ManyFriend {
    private:
        T item;
    public:
        ManyFriend(const T & i) : item(i) {}
        template <typename C, typename D> friend void show2(C &, D &);
};

template <typename C, typename D> void show2(C & c, D & d) {
    cout << c.item << " " <<d.item << endl;
}

int main() {
    ManyFriend<int> manyFriend1(10);
    ManyFriend<int> manyFriend2(20);
    ManyFriend<double> manyFriend3(10.5);
    show2(manyFriend1, manyFriend2);
    show2(manyFriend2, manyFriend3);
    return 0;
}