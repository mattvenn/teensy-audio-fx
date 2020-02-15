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

void BarTimer::inc_sync_mode() {
    if(_sync_mode == TAP) {
        _sync_mode = SYNC;
        //Serial.println("sync = SYNC");
    }
    else {
        _sync_mode = TAP;
        //Serial.println("sync = TAP");
    }
}

int BarTimer::get_led() {
    if(_sync_mode == SYNC)
        return _sync_led ? MAX_LED : 0;
    else
        return millis() - _last_tap > 100 ? MAX_LED : 0;
}

void BarTimer::sync_tempo() {
    if(_sync_mode != SYNC)
        return;

    if(millis() - _last_tap > TAP_TIMEOUT) {
        _last_tap = millis(); 
    }
    else {
        _sync_led = !_sync_led;
        int sync_time = millis() - _last_tap; 
        _last_tap = millis();
//        Serial.println(sync_time);
//        Serial.println(30000 / sync_time);
        set_bpm(30000 / sync_time);

        // force automation sequence to keep in line with the sync
        _set_to((MAX_STEPS/SYNC_STEPS) * _sync_beat);
        _sync_beat ++;
        if(_sync_beat >= SYNC_STEPS)
            _sync_beat = 0;
    }
}

void BarTimer::tap_tempo() {
    if(_sync_mode != TAP)
        return;

    // don't rely on counter until _tap_count == NUM_TAPS
    // if it's been a long time since a tap, set _tap_count to 0
    if(millis() - _last_tap > TAP_TIMEOUT) {
        _tap_count = 0;
        _last_tap = millis(); 
    }
    // otherwise, keep a track of the tap times in a circular buffer
    else {
        // rotate buffer
        for(int i = NUM_TAPS-1; i > 0; i --)
            _taps[i] = _taps[i-1];

        _taps[0] = millis() - _last_tap;
        _last_tap = millis();

        // increment _tap_count but don't let it rollover
        if(_tap_count < NUM_TAPS)
            _tap_count ++;
    }

    // the taps should be stable now, so use them to set the bpm
    if(_tap_count == NUM_TAPS) {
        int avg_tap = 0;
        for(int i = 0; i < NUM_TAPS; i ++)
            avg_tap += _taps[i];
        //Serial.println(avg_tap/NUM_TAPS);
//        Serial.println(60000 / (avg_tap/NUM_TAPS));
        set_bpm(60000 / (avg_tap/NUM_TAPS));
    }
}

void BarTimer::set_to_one() {
    _sync_beat = 0;
    _set_to(0);
}

void BarTimer::_set_to(int step) {
    if(step > MAX_STEPS)
        step = 0;
    _step = step;
    _next_step_millis = millis() + _step_millis;
}

void BarTimer::update() {

    if(millis() >= _next_step_millis) {
        _step ++;
        // fractional count to handle non integer step millis
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
