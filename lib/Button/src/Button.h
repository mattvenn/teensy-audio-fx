#ifndef Button_H
#define Button_H

class Button {

    public:
        Button(int b_p); //, int erase_p, int set_one_p, int tap_tempo_p);
        void update();
        bool pressed();
        /*
        bool get_write();
        bool get_erase();
        bool get_set_one();
        bool get_tap_tempo();
        */
    
    private:
        int _b_p;
        bool _b;
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
