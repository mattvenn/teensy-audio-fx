#ifndef Button_H
#define Button_H

#define LONG_HOLD 500

class Button {

    public:
        Button(int b_p); //, int erase_p, int set_one_p, int tap_tempo_p);
        void update();
        bool pressed();
        bool was_pressed();
        bool long_hold();
        /*
        bool get_write();
        bool get_erase();
        bool get_set_one();
        bool get_tap_tempo();
        */
    
    private:
        int _b_p;
        int _hold_time;
        unsigned long _start_hold;
        bool _b;
        bool _long_hold = false;
        bool _was_pressed = false;
    /*
        bool _write;
        bool _erase;
        bool _tap_tempo;
        bool _set_one;

        int _write_p;
        int _erase_p;
        int _tap_tempo_p;
        int _set_one_p;
        */
};

#endif
