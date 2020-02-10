#ifndef Control_H
#define Control_H

#define MAX_POT 1024
#define MAX_LED 1024
#define MAX_STEPS 512

//#define DEBUG

class Control {

    public:
        Control() {};
        void set_val(int val, int step, bool changed, bool write, bool erase);
        float get_val(int step);
        int get_led_val(int step);
    
    private:
        int _val[MAX_STEPS] = {0};
        bool _writing = false;
#ifdef DEBUG
        char _buf [80];
#endif
};

#endif
