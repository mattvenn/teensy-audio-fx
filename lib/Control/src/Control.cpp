#include <Control.h>

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <stdio.h>
#endif

void Control::set_val(int val, int step) {
    _val[step] = val;
}

void Control::set_val(int val) {
    for(int s = 0; s < MAX_STEPS; s ++)
        _val[s] = val;
}

float Control::get_val(int step) {
    return float(_val[step]) / MAX_POT;
}

int Control::get_led_val(int step) {
    return _val[step] / (MAX_POT / MAX_LED);
}
