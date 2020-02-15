#ifndef BarTimer_H
#define BarTimer_H

#define DEFAULT_BPM 120
#define NUM_TAPS 4
#define TAP_TIMEOUT 2000

class BarTimer {

    public:
        BarTimer() {};
        void update(bool set_to_one, bool tap_tempo);
        void set_bpm(int bpm);
        void set_sync(bool sync);
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
        bool _sync = false;
        int _taps[NUM_TAPS] = {0};
        int _tap_count = 0;
        unsigned long _last_tap = 0;
        int _step_millis;
        float _step_millis_fraction;
        float _next_step_fraction;
        unsigned long _next_step_millis;
#ifndef ARDUINO
        int _millis;
#endif
};

#endif
