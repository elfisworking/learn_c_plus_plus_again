#ifndef TVF_H_
#define TVF_H_
class TV; // forward declaration
class Remote {
    public:
        int getNum(TV & tv);
};

class TV {
    private:
        int num;
    public:
        void setNum(int _num) { num = _num; }
        friend int Remote::getNum(TV & tv);
};

// inline int Remote::getNum(TV & tv) {
//     return tv.num;
// }
#endif