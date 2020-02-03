#ifndef Control_H
#define Control_H

#define MAX_POT 1024
#define MAX_LED 255
#define MAX_STEPS 64

class Control {

    public:
        Control() {};
        void set_val(int val, int step);
        void set_val(int val);
        float get_val(int step);
        int get_led_val(int step);
    
    private:
        int _val[MAX_STEPS] = {0};
};

#endif
