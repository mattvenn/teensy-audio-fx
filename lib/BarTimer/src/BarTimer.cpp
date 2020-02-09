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

bool BarTimer::bar_led(int bar) {
    return bar == _step / (MAX_STEPS / 4);
}

void BarTimer::update(bool set_to_one) {
    if(set_to_one) {
        _step = 0;
        _next_step_millis = millis() + _step_millis;
    }
    if(millis() >= _next_step_millis) {
        _step ++;
        _next_step_millis += _step_millis;
        if(_step == MAX_STEPS)
            _step = 0;
    }
}

void BarTimer::set_bpm(int bpm) {
    _bpm = bpm;
    _step_millis = (60000*16/MAX_STEPS)/_bpm;
}

int BarTimer::get_step() {
    return _step;
}
