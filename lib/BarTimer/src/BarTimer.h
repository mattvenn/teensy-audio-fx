#ifndef BarTimer_H
#define BarTimer_H

#define DEFAULT_BPM 120
#define NUM_TAPS 4
#define TAP_TIMEOUT 1000
#define SYNC_STEPS 32

enum SyncMode {
    TAP,
    SYNC,
};

class BarTimer {

    public:
        BarTimer() {};
        void update();
        void tap_tempo();
        void sync_tempo();
        void inc_sync_mode();
        void set_bpm(int bpm);
        void set_to_one();
        int get_step();
        int get_led();
        bool bar_led(int bar);
        float get_step_millis();
#ifndef ARDUINO
        int millis();
        void set_millis(int millis);
        int get_next_step_millis();
#endif
    
    private:
        void _set_to(int step);
        int _sync_beat = 0;
        int _bpm = DEFAULT_BPM;
        int _step = 0;
        int _taps[NUM_TAPS] = {0};
        int _tap_count = 0;
        bool _sync_mode = TAP;
        bool _sync_led = false;
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
