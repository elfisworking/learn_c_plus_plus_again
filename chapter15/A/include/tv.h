#ifndef TV_H_
#define TV_H
class TV {
    public:
        int getNum() {return num;}
        void setNum(int _num) {num = _num;}
        int getChannel() {return channel;}
        void setChannel(int _channel) {channel = _channel;}
        friend class Remote;
    private:
        int num;
        int channel;  
};

class Remote {
    public: 
        int getNum(TV & tv) {return tv.channel;}
        int getChannel(TV & tv) {return tv.num;}
};
#endif