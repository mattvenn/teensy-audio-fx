#ifndef BarTimer_H
#define BarTimer_H

#define DEFAULT_BPM 120

class BarTimer {

    public:
        BarTimer() {};
        void update(bool set_to_one);
        void set_bpm(int bpm);
        int get_step();
        bool bar_led(int bar);
        float get_step_millis();
#ifndef ARDUINO
        int millis();
        void set_millis(int millis);
        int get_next_step_millis();
#endif
    
    private:
        int _bpm = DEFAULT_BPM;
        int _step = 0;
        int _step_millis;
        float _step_millis_fraction;
        float _next_step_fraction;
        unsigned long _next_step_millis;
#ifndef ARDUINO
        int _millis;
#endif
};

#endif
