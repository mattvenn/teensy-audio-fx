#include <BarTimer.h>
#include <Control.h> // for MAX_STEPS

#ifdef ARDUINO
#include <Arduino.h>
#define MILLIS = millis()
#else
#include <stdio.h>
int BarTimer::millis() {
    return _millis;
}
void BarTimer::set_millis(int millis) {
    _millis = millis;
}
int BarTimer::get_next_step_millis() {
    return _next_step_millis;
}
#endif

float BarTimer::get_step_millis() {
    return _step_millis;
}

bool BarTimer::bar_led(int bar) {
    return bar == _step / (MAX_STEPS / 4);
}

void BarTimer::set_sync(bool sync) {
    _sync = sync;
}

void BarTimer::update(bool set_to_one, bool tap_tempo) {
    if(tap_tempo && !_sync) {
        Serial.println("tap");

        if(millis() - _last_tap > TAP_TIMEOUT) {
            _tap_count = 0;
            _last_tap = millis(); 
        }
        else {
            _taps[_tap_count++] = millis() - _last_tap;
            _last_tap = millis();
        }

        if(_tap_count==NUM_TAPS) {
            _tap_count = 0;
            int avg_tap = 0;
            for(int i = 0; i < NUM_TAPS; i ++)
                avg_tap += _taps[i];
            //Serial.println(avg_tap/NUM_TAPS);
            Serial.println(60000 / (avg_tap/NUM_TAPS));
            set_bpm(60000 / (avg_tap/NUM_TAPS));
        }
    }

    if(set_to_one) {
        _step = 0;
        _next_step_millis = millis() + _step_millis;
    }
    if(millis() >= _next_step_millis) {
        _step ++;
        _next_step_fraction += _step_millis_fraction;

        if(_next_step_fraction >= 1) {
            _next_step_millis += 1;
            _next_step_fraction -= 1;
        }

        _next_step_millis += _step_millis;
        if(_step == MAX_STEPS)
            _step = 0;
    }
}

void BarTimer::set_bpm(int bpm) {
    _bpm = bpm;
    _step_millis = (60000.0 * 16.0 / MAX_STEPS) / _bpm;
    _step_millis_fraction = (60000.0 * 16.0 / MAX_STEPS) / _bpm - _step_millis;
}

int BarTimer::get_step() {
    return _step;
}
